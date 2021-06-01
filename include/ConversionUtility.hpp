#ifndef STACKVM_CONVERSIONUTILITY_HPP
#define STACKVM_CONVERSIONUTILITY_HPP

#include "Specification.hpp"

namespace StackVM
{
    class ConversionUtility
    {
    public:
        static void CastSourceToDestinationType(byte* src, byte* dst, Type srcType, Type dstType);
    };
}

#endif