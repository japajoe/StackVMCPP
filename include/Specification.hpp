#ifndef STACKVM_SPECIFICATION_HPP
#define STACKVM_SPECIFICATION_HPP

#include <cstdint>
#include <string>

namespace StackVM
{
    typedef unsigned char byte;

    enum OpCode : uint8_t
    {
        MOV,
        INC,
        DEC,
        ADD,
        SUB,
        MUL,
        DIV,
        PUSH,
        PUSHI8,
        PUSHU8,
        PUSHF,
        PUSHD,
        PUSHI32,
        PUSHU32,
        PUSHI16,
        PUSHU16,
        PUSHI64,
        PUSHU64,
        POP,
        POPI8,
        POPU8,
        POPF,
        POPD,
        POPI32,
        POPU32,
        POPI16,
        POPU16,
        POPI64,
        POPU64,
        PRINT,
        CMP,
        JMP,
        JE,
        JNE,
        JG,
        JGE,
        JL,
        JLE,
        JZ,
        JNZ,
        NOP,
        HLT,
        NUM_OPCODES
    };

    enum Type : uint8_t
    {
        Int8,
        Int16,
        Int32,
        Int64,
        UInt8,
        UInt16,
        UInt32,
        UInt64,
        Double,
        Single
    };

    enum class OperandType : uint8_t
    {
        Register = 0,
        Variable = 1,
        IntegerLiteral
    };

    enum class OperandTypeOption : uint8_t
    {
        All = 0,     
        RegisterOrVariable = 1
    };

    enum class OperandInfo : uint8_t
    {
        None,
        Optional,
        One,
        Two
    };

    class OpCodeInfo
    {
    public:
        OpCode code;
        OperandInfo operandInfo;
        OperandTypeOption leftTypeOption;
        OperandTypeOption rightTypeOption;

        OpCodeInfo() {}

        OpCodeInfo(OpCode code, OperandInfo operandInfo)
        {
            this->code = code;
            this->operandInfo = operandInfo;
        }

        OpCodeInfo(OpCode code, OperandInfo operandInfo, OperandTypeOption leftTypeOption)
        {
            this->code = code;
            this->operandInfo = operandInfo;
            this->leftTypeOption = leftTypeOption;
        } 

        OpCodeInfo(OpCode code, OperandInfo operandInfo, OperandTypeOption leftTypeOption, OperandTypeOption rightTypeOption)
        {
            this->code = code;
            this->operandInfo = operandInfo;
            this->leftTypeOption = leftTypeOption;
            this->rightTypeOption = rightTypeOption;
        }                
    };    

    enum Register : uint8_t
    {
        EAX,
        EBX,
        ECX,
        EDX,
        EBP,
        ESP,
        EDI,
        EIP,
        ESI,
        RAX,
        RBX,
        RCX,
        RDX        
    };

    static std::string opcodeDictionary[] =
    {
        "MOV",
        "INC",
        "DEC",
        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "PUSH",
        "PUSHI8",
        "PUSHU8",
        "PUSHF",
        "PUSHD",
        "PUSHI32",
        "PUSHU32",
        "PUSHI16",
        "PUSHU16",
        "PUSHI64",
        "PUSHU64",
        "POP",
        "POPI8",
        "POPU8",
        "POPF",
        "POPD",
        "POPI32",
        "POPU32",
        "POPI16",
        "POPU16",
        "POPI64",
        "POPU64",
        "PRINT",
        "CMP",
        "JMP",
        "JE",
        "JNE",
        "JG",
        "JGE",
        "JL",
        "JLE",
        "JZ",
        "JNZ",
        "NOP",
        "HLT"
    };
}

#endif