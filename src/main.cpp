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

void PlayLotto(Stack<byte>* stack);
void GetUpcomingWeather(Stack<byte>* stack);
void SetUpcomingWeather(Stack<byte>* stack);

int main()
{
    CompileProgram();
    return 0;
}

void CompileProgram()
{
    compiler.RegisterFunction("playLotto", PlayLotto);
    compiler.RegisterFunction("getUpcomingWeather", GetUpcomingWeather);
    compiler.RegisterFunction("setUpcomingWeather", SetUpcomingWeather);

    std::string filename = "sampscript.asm";

    if(IO::FileExists(filename))
    {
        std::string source = IO::ReadAllText(filename);

        Assembly assembly;

        if(compiler.Compile(source, assembly)) 
        {
            if(machine.LoadProgram(&assembly))
            {
                bool execute = true;

                while(true)
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

void PlayLotto(Stack<byte>* stack)
{
    std::cout << "PlayLotto" << std::endl;
}

void GetUpcomingWeather(Stack<byte>* stack)
{
    //std::cout << "GetUpComingWeather" << std::endl;
    stack->push_int32(2);
}

void SetUpcomingWeather(Stack<byte>* stack)
{
    //std::cout << "SetUpComingWeather" << std::endl;
}
