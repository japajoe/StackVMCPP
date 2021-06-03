#ifndef STACKVM_INSTRUCTION_HPP
#define STACKVM_INSTRUCTION_HPP

#include "Specification.hpp"
#include <cstring>
#include <string>
#include <iostream>

namespace StackVM
{
    struct Instruction
    {
        OpCode opcode;
        byte lhs[8];
        byte rhs[8];
        OperandType lhsOperandType;
        OperandType rhsOperandType;
        Type lhsDataType;
        Type rhsDataType;
        int numOperands;

        template<typename T>
        T GetLeftValue() const
        {
            T value;
            memcpy(&value, &lhs[0], sizeof(T));
            return value;
        }

        template<typename T>
        T GetRightValue() const
        {
            T value;
            memcpy(&value, &rhs[0], sizeof(T));
            return value;
        }        

        Instruction(OpCode opcode)
        {
            this->opcode = opcode;
            this->numOperands = 0;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::UInt8;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::Int8;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::UInt16;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::Int16;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::UInt32;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::Int32;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::UInt64;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::Int64;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::Single;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->lhsDataType = Type::Double;
            this->numOperands = 1;
        }

        Instruction(OpCode opcode, byte* leftValue, Type lhsDataType, OperandType leftType)
        {
            this->opcode = opcode;

            switch(lhsDataType)
            {
                case Type::Int8:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(char));
                    break;
                }
                case Type::Int16:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(int16_t));
                    break;
                }
                case Type::Int32:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(int32_t));
                    break;
                }
                case Type::Int64:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(int64_t));
                    break;
                }
                case Type::UInt8:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(unsigned char));
                    break;
                }
                case Type::UInt16:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(uint16_t));
                    break;
                }
                case Type::UInt32:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(uint32_t));
                    break;
                }
                case Type::UInt64:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(uint64_t));
                    break;
                }
                case Type::Double:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(double));
                    break;
                }
                case Type::Single:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(float));
                    break;
                }
            }

            this->lhsOperandType = leftType;
            this->lhsDataType = lhsDataType;
            this->numOperands = 1;
        }         

        Instruction(OpCode opcode, byte* leftValue, Type lhsDataType, OperandType leftType, byte* rightValue, Type rhsDataType, OperandType rightType)
        {
            this->opcode = opcode;

            switch(lhsDataType)
            {
                case Type::Int8:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(char));
                    break;
                }
                case Type::Int16:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(int16_t));
                    break;
                }
                case Type::Int32:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(int32_t));
                    break;
                }
                case Type::Int64:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(int64_t));
                    break;
                }
                case Type::UInt8:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(unsigned char));
                    break;
                }
                case Type::UInt16:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(uint16_t));
                    break;
                }
                case Type::UInt32:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(uint32_t));
                    break;
                }
                case Type::UInt64:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(uint64_t));
                    break;
                }
                case Type::Double:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(double));
                    break;
                }
                case Type::Single:
                {
                    memcpy(&lhs[0], &leftValue[0], sizeof(float));
                    break;
                }
            }

            switch(rhsDataType)
            {
                case Type::Int8:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(char));
                    break;
                }
                case Type::Int16:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(int16_t));
                    break;
                }
                case Type::Int32:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(int32_t));
                    break;
                }
                case Type::Int64:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(int64_t));
                    break;
                }
                case Type::UInt8:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(unsigned char));
                    break;
                }
                case Type::UInt16:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(uint16_t));
                    break;
                }
                case Type::UInt32:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(uint32_t));
                    break;
                }
                case Type::UInt64:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(uint64_t));
                    break;
                }
                case Type::Double:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(double));
                    break;
                }
                case Type::Single:
                {
                    memcpy(&rhs[0], &rightValue[0], sizeof(float));
                    break;
                }
            }

            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = lhsDataType;
            this->rhsDataType = rhsDataType;
            this->numOperands = 2;
        }              

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, unsigned char leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(unsigned char));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt8;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, char leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(char));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int8;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint16_t leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint16_t));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt16;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int16_t leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int16_t));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int16;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint32_t leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint32_t));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt32;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int32_t leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int32_t));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int32;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, uint64_t leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(uint64_t));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::UInt64;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, int64_t leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(int64_t));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Int64;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, float leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(float));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Single;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, unsigned char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(unsigned char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::UInt8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, char rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(char));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::Int8;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, uint16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(uint16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::UInt16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, int16_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(int16_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::Int16;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, uint32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(uint32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::UInt32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, int32_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(int32_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::Int32;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, uint64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(uint64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::UInt64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, int64_t rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(int64_t));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::Int64;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, float rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(float));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::Single;
            this->numOperands = 2;
        }

        Instruction(OpCode opcode, double leftValue, OperandType leftType, double rightValue, OperandType rightType)
        {
            this->opcode = opcode;
            memcpy(&lhs[0], &leftValue, sizeof(double));
            memcpy(&rhs[0], &rightValue, sizeof(double));
            this->lhsOperandType = leftType;
            this->rhsOperandType = rightType;
            this->lhsDataType = Type::Double;
            this->rhsDataType = Type::Double;
            this->numOperands = 2;
        }   

        void Dump()
        {
            std::string lhsType = "LHS ";
            std::string rhsType = "RHS ";
            switch(lhsDataType)
            {
                case Type::Double:
                    lhsType += "Double " + std::to_string(*(double*)lhs);
                    break;
                case Type::Int16:
                    lhsType += "Int16 " + std::to_string(*(int16_t*)lhs);
                    break;
                case Type::Int32:
                    lhsType += "Int32 " + std::to_string(*(int32_t*)lhs);
                    break;
                case Type::Int64:
                    lhsType += "Int64 " + std::to_string(*(int64_t*)lhs);
                    break;       
                case Type::Int8:
                    lhsType += "Int8 " + std::to_string(*(char*)lhs);
                    break;
                case Type::Single:
                    lhsType += "Single " + std::to_string(*(float*)lhs);
                    break;        
                case Type::UInt16:
                    lhsType += "UInt16 " + std::to_string(*(uint16_t*)lhs);
                    break;       
                case Type::UInt32:
                    lhsType += "UInt32 " + std::to_string(*(uint32_t*)lhs);
                    break;        
                case Type::UInt64:
                    lhsType += "UInt64 " + std::to_string(*(uint64_t*)lhs);
                    break;                            
                case Type::UInt8:
                    lhsType += "UInt8 " + std::to_string(*(unsigned char*)lhs);
                    break;                                                                                                                                                                                                                                                                                                                                                         
            }

            switch(rhsDataType)
            {
                case Type::Double:
                    rhsType += "Double " + std::to_string(*(double*)rhs);
                    break;
                case Type::Int16:
                    rhsType += "Int16 " + std::to_string(*(int16_t*)rhs);
                    break;
                case Type::Int32:
                    rhsType += "Int32 " + std::to_string(*(int32_t*)rhs);
                    break;
                case Type::Int64:
                    rhsType += "Int64 " + std::to_string(*(int64_t*)rhs);
                    break;       
                case Type::Int8:
                    rhsType += "Int8 " + std::to_string(*(char*)rhs);
                    break;
                case Type::Single:
                    rhsType += "Single " + std::to_string(*(float*)rhs);
                    break;        
                case Type::UInt16:
                    rhsType += "UInt16 " + std::to_string(*(uint16_t*)rhs);
                    break;       
                case Type::UInt32:
                    rhsType += "UInt32 " + std::to_string(*(uint32_t*)rhs);
                    break;        
                case Type::UInt64:
                    rhsType += "UInt64 " + std::to_string(*(uint64_t*)rhs);
                    break;                            
                case Type::UInt8:
                    rhsType += "UInt8 " + std::to_string(*(unsigned char*)rhs);
                    break;                                                                                                                                                                                                                                                                                                                                                         
            } 

            if(numOperands == 0)
                std::cout << opcodeDictionary[opcode] << std::endl;
            else if(numOperands == 1)
                std::cout << opcodeDictionary[opcode] << "\t" << lhsType << std::endl;
            else
                std::cout << opcodeDictionary[opcode] << "\t" << lhsType << "\t" << rhsType << std::endl;

        }
    };
}

#endif