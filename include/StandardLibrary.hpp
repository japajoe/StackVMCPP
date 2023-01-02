#ifndef STACKVM_STANDARDLIBRARY_HPP
#define STACKVM_STANDARDLIBRARY_HPP

#include "Stack.hpp"

namespace StackVM
{    
    typedef int (*StackVMFunction)(Stack<byte>* stack);
    
    class StandardLibrary
    {
    public:
        static int Print(Stack<byte>* stack);
        static int PrintLine(Stack<byte>* stack);
        static int PrintNum(Stack<byte>* stack);
        static int EndLine(Stack<byte>* stack);
    };
}

#endif
