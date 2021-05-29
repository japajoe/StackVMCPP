#ifndef STACKVM_SPECIFICATION_HPP
#define STACKVM_SPECIFICATION_HPP

#include <cstdint>

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
        HLT
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
        Single,
        Pointer
    };

    enum class OperandType : uint8_t
    {
        Register = 0,
        Variable = 1,
        IntegerLiteral
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
}

#endif