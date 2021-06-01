#include <iostream>
#include <string>
#include "VirtualMachine.hpp"
#include "Compiler.hpp"
#include "IO.hpp"

using namespace StackVM;

Compiler compiler;
VirtualMachine machine;

void CompileProgram();
void RunExampleProgram();

int main()
{
    CompileProgram();
    //RunExampleProgram();
    return 0;
}

void RunExampleProgram()
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

    if(machine.LoadProgram(&assembly))
    {
        bool execute = true;

        while(execute)
        {
            execute = machine.Execute();
        }
    }
}

void CompileProgram()
{
    std::string filename = "demo.asm";

    if(IO::FileExists(filename))
    {
        std::string source = IO::ReadAllText(filename);

        Assembly assembly;

        //Compiler isn't fully implemented yet so output shouldn't be loaded into virtual machine
        if(compiler.Compile(source, assembly)) 
        {
            if(machine.LoadProgram(&assembly))
            {
                bool execute = true;

                while(execute)
                {
                    execute = machine.Execute();
                }
            }    
        }
        else
        {
            std::cout << "Compile error" << std::endl;
        }
    }
    else
    {
        std::cout << "The file " << filename << " does not exist" << std::endl;
    }
}