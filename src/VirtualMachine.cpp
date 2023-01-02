#include "VirtualMachine.hpp"
#include "MathOperation.hpp"
#include "ConversionUtility.hpp"
#include "StandardLibrary.hpp"
#include <cstring>
#include <iostream>
#include <algorithm>

namespace StackVM
{
    bool debugLog = false;

    void Debug(const std::string& message)
    {
        if(debugLog)
        {
            std::cout << message << std::endl;
        }
    }

    VirtualMachine::VirtualMachine()
    {
        registers.reserve(13 * 8);
        registers.resize(13 * 8);
        ResetState();
    }

    bool VirtualMachine::LoadProgram(Assembly* assembly)
    {
        if(assembly == nullptr)
            return false;

        if(assembly->instructions.size() == 0)
            return false;

        if(assembly->instructions.back().opcode != OpCode::HLT)
            return false;

        ResetState();
        this->assembly = assembly;
        currentInstruction = &assembly->instructions[0];
        entryInstruction = &assembly->instructions[0];        
        return true;
    }    

    ExecutionStatus VirtualMachine::Execute()
    {
        if(currentInstruction == nullptr)
            return ExecutionStatus::Error;

        switch(currentInstruction->opcode)
        {
            case OpCode::HLT:
            {
                currentInstruction = nullptr;
                endTime = high_resolution_clock::now();
                auto ms_int = duration_cast<milliseconds>(endTime - startTime);
                elapsedTime = ms_int.count();                 
                std::cout << "Execution finished in " << elapsedTime << " milliseconds" << std::endl;
                return ExecutionStatus::Done;
            }
            case OpCode::NOP:
            {
                IncrementInstructionPointer();
                break;
            }
            case OpCode::MOV:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                if(currentInstruction->lhsOperandType == OperandType::Register)           
                {      
                    Type rhsType = GetRightOperandDataType(currentInstruction);
                    uint16_t rhsSize = GetSizeOfType(rhsType);
                    SetDestinationRegisterDataType(currentInstruction, rhsType);
                    memset(dst, 0, 8); //clears any previous data in register
                    memcpy(dst, src, rhsSize);
                }
                else if(currentInstruction->lhsOperandType == OperandType::Variable)
                {                    
                    Type lhsType = GetLeftOperandDataType(currentInstruction);
                    Type rhsType = GetRightOperandDataType(currentInstruction);
                    uint16_t lhsSize = GetSizeOfType(lhsType);
                    uint16_t rhsSize = GetSizeOfType(rhsType);

                    byte buffer[8];
                    memset(buffer, 0, 8);

                    ConversionUtility::CastSourceToDestinationType(src, buffer, rhsType, lhsType);

                    memcpy(dst, buffer, lhsSize);
                }

                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSH:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                Type type = GetLeftOperandDataType(currentInstruction);
                if(!stack.push(src, type))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHI8:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::Int8))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHU8:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::UInt8))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }            
            case OpCode::PUSHF:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::Single))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHD:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::Double))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }                  
            case OpCode::PUSHI32:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::Int32))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHU32:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::UInt32))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }            
            case OpCode::PUSHI16:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::Int16))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }    
            case OpCode::PUSHU16:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::UInt16))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }                          
            case OpCode::PUSHI64:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::Int64))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHU64:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                if(!stack.push(src, Type::UInt64))
                    return ExecutionStatus::StackOverflow;
                IncrementInstructionPointer();
                break;
            }                                    
            case OpCode::POP:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    byte* src;

                    if(!stack.pop_bytes(src))
                        return ExecutionStatus::StackUnderflow;
                    // byte *src = stack.pop_bytes();
                    memcpy(dst, src, 8);
                }
                else
                {
                    byte* src;

                    if(!stack.pop_bytes(src))
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI8:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    char src;
                    if(!stack.pop_char(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(char));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int8);
                    }
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }                
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU8:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    unsigned char src;
                    if(!stack.pop_uchar(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(unsigned char));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt8);
                    }
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPF:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    float src;
                    if(!stack.pop_float(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(float));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Single);
                    }                    
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPD:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    double src;
                    if(!stack.pop_double(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(double));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Double);
                    }                    
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI32:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t src;
                    if(!stack.pop_int32(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(int32_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int32);
                    }                    
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU32:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint32_t src;
                    if(!stack.pop_uint32(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(uint32_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt32);
                    }                    
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI16:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int16_t src;
                    if(!stack.pop_int16(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(int16_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int16);
                    }                      
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }                 
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU16:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint16_t src;
                    if(!stack.pop_uint16(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(uint16_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt16);
                    }                                          
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI64:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int64_t src;
                    if(!stack.pop_int64(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(int64_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int64);
                    }
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }                   
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU64:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t src;
                    if(!stack.pop_uint64(src))
                        return ExecutionStatus::StackUnderflow;
                    memcpy(dst, &src, sizeof(uint64_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt64);
                    }
                }
                else
                {
                    if(!stack.pop())
                        return ExecutionStatus::StackUnderflow;
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::INC:
            {
                uint16_t value = 1;
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = (byte*)&value;

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = Type::UInt16;

                MathOperation::Add(dst, src, typeLeft, typeRight);

                IncrementInstructionPointer();
                break;
            }
            case OpCode::DEC:
            {
                uint16_t value = 1;
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = (byte*)&value;

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = Type::UInt16;

                MathOperation::Subtract(dst, src, typeLeft, typeRight);
                IncrementInstructionPointer();
                break;
            }
            case OpCode::ADD:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);

                MathOperation::Add(dst, src, typeLeft, typeRight);
                
                IncrementInstructionPointer();
                break;
            }
            case OpCode::SUB:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);

                MathOperation::Subtract(dst, src, typeLeft, typeRight);
                
                IncrementInstructionPointer();
                break;
            }
            case OpCode::MUL:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);                

                MathOperation::Multiply(dst, src, typeLeft, typeRight);

                IncrementInstructionPointer();
                break;
            }
            case OpCode::DIV:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);                

                MathOperation::Divide(dst, src, typeLeft, typeRight);

                IncrementInstructionPointer();
                break;
            }
            case OpCode::CMP:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);

                MathOperation::Compare(dst, src, typeLeft, typeRight);

                IncrementInstructionPointer();
                break;
            }
            case OpCode::CALL:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);

                if(currentInstruction->lhsOperandType == OperandType::IntegerLiteralLabel)
                {
                    //Todo: store return address somewhere else instead of the stack
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    uint64_t ip = (currentInstruction - entryInstruction) + 1;
                    stack.push_uint64(ip);
                    SetInstructionPointer(offset);
                }
                else if(currentInstruction->lhsOperandType == OperandType::IntegerLiteralExtern)
                {
                    uint64_t address;
                    memcpy(&address, dst, sizeof(uint64_t));
                    StackVMFunction func = reinterpret_cast<StackVMFunction>(address);
                    int result = func(&stack);

                    if(result >= 0)
                        IncrementInstructionPointer();
                    else
                        return ExecutionStatus::Error;
                }

                break;
            }
            case OpCode::CALLF:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                uint64_t address;
                memcpy(&address, dst, sizeof(uint64_t));

                StackVMFunction func = reinterpret_cast<StackVMFunction>(address);
                func(&stack);

                IncrementInstructionPointer();
                break;
            }
            case OpCode::RET:
            {
                //Todo: obtain return address from somewhere else instead of the stack
                uint64_t ip;
                if(!stack.pop_uint64(ip))
                    return ExecutionStatus::StackUnderflow;
                SetInstructionPointer(ip);
                break;
            }
            case OpCode::JMP:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                uint64_t offset;
                memcpy(&offset, dst, sizeof(uint64_t));                
                SetInstructionPointer(offset);
                break;
            }
            case OpCode::JE:
            {
                if(MathOperation::GetCompareFlag() == 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }
                break;
            }
            case OpCode::JNE:
            {
                if(MathOperation::GetCompareFlag() != 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }                
                break;
            }
            case OpCode::JG:
            {
                if(MathOperation::GetCompareFlag() > 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }                 
                break;
            }
            case OpCode::JGE:
            {
                if(MathOperation::GetCompareFlag() >= 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }                 
                break;
            }
            case OpCode::JL:
            {
                if(MathOperation::GetCompareFlag() < 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }                 
                break;
            }
            case OpCode::JLE:
            {
                if(MathOperation::GetCompareFlag() <= 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }                 
                break;
            }
            case OpCode::JZ:
            {
                if(MathOperation::GetZeroFlag() == 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }                 
                break;
            }
            case OpCode::JNZ:
            {
                if(MathOperation::GetZeroFlag() != 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t offset;
                    memcpy(&offset, dst, sizeof(uint64_t));
                    SetInstructionPointer(offset);                    
                }
                else
                {
                    IncrementInstructionPointer();
                }                 
                break;
            }            
            default:
            {
                IncrementInstructionPointer();
                break;
            }
        }      

        return ExecutionStatus::Ok;   
    }

    void VirtualMachine::Stop()
    {
        currentInstruction = nullptr;
    }

    void VirtualMachine::ResetState()
    {
        currentInstruction = nullptr;
        entryInstruction = nullptr;
        assembly = nullptr;
        memset(&registers[0], 0, 13 * sizeof(byte) * 8);
        
        for(size_t i = 0; i < 13; i++)
            registerDataType[i] = Type::Int64;
        
        stack.clear();
        startTime = high_resolution_clock::now();
    }

    byte* VirtualMachine::GetLeftOperandPointer(Instruction* instruction)
    {
        switch(instruction->lhsOperandType)
        {
            case OperandType::IntegerLiteral:
                return &instruction->lhs[0];
            case OperandType::IntegerLiteralLabel:
                return &instruction->lhs[0];
            case OperandType::IntegerLiteralExtern:
                return &instruction->lhs[0];
            case OperandType::Register:                
                return &registers[0] + (instruction->GetLeftValue<int32_t>() * (sizeof(byte) * 8));
            case OperandType::Variable:
                return assembly->GetDataAtIndex(instruction->GetLeftValue<int32_t>());
        }
        
        return nullptr;
    }

    byte* VirtualMachine::GetRightOperandPointer(Instruction* instruction)
    {
        switch(instruction->rhsOperandType)
        {
            case OperandType::IntegerLiteral:
                return &instruction->rhs[0];
            case OperandType::IntegerLiteralLabel:
                return &instruction->rhs[0];
            case OperandType::IntegerLiteralExtern:
                return &instruction->rhs[0];
            case OperandType::Register:
                return &registers[0] + (instruction->GetRightValue<int32_t>() * (sizeof(byte) * 8));
            case OperandType::Variable:
                return assembly->GetDataAtIndex(instruction->GetRightValue<int32_t>());
        }

        return nullptr;
    }

    Type VirtualMachine::GetLeftOperandDataType(Instruction* instruction) const
    {
        if(instruction->lhsOperandType == OperandType::Register)           
        {   
            int32_t index;
            memcpy(&index, &instruction->lhs[0], 4);
            return registerDataType[index];
        }
        else if(instruction->lhsOperandType == OperandType::Variable)
        {
            int32_t index;
            memcpy(&index, &currentInstruction->lhs[0], 4);
            return assembly->types[index];
        }        
        return instruction->lhsDataType;
    }

    Type VirtualMachine::GetRightOperandDataType(Instruction* instruction) const
    {
        if(instruction->rhsOperandType == OperandType::Register)
        {       
            int32_t index;                 
            memcpy(&index, &currentInstruction->rhs[0], 4);
            return registerDataType[index];
        }
        else if(instruction->rhsOperandType == OperandType::Variable)
        {
            int32_t index;
            memcpy(&index, &currentInstruction->rhs[0], 4);
            return assembly->types[index];
        }
        return instruction->rhsDataType;
    }

    uint16_t VirtualMachine::GetSizeOfType(Type type) const
    {
        switch(type)
        {
            case Type::Int8:
                return sizeof(char);
            case Type::Int16:
                return sizeof(int16_t);
            case Type::Int32:
                return sizeof(int32_t);
            case Type::Int64:
                return sizeof(int64_t);
            case Type::UInt8:
                return sizeof(unsigned char);
            case Type::UInt16:
                return sizeof(uint16_t);
            case Type::UInt32:
                return sizeof(uint32_t);
            case Type::UInt64:
                return sizeof(uint64_t);
            case Type::Double:
                return sizeof(double);
            case Type::Single:
                return sizeof(float);
        }

        return 0;
    }
    
    int32_t VirtualMachine::GetDestinationRegisterIndex(Instruction* instruction) const
    {
        int32_t index = 0;
        memcpy(&index, &instruction->lhs[0], 4);
        return index;
    }

    void VirtualMachine::SetDestinationRegisterDataType(Instruction* instruction, Type type)
    {
        int32_t index = GetDestinationRegisterIndex(instruction);
        registerDataType[index] = type;
    }

    void VirtualMachine::IncrementInstructionPointer()
    {
        currentInstruction += 1;
    }

    void VirtualMachine::IncrementInstructionPointer(uint64_t offset)
    {
        currentInstruction += offset;   
    }    

    void VirtualMachine::SetInstructionPointer(uint64_t offset)
    {
        currentInstruction = (entryInstruction + offset);
        //currentInstruction = reinterpret_cast<Instruction*>(offset);
    }   

    void VirtualMachine::LogMessage(const std::string& message)
    {
        std::cout << message;
    }
}
