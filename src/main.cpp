#include <iostream>
#include "Stack.hpp"
#include "Specification.hpp"
#include "Assembly.hpp"
#include "Instruction.hpp"
#include "VirtualMachine.hpp"

using namespace StackVM;

int main()
{
    Assembly assembly;
    assembly.instructions.push_back(Instruction(OpCode::MOV, EAX, OperandType::Register, 0, OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::MOV, EBX, OperandType::Register, 10, OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::INC, EAX, OperandType::Register));
    assembly.instructions.push_back(Instruction(OpCode::PUSHI8, '\n', OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::PUSHI8, 'o', OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::PUSHI8, 'l', OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::PUSHI8, 'l', OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::PUSHI8, 'e', OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::PUSHI8, 'h', OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::PUSHI32, 6, OperandType::IntegerLiteral));
    assembly.instructions.push_back(Instruction(OpCode::PRINT));
    assembly.instructions.push_back(Instruction(OpCode::CMP, EAX, OperandType::Register, EBX, OperandType::Register));
    assembly.instructions.push_back(Instruction(OpCode::JNE, 2, OperandType::IntegerLiteral));    
    assembly.instructions.push_back(Instruction(OpCode::HLT));

    VirtualMachine machine;

    if(machine.LoadProgram(&assembly))
    {
        bool execute = true;

        while(execute)
        {
            execute = machine.Execute();
        }
    }

    return 0;
}