#include <iostream>
#include <string>
#include <memory>
#include "VirtualMachine.hpp"
#include "Compiler.hpp"
#include "IO.hpp"
#include <math.h>

using namespace StackVM;

std::unique_ptr<Compiler> compiler;
std::unique_ptr<VirtualMachine> machine;

void CompileProgram();

int main()
{
    compiler = std::make_unique<Compiler>();
    machine = std::make_unique<VirtualMachine>();
    CompileProgram();
    return 0;
}

void CompileProgram()
{
    std::string filename = "helloworld.asm";

    if(IO::FileExists(filename))
    {
        std::string source = IO::ReadAllText(filename);

        Assembly assembly;

        if(compiler->Compile(source, assembly)) 
        {
            if(machine->LoadProgram(&assembly))
            {
                bool execute = true;

                while(execute)
                {
                    execute = machine->Execute();
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
