#include "StandardLibrary.hpp"
#include <iostream>
#include <math.h>

namespace StackVM
{
    void StandardLibrary::Abs(Stack<byte>* stack)
    {
        float value = stack->pop_float();
        float result = value >= 0 ? value : (-1.0f * value);
        stack->push_float(result);
    }

    //float value, float min, float max
    void StandardLibrary::Clamp(Stack<byte>* stack)
    {
        float max = stack->pop_float();
        float min = stack->pop_float();
        float result = stack->pop_float();

        if(result > max)
            result = max;
        if(result < min)
            result = min;        
    
        stack->push_float(result);
    }

    void StandardLibrary::Cos(Stack<byte>* stack)
    {
        float value = stack->pop_float();
        float result = cos(value);
        stack->push_float(result);
    }

    //float a, float b, float t
    void StandardLibrary::Lerp(Stack<byte>* stack)
    {
        float t = stack->pop_float();
        float b = stack->pop_float();
        float a = stack->pop_float();

        if(t > 1.0f)
            t = 1.0f;
        if(t < 0.0f)
            t = 0.0f;

        float result = a + ((b-a) * t);

        stack->push_float(result);
    }

    //float x, float y
    void StandardLibrary::Pow(Stack<byte>* stack)
    {
        float y = stack->pop_float();
        float x = stack->pop_float();
        float result = pow(x, y);
        stack->push_float(result);
    }

    void StandardLibrary::Sin(Stack<byte>* stack)
    {
        float value = stack->pop_float();
        float result = sin(value);
        stack->push_float(result);

        std::cout << "Called StandardLibrary::Sin with input value " << value << " and return result " << result << std::endl;
    }

    void StandardLibrary::Sign(Stack<byte>* stack)
    {
        float value = stack->pop_float();
        float result = 0;

        if(value == 0)
            result = 0;
        else if(value < 0)
            result = -1;
        else
            result = 1;
        stack->push_float(result);
    }

    void StandardLibrary::Sqrt(Stack<byte>* stack)  
    {
        float value = stack->pop_float();
        float result = sqrt(value);
        stack->push_float(result);
    }
}