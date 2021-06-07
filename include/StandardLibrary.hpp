#ifndef STACKVM_STANDARDLIBRARY_HPP
#define STACKVM_STANDARDLIBRARY_HPP

#include "Stack.hpp"

namespace StackVM
{
    typedef void (*StandardLibraryFunction)(Stack<byte>* stack);
    
    class StandardLibrary
    {
    public:
        static void Abs(Stack<byte>* stack);
        static void Clamp(Stack<byte>* stack);
        static void Cos(Stack<byte>* stack);
        static void Lerp(Stack<byte>* stack);
        static void Pow(Stack<byte>* stack);
        static void Sin(Stack<byte>* stack);
        static void Sign(Stack<byte>* stack);
        static void Sqrt(Stack<byte>* stack);
    };
}

#endif