#ifndef STACKVM_CONVERSIONUTILITY_HPP
#define STACKVM_CONVERSIONUTILITY_HPP

#include "Specification.hpp"
#include <string>

namespace StackVM
{
    class ConversionUtility
    {
    public:
        static void CastSourceToDestinationType(byte* src, byte* dst, Type srcType, Type dstType);
        static std::string GetStringFromType(Type type);
    };
}

#endif