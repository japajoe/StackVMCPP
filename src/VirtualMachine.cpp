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
        program = &assembly->instructions[0];
        currentInstruction = &assembly->instructions[0];
        entryInstruction = &assembly->instructions[0];
        startTime = high_resolution_clock::now();
        return true;
    }

    bool VirtualMachine::Execute()
    {
        if(currentInstruction == nullptr)
            return false;

        uint32_t instructionIndex = (currentInstruction - entryInstruction);
        std::string currentIndex = std::to_string(instructionIndex);

        switch(currentInstruction->opcode)
        {
            case OpCode::HLT:
            {
                Debug("HLT " + currentIndex);
                currentInstruction = nullptr;
                std::cout << "Elapsed time " << elapsedTime << std::endl;
                return false;
            }
            case OpCode::NOP:
            {
                Debug("NOP " + currentIndex);
                ++currentInstruction;
                break;
            }
            case OpCode::MOV:
            {
                Debug("MOV " + currentIndex);
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                if(currentInstruction->lhsOperandType == OperandType::Register)           
                {      
                    Type rhsType = GetRightOperandDataType(currentInstruction);
                    SetDestinationRegisterDataType(currentInstruction, rhsType);
                    memcpy(dst, src, 8);
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

                ++currentInstruction;
                break;
            }
            case OpCode::PUSH:
            {
                Debug("PUSH " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                Type type = GetLeftOperandDataType(currentInstruction);
                stack.push(src, type);
                ++currentInstruction;                
                break;
            }
            case OpCode::PUSHI8:
            {
                Debug("PUSHI8 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<char>(src);
                ++currentInstruction;
                break;
            }
            case OpCode::PUSHU8:
            {
                Debug("PUSHU8 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<unsigned char>(src);
                ++currentInstruction;
                break;
            }            
            case OpCode::PUSHF:
            {
                Debug("PUSHF " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<float>(src);
                ++currentInstruction;
                break;
            }
            case OpCode::PUSHD:
            {
                Debug("PUSHD " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<double>(src);
                ++currentInstruction;
                break;
            }                  
            case OpCode::PUSHI32:
            {
                Debug("PUSHI32 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<int32_t>(src);
                ++currentInstruction;
                break;
            }
            case OpCode::PUSHU32:
            {
                Debug("PUSHU32 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<uint32_t>(src);
                ++currentInstruction;
                break;
            }            
            case OpCode::PUSHI16:
            {
                Debug("PUSHI16 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<int16_t>(src);
                ++currentInstruction;
                break;
            }    
            case OpCode::PUSHU16:
            {
                Debug("PUSHU16 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<uint16_t>(src);
                ++currentInstruction;
                break;
            }                          
            case OpCode::PUSHI64:
            {
                Debug("PUSHI64 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<int64_t>(src);
                ++currentInstruction;
                break;
            }
            case OpCode::PUSHU64:
            {
                Debug("PUSHU64 " + currentIndex);
                byte* src = GetLeftOperandPointer(currentInstruction);
                stack.push_from_type<uint64_t>(src);
                ++currentInstruction;
                break;
            }                                    
            case OpCode::POP:
            {
                Debug("POP " + currentIndex);
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
                ++currentInstruction;
                break;
            }
            case OpCode::POPI8:
            {
                Debug("POPI8 " + currentIndex);
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
                ++currentInstruction;
                break;
            }
            case OpCode::POPU8:
            {
                Debug("POPU8 " + currentIndex);
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
                ++currentInstruction;
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
                ++currentInstruction;
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
                ++currentInstruction;
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
                ++currentInstruction;
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
                ++currentInstruction;
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
                ++currentInstruction;
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
                ++currentInstruction;
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
                ++currentInstruction;
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
                ++currentInstruction;
                break;
            }            
            case OpCode::PRINT:
            {
                Debug("PRINT " + currentIndex);

                //int8_t numArgs = stack.pop_char();
                int32_t numArgs = stack.pop_int32();

                char characters[numArgs + 1];
                characters[numArgs] = '\0';
                
                for(size_t i = 0; i < numArgs; i++)
                {     
                    char character = stack.pop_char();
                    characters[i] = character;
                }

                printf(characters);
                ++currentInstruction;
                break;
            }
            case OpCode::INC:
            {
                byte value = 1;
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = &value;

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = Type::UInt8;

                MathOperation::Add(currentInstruction, dst, src, typeLeft, typeRight, &registers[0], &assembly->data[0]);

                ++currentInstruction;
                break;
            }
            case OpCode::DEC:
            {
                byte value = 1;
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = &value;

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = Type::UInt8;

                MathOperation::Subtract(currentInstruction, dst, src, typeLeft, typeRight, &registers[0], &assembly->data[0]);
                ++currentInstruction;
                break;
            }
            case OpCode::ADD:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);

                MathOperation::Add(currentInstruction, dst, src, typeLeft, typeRight, &registers[0], &assembly->data[0]);
                
                ++currentInstruction;
                break;
            }
            case OpCode::SUB:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);

                MathOperation::Subtract(currentInstruction, dst, src, typeLeft, typeRight, &registers[0], &assembly->data[0]);
                
                ++currentInstruction;
                break;
            }
            case OpCode::MUL:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);                

                MathOperation::Multiply(currentInstruction, dst, src, typeLeft, typeRight, &registers[0], &assembly->data[0]);

                ++currentInstruction;
                break;
            }
            case OpCode::DIV:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);                

                MathOperation::Divide(currentInstruction, dst, src, typeLeft, typeRight, &registers[0], &assembly->data[0]);

                ++currentInstruction;
                break;
            }
            case OpCode::CMP:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                byte* src = GetRightOperandPointer(currentInstruction);

                Type typeLeft = GetLeftOperandDataType(currentInstruction);
                Type typeRight = GetRightOperandDataType(currentInstruction);

                MathOperation::Compare(currentInstruction, dst, src, typeLeft, typeRight, &registers[0], &assembly->data[0]);

                ++currentInstruction;
                break;
            }
            case OpCode::JMP:
            {
                byte* dst = GetLeftOperandPointer(currentInstruction);
                int32_t offset;
                memcpy(&offset, dst, sizeof(int32_t));
                currentInstruction = (entryInstruction + offset);

                break;
            }
            case OpCode::JE:
            {
                if(MathOperation::GetCompareFlag() == 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }
                break;
            }
            case OpCode::JNE:
            {
                if(MathOperation::GetCompareFlag() != 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }                
                break;
            }
            case OpCode::JG:
            {
                if(MathOperation::GetCompareFlag() > 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }                 
                break;
            }
            case OpCode::JGE:
            {
                if(MathOperation::GetCompareFlag() >= 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }                 
                break;
            }
            case OpCode::JL:
            {
                if(MathOperation::GetCompareFlag() < 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }                 
                break;
            }
            case OpCode::JLE:
            {
                if(MathOperation::GetCompareFlag() <= 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }                 
                break;
            }
            case OpCode::JZ:
            {
                if(MathOperation::GetZeroFlag() == 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }                 
                break;
            }
            case OpCode::JNZ:
            {
                if(MathOperation::GetZeroFlag() != 0)
                {
                    byte* dst = GetLeftOperandPointer(currentInstruction);
                    int32_t offset;
                    memcpy(&offset, dst, sizeof(int32_t));
                    currentInstruction = (entryInstruction + offset);                    
                }
                else
                {
                    ++currentInstruction;
                }                 
                break;
            }            
            default:
            {
                ++currentInstruction;
                break;
            }
        }

        endTime = high_resolution_clock::now();
        auto ms_int = duration_cast<milliseconds>(endTime - startTime);
        elapsedTime = ms_int.count();       

        return true;   
    }

    void VirtualMachine::Stop()
    {
        currentInstruction = nullptr;
    }

    void VirtualMachine::ResetState()
    {
        program = nullptr;
        currentInstruction = nullptr;
        entryInstruction = nullptr;
        memset(&registers[0], 0, 13 * sizeof(byte) * 8);
        zeroFlag = 0;
        compareFlag = 0;
        elapsedTime = 0;
        stack.clear();
    }

    byte* VirtualMachine::GetLeftOperandPointer(Instruction* instruction)
    {
        byte* ptr = nullptr;

        switch(instruction->lhsOperandType)
        {
            case OperandType::IntegerLiteral:
                ptr = &instruction->lhs[0];
                break;
            case OperandType::Register:                
                ptr = &registers[0] + (instruction->GetLeftValue<int32_t>() * (sizeof(byte) * 8));
                break;
            case OperandType::Variable:
                ptr = assembly->GetDataAtIndex(instruction->GetLeftValue<int32_t>());
                break;
        }
        
        return ptr;
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
                ptr = assembly->GetDataAtIndex(instruction->GetLeftValue<int32_t>());
                break;
        }
        
        return ptr;
    }

    Type VirtualMachine::GetRegisterDataType(Instruction* instruction) const
    {
        return instruction->rhsDataType;
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

    int32_t VirtualMachine::GetSourceRegisterIndex(Instruction* instruction) const
    {
        int32_t index = 0;
        memcpy(&index, &instruction->rhs[0], 4);
        return index;
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
        memcpy(&index, &instruction->lhs[0], 4);
        registerDataType[index] = type;
    }

    void VirtualMachine::WriteBytesToBuffer(byte* dst, Type dstType, byte* src, Type srcType)
    {
        uint16_t dstSize = GetSizeOfType(dstType);
        uint16_t srcSize = GetSizeOfType(srcType);

        byte buffer[8];
        memset(buffer, 0, 8);        
        memcpy(buffer, src, srcSize);

        
    }

    void VirtualMachine::LogMessage(const std::string& message)
    {
        std::cout << message;
    }
}