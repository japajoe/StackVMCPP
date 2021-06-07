#include "VirtualMachine.hpp"
#include "MathOperation.hpp"
#include "ConversionUtility.hpp"
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

    bool VirtualMachine::Execute()
    {
        if(currentInstruction == nullptr)
            return false;

        switch(currentInstruction->opcode)
        {
            case OpCode::HLT:
            {
                currentInstruction = nullptr;
                endTime = high_resolution_clock::now();
                auto ms_int = duration_cast<milliseconds>(endTime - startTime);
                elapsedTime = ms_int.count();                 
                std::cout << "Elapsed time " << elapsedTime << std::endl;
                return false;
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
                stack.push(src, type);
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHI8:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<char>(src);
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHU8:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<unsigned char>(src);
                IncrementInstructionPointer();
                break;
            }            
            case OpCode::PUSHF:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<float>(src);
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHD:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<double>(src);
                IncrementInstructionPointer();
                break;
            }                  
            case OpCode::PUSHI32:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<int32_t>(src);
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHU32:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<uint32_t>(src);
                IncrementInstructionPointer();
                break;
            }            
            case OpCode::PUSHI16:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<int16_t>(src);
                IncrementInstructionPointer();
                break;
            }    
            case OpCode::PUSHU16:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<uint16_t>(src);
                IncrementInstructionPointer();
                break;
            }                          
            case OpCode::PUSHI64:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<int64_t>(src);
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PUSHU64:
            {
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<uint64_t>(src);
                IncrementInstructionPointer();
                break;
            }                                    
            case OpCode::POP:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    byte* src = stack.pop_bytes();
                    memcpy(dst, src, 8);
                }
                else
                {
                    stack.pop_bytes();
                }
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI8:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    char src = stack.pop_char();
                    memcpy(dst, &src, sizeof(char));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int8);
                    }
                }
                else
                {
                    stack.pop_char();
                }                
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU8:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    unsigned char src = stack.pop_uchar();
                    memcpy(dst, &src, sizeof(unsigned char));
                    
                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt8);
                    }
                }
                else
                {
                    stack.pop_uchar();
                }                 
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPF:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    float src = stack.pop_float();
                    memcpy(dst, &src, sizeof(float));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Single);
                    }                    
                }
                else
                {
                    stack.pop_float();
                }                 
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPD:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    double src = stack.pop_double();
                    memcpy(dst, &src, sizeof(double));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Double);
                    }                    
                }
                else
                {
                    stack.pop_double();
                }                 
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI32:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t src = stack.pop_int32();
                    memcpy(dst, &src, sizeof(int32_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int32);
                    }                    
                }
                else
                {
                    stack.pop_int32();
                }                
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU32:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint32_t src = stack.pop_uint32();
                    memcpy(dst, &src, sizeof(uint32_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt32);
                    }                    
                }
                else
                {
                    stack.pop_uint32();
                }                
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI16:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int16_t src = stack.pop_int16();
                    memcpy(dst, &src, sizeof(int16_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int16);
                    }                      
                }
                else
                {
                    stack.pop_int16();
                }                 
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU16:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint16_t src = stack.pop_uint16();
                    memcpy(dst, &src, sizeof(uint16_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt16);
                    }                                          
                }
                else
                {
                    stack.pop_uint16();
                }                
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPI64:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int64_t src = stack.pop_int64();
                    memcpy(dst, &src, sizeof(int64_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::Int64);
                    }
                }
                else
                {
                    stack.pop_int64();
                }                   
                IncrementInstructionPointer();
                break;
            }
            case OpCode::POPU64:
            {
                if(currentInstruction->numOperands == 1)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    uint64_t src = stack.pop_uint64();
                    memcpy(dst, &src, sizeof(uint64_t));

                    if(currentInstruction->lhsOperandType == OperandType::Register)
                    {        
                        SetDestinationRegisterDataType(currentInstruction, Type::UInt64);
                    }
                }
                else
                {
                    stack.pop_uint64();
                }                
                IncrementInstructionPointer();
                break;
            }            
            case OpCode::PRINT:
            {
                int32_t numArgs = stack.pop_int32();
                char characters[numArgs];
                characters[numArgs] = '\0';
                
                for(size_t i = 0; i < numArgs; i++)
                {
                    characters[i] = stack.pop_char();
                }

                std::cout << characters;
                IncrementInstructionPointer();
                break;
            }
            case OpCode::PRINTF:
            {                
                int32_t numberType = stack.pop_int32();
                if(numberType == 0)
                {
                    int32_t val = stack.pop_int32();
                    std::cout << val << '\n';
                }
                else
                {
                    float val = stack.pop_float();
                    std::cout << val << '\n';
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
                uint64_t offset;
                memcpy(&offset, dst, sizeof(uint64_t));

                uint64_t ip = (currentInstruction - entryInstruction) + 1;
                stack.push_uint64(ip);

                SetInstructionPointer(offset);
                break;
            }
            case OpCode::RET:
            {
                uint64_t ip = stack.pop_uint64();
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

        return true;   
    }

    void VirtualMachine::Stop()
    {
        currentInstruction = nullptr;
    }

    void VirtualMachine::ResetState()
    {
        currentInstruction = nullptr;
        entryInstruction = nullptr;
        memset(&registers[0], 0, 13 * sizeof(byte) * 8);
        elapsedTime = 0;
        stack.clear();
        startTime = high_resolution_clock::now();
    }

    byte* VirtualMachine::GetLeftOperandPointer(Instruction* instruction)
    {
        switch(instruction->lhsOperandType)
        {
            case OperandType::IntegerLiteral:
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
        byte* ptr = nullptr;

        switch(instruction->rhsOperandType)
        {
            case OperandType::IntegerLiteral:
                ptr = &instruction->rhs[0];
                break;
            case OperandType::Register:
                ptr = &registers[0] + (instruction->GetRightValue<int32_t>() * (sizeof(byte) * 8));
                break;
            case OperandType::Variable:
                ptr = assembly->GetDataAtIndex(instruction->GetRightValue<int32_t>());
                break;
        }
        
        return ptr;
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
        //currentInstruction = (entryInstruction + offset);
        currentInstruction = reinterpret_cast<Instruction*>(offset);
    }   

    void VirtualMachine::LogMessage(const std::string& message)
    {
        std::cout << message;
    }
}