#include "StandardLibrary.hpp"
#include <iostream>
#include <chrono>
#include <math.h>
#include <stdarg.h>

namespace StackVM
{
    int StandardLibrary::Print(Stack<byte>* stack)
    {
        int32_t numChars;
       
        if(!stack->pop_int32(numChars))
            return -1;

        char characters[numChars];
        characters[numChars] = '\0';
        
        for(size_t i = 0; i < numChars; i++)
        {
            char c;
            if(!stack->pop_char(c))
                return -1;
            characters[i] = c;
        }

        std::cout << characters;    

        return 0; 
    }

    int StandardLibrary::PrintLine(Stack<byte>* stack)
    {
        int32_t numChars;
       
        if(!stack->pop_int32(numChars))
            return -1;

        char characters[numChars];
        characters[numChars] = '\0';
        
        for(size_t i = 0; i < numChars; i++)
        {
            char c;
            if(!stack->pop_char(c))
                return -1;
            characters[i] = c;
        }

        std::cout << characters << '\n';

        return 0;
    }

    int StandardLibrary::PrintNum(Stack<byte>* stack)
    {
        auto type = stack->get_top_type();

        std::string value;

        if(!stack->try_pop_as_string(value))
        {
            return -1;
        }

        std::cout << value;

        return 0;
    }

    int StandardLibrary::EndLine(Stack<byte>* stack)
    {
        std::cout << '\n';

        return 0;
    }
}
