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
        PRINTF,
        CMP,
        CALL,
        CALLF,
        RET,
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
        UInt8 = 0,
        Int8 = 1,
        UInt16 = 2,
        Int16 = 3,
        UInt32 = 4,
        Int32 = 5,
        UInt64 = 6,
        Int64 = 7,
        Single = 8,
        Double = 9        
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
        "PRINTF",
        "CMP",
        "CALL",
        "CALLF",
        "RET",
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