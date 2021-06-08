#include <iostream>
#include <string>
#include "VirtualMachine.hpp"
#include "Compiler.hpp"
#include "IO.hpp"
#include <math.h>

using namespace StackVM;

Compiler compiler;
VirtualMachine machine;

void CompileProgram();
void Tokenize();

int main()
{
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