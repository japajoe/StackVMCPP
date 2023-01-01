#ifndef STACKVM_STANDARDLIBRARY_HPP
#define STACKVM_STANDARDLIBRARY_HPP

#include "Stack.hpp"

namespace StackVM
{    
    typedef void (*StackVMFunction)(Stack<byte>* stack);
    
    class StandardLibrary
    {
    public:
        static void TestFunction(Stack<byte>* stack);
        static void Abs(Stack<byte>* stack);
        static void Clamp(Stack<byte>* stack);
        static void Cos(Stack<byte>* stack);
        static void Lerp(Stack<byte>* stack);
        static void Pow(Stack<byte>* stack);
        static void Sin(Stack<byte>* stack);
        static void Sign(Stack<byte>* stack);
        static void Sqrt(Stack<byte>* stack);
        static void GetTimeStamp(Stack<byte>* stack);
        static void Print(Stack<byte>* stack);
        static void PrintLine(Stack<byte>* stack);
        static void PrintNum(Stack<byte>* stack);
        static void EndLine(Stack<byte>* stack);
    };
}

#endif
