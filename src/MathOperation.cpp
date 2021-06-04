#include "MathOperation.hpp"
#include <iostream>

namespace StackVM
{
	//WARNING: This class contains generated code, so it's not recommend to casually start changing things
	
    int MathOperation::zeroFlag = 0;
    int MathOperation::compareFlag = 0;

    CmpCallbackPtr MathOperation::cmpFunctions[][10] =
    {
        { CompareUInt8UInt8, CompareUInt8Int8, CompareUInt8UInt16, CompareUInt8Int16, CompareUInt8UInt32, CompareUInt8Int32, CompareUInt8UInt64, CompareUInt8Int64, CompareUInt8Single, CompareUInt8Double },
        { CompareInt8UInt8, CompareInt8Int8, CompareInt8UInt16, CompareInt8Int16, CompareInt8UInt32, CompareInt8Int32, CompareInt8UInt64, CompareInt8Int64, CompareInt8Single, CompareInt8Double }, 
        { CompareUInt16UInt8, CompareUInt16Int8, CompareUInt16UInt16, CompareUInt16Int16, CompareUInt16UInt32, CompareUInt16Int32, CompareUInt16UInt64, CompareUInt16Int64, CompareUInt16Single, CompareUInt16Double },
        { CompareInt16UInt8, CompareInt16Int8, CompareInt16UInt16, CompareInt16Int16, CompareInt16UInt32, CompareInt16Int32, CompareInt16UInt64, CompareInt16Int64, CompareInt16Single, CompareInt16Double },
        { CompareUInt32UInt8, CompareUInt32Int8, CompareUInt32UInt16, CompareUInt32Int16, CompareUInt32UInt32, CompareUInt32Int32, CompareUInt32UInt64, CompareUInt32Int64, CompareUInt32Single, CompareUInt32Double },
        { CompareInt32UInt8, CompareInt32Int8, CompareInt32UInt16, CompareInt32Int16, CompareInt32UInt32, CompareInt32Int32, CompareInt32UInt64, CompareInt32Int64, CompareInt32Single, CompareInt32Double },
        { CompareUInt64UInt8, CompareUInt64Int8, CompareUInt64UInt16, CompareUInt64Int16, CompareUInt64UInt32, CompareUInt64Int32, CompareUInt64UInt64, CompareUInt64Int64, CompareUInt64Single, CompareUInt64Double },
        { CompareInt64UInt8, CompareInt64Int8, CompareInt64UInt16, CompareInt64Int16, CompareInt64UInt32, CompareInt64Int32, CompareInt64UInt64, CompareInt64Int64, CompareInt64Single, CompareInt64Double },
        { CompareSingleUInt8, CompareSingleInt8, CompareSingleUInt16, CompareSingleInt16, CompareSingleUInt32, CompareSingleInt32, CompareSingleUInt64, CompareSingleInt64, CompareSingleSingle, CompareSingleDouble },
        { CompareDoubleUInt8, CompareDoubleInt8, CompareDoubleUInt16, CompareDoubleInt16, CompareDoubleUInt32, CompareDoubleInt32, CompareDoubleUInt64, CompareDoubleInt64, CompareDoubleSingle, CompareDoubleDouble }
    };

    AddCallbackPtr MathOperation::addFunctions[][10] =
    {
        { AddUInt8UInt8, AddUInt8Int8, AddUInt8UInt16, AddUInt8Int16, AddUInt8UInt32, AddUInt8Int32, AddUInt8UInt64, AddUInt8Int64, AddUInt8Single, AddUInt8Double }, 
        { AddInt8UInt8, AddInt8Int8, AddInt8UInt16, AddInt8Int16, AddInt8UInt32, AddInt8Int32, AddInt8UInt64, AddInt8Int64, AddInt8Single, AddInt8Double },
        { AddUInt16UInt8, AddUInt16Int8, AddUInt16UInt16, AddUInt16Int16, AddUInt16UInt32, AddUInt16Int32, AddUInt16UInt64, AddUInt16Int64, AddUInt16Single, AddUInt16Double },
        { AddInt16UInt8, AddInt16Int8, AddInt16UInt16, AddInt16Int16, AddInt16UInt32, AddInt16Int32, AddInt16UInt64, AddInt16Int64, AddInt16Single, AddInt16Double },
        { AddUInt32UInt8, AddUInt32Int8, AddUInt32UInt16, AddUInt32Int16, AddUInt32UInt32, AddUInt32Int32, AddUInt32UInt64, AddUInt32Int64, AddUInt32Single, AddUInt32Double },
        { AddInt32UInt8, AddInt32Int8, AddInt32UInt16, AddInt32Int16, AddInt32UInt32, AddInt32Int32, AddInt32UInt64, AddInt32Int64, AddInt32Single, AddInt32Double },
        { AddUInt64UInt8, AddUInt64Int8, AddUInt64UInt16, AddUInt64Int16, AddUInt64UInt32, AddUInt64Int32, AddUInt64UInt64, AddUInt64Int64, AddUInt64Single, AddUInt64Double },
        { AddInt64UInt8, AddInt64Int8, AddInt64UInt16, AddInt64Int16, AddInt64UInt32, AddInt64Int32, AddInt64UInt64, AddInt64Int64, AddInt64Single, AddInt64Double },
        { AddSingleUInt8, AddSingleInt8, AddSingleUInt16, AddSingleInt16, AddSingleUInt32, AddSingleInt32, AddSingleUInt64, AddSingleInt64, AddSingleSingle, AddSingleDouble },
        { AddDoubleUInt8, AddDoubleInt8, AddDoubleUInt16, AddDoubleInt16, AddDoubleUInt32, AddDoubleInt32, AddDoubleUInt64, AddDoubleInt64, AddDoubleSingle, AddDoubleDouble }
    };

    SubCallbackPtr MathOperation::subFunctions[][10] =
    {
        { SubtractUInt8UInt8, SubtractUInt8Int8, SubtractUInt8UInt16, SubtractUInt8Int16, SubtractUInt8UInt32, SubtractUInt8Int32, SubtractUInt8UInt64, SubtractUInt8Int64, SubtractUInt8Single, SubtractUInt8Double }, 
        { SubtractInt8UInt8, SubtractInt8Int8, SubtractInt8UInt16, SubtractInt8Int16, SubtractInt8UInt32, SubtractInt8Int32, SubtractInt8UInt64, SubtractInt8Int64, SubtractInt8Single, SubtractInt8Double },
        { SubtractUInt16UInt8, SubtractUInt16Int8, SubtractUInt16UInt16, SubtractUInt16Int16, SubtractUInt16UInt32, SubtractUInt16Int32, SubtractUInt16UInt64, SubtractUInt16Int64, SubtractUInt16Single, SubtractUInt16Double },
        { SubtractInt16UInt8, SubtractInt16Int8, SubtractInt16UInt16, SubtractInt16Int16, SubtractInt16UInt32, SubtractInt16Int32, SubtractInt16UInt64, SubtractInt16Int64, SubtractInt16Single, SubtractInt16Double },
        { SubtractUInt32UInt8, SubtractUInt32Int8, SubtractUInt32UInt16, SubtractUInt32Int16, SubtractUInt32UInt32, SubtractUInt32Int32, SubtractUInt32UInt64, SubtractUInt32Int64, SubtractUInt32Single, SubtractUInt32Double },
        { SubtractInt32UInt8, SubtractInt32Int8, SubtractInt32UInt16, SubtractInt32Int16, SubtractInt32UInt32, SubtractInt32Int32, SubtractInt32UInt64, SubtractInt32Int64, SubtractInt32Single, SubtractInt32Double },
        { SubtractUInt64UInt8, SubtractUInt64Int8, SubtractUInt64UInt16, SubtractUInt64Int16, SubtractUInt64UInt32, SubtractUInt64Int32, SubtractUInt64UInt64, SubtractUInt64Int64, SubtractUInt64Single, SubtractUInt64Double },
        { SubtractInt64UInt8, SubtractInt64Int8, SubtractInt64UInt16, SubtractInt64Int16, SubtractInt64UInt32, SubtractInt64Int32, SubtractInt64UInt64, SubtractInt64Int64, SubtractInt64Single, SubtractInt64Double },
        { SubtractSingleUInt8, SubtractSingleInt8, SubtractSingleUInt16, SubtractSingleInt16, SubtractSingleUInt32, SubtractSingleInt32, SubtractSingleUInt64, SubtractSingleInt64, SubtractSingleSingle, SubtractSingleDouble },
        { SubtractDoubleUInt8, SubtractDoubleInt8, SubtractDoubleUInt16, SubtractDoubleInt16, SubtractDoubleUInt32, SubtractDoubleInt32, SubtractDoubleUInt64, SubtractDoubleInt64, SubtractDoubleSingle, SubtractDoubleDouble }
    };

    MulCallbackPtr MathOperation::mulFunctions[][10] =
    {
        { MultiplyUInt8UInt8, MultiplyUInt8Int8, MultiplyUInt8UInt16, MultiplyUInt8Int16, MultiplyUInt8UInt32, MultiplyUInt8Int32, MultiplyUInt8UInt64, MultiplyUInt8Int64, MultiplyUInt8Single, MultiplyUInt8Double }, 
        { MultiplyInt8UInt8, MultiplyInt8Int8, MultiplyInt8UInt16, MultiplyInt8Int16, MultiplyInt8UInt32, MultiplyInt8Int32, MultiplyInt8UInt64, MultiplyInt8Int64, MultiplyInt8Single, MultiplyInt8Double },
        { MultiplyUInt16UInt8, MultiplyUInt16Int8, MultiplyUInt16UInt16, MultiplyUInt16Int16, MultiplyUInt16UInt32, MultiplyUInt16Int32, MultiplyUInt16UInt64, MultiplyUInt16Int64, MultiplyUInt16Single, MultiplyUInt16Double },
        { MultiplyInt16UInt8, MultiplyInt16Int8, MultiplyInt16UInt16, MultiplyInt16Int16, MultiplyInt16UInt32, MultiplyInt16Int32, MultiplyInt16UInt64, MultiplyInt16Int64, MultiplyInt16Single, MultiplyInt16Double },
        { MultiplyUInt32UInt8, MultiplyUInt32Int8, MultiplyUInt32UInt16, MultiplyUInt32Int16, MultiplyUInt32UInt32, MultiplyUInt32Int32, MultiplyUInt32UInt64, MultiplyUInt32Int64, MultiplyUInt32Single, MultiplyUInt32Double },
        { MultiplyInt32UInt8, MultiplyInt32Int8, MultiplyInt32UInt16, MultiplyInt32Int16, MultiplyInt32UInt32, MultiplyInt32Int32, MultiplyInt32UInt64, MultiplyInt32Int64, MultiplyInt32Single, MultiplyInt32Double },
        { MultiplyUInt64UInt8, MultiplyUInt64Int8, MultiplyUInt64UInt16, MultiplyUInt64Int16, MultiplyUInt64UInt32, MultiplyUInt64Int32, MultiplyUInt64UInt64, MultiplyUInt64Int64, MultiplyUInt64Single, MultiplyUInt64Double },
        { MultiplyInt64UInt8, MultiplyInt64Int8, MultiplyInt64UInt16, MultiplyInt64Int16, MultiplyInt64UInt32, MultiplyInt64Int32, MultiplyInt64UInt64, MultiplyInt64Int64, MultiplyInt64Single, MultiplyInt64Double },
        { MultiplySingleUInt8, MultiplySingleInt8, MultiplySingleUInt16, MultiplySingleInt16, MultiplySingleUInt32, MultiplySingleInt32, MultiplySingleUInt64, MultiplySingleInt64, MultiplySingleSingle, MultiplySingleDouble },
        { MultiplyDoubleUInt8, MultiplyDoubleInt8, MultiplyDoubleUInt16, MultiplyDoubleInt16, MultiplyDoubleUInt32, MultiplyDoubleInt32, MultiplyDoubleUInt64, MultiplyDoubleInt64, MultiplyDoubleSingle, MultiplyDoubleDouble }
    };

    DivCallbackPtr MathOperation::divFunctions[][10] =
    {
        { DivideUInt8UInt8, DivideUInt8Int8, DivideUInt8UInt16, DivideUInt8Int16, DivideUInt8UInt32, DivideUInt8Int32, DivideUInt8UInt64, DivideUInt8Int64, DivideUInt8Single, DivideUInt8Double }, 
        { DivideInt8UInt8, DivideInt8Int8, DivideInt8UInt16, DivideInt8Int16, DivideInt8UInt32, DivideInt8Int32, DivideInt8UInt64, DivideInt8Int64, DivideInt8Single, DivideInt8Double },
        { DivideUInt16UInt8, DivideUInt16Int8, DivideUInt16UInt16, DivideUInt16Int16, DivideUInt16UInt32, DivideUInt16Int32, DivideUInt16UInt64, DivideUInt16Int64, DivideUInt16Single, DivideUInt16Double },
        { DivideInt16UInt8, DivideInt16Int8, DivideInt16UInt16, DivideInt16Int16, DivideInt16UInt32, DivideInt16Int32, DivideInt16UInt64, DivideInt16Int64, DivideInt16Single, DivideInt16Double },
        { DivideUInt32UInt8, DivideUInt32Int8, DivideUInt32UInt16, DivideUInt32Int16, DivideUInt32UInt32, DivideUInt32Int32, DivideUInt32UInt64, DivideUInt32Int64, DivideUInt32Single, DivideUInt32Double },
        { DivideInt32UInt8, DivideInt32Int8, DivideInt32UInt16, DivideInt32Int16, DivideInt32UInt32, DivideInt32Int32, DivideInt32UInt64, DivideInt32Int64, DivideInt32Single, DivideInt32Double },
        { DivideUInt64UInt8, DivideUInt64Int8, DivideUInt64UInt16, DivideUInt64Int16, DivideUInt64UInt32, DivideUInt64Int32, DivideUInt64UInt64, DivideUInt64Int64, DivideUInt64Single, DivideUInt64Double },
        { DivideInt64UInt8, DivideInt64Int8, DivideInt64UInt16, DivideInt64Int16, DivideInt64UInt32, DivideInt64Int32, DivideInt64UInt64, DivideInt64Int64, DivideInt64Single, DivideInt64Double },
        { DivideSingleUInt8, DivideSingleInt8, DivideSingleUInt16, DivideSingleInt16, DivideSingleUInt32, DivideSingleInt32, DivideSingleUInt64, DivideSingleInt64, DivideSingleSingle, DivideSingleDouble },
        { DivideDoubleUInt8, DivideDoubleInt8, DivideDoubleUInt16, DivideDoubleInt16, DivideDoubleUInt32, DivideDoubleInt32, DivideDoubleUInt64, DivideDoubleInt64, DivideDoubleSingle, DivideDoubleDouble }
    };

    int MathOperation::GetZeroFlag()
    {
        return zeroFlag;
    }
	
    int MathOperation::GetCompareFlag()
    {
        return compareFlag;
    }

    void MathOperation::ClearFlags()
    {
        zeroFlag = 0;
        compareFlag = 0;
    }

    void MathOperation::SetFlags(int flagCompare, int flagZero)
    {
        compareFlag = flagCompare;
        zeroFlag = flagZero;
    }

    void MathOperation::Compare(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType)
    {
        uint64_t result = cmpFunctions[lhsDataType][rhsDataType](lhs, rhs);

        if(result == 0)
            compareFlag = 0;
        else if(result < 0)
            compareFlag = -1;
        else
            compareFlag = 1;
    }

    void MathOperation::Add(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType)
    {
        addFunctions[lhsDataType][rhsDataType](lhs, rhs);
    }

    void MathOperation::Subtract(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType)
    {
        subFunctions[lhsDataType][rhsDataType](lhs, rhs);
    }

    void MathOperation::Multiply(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType)
    {
        mulFunctions[lhsDataType][rhsDataType](lhs, rhs);
    }

    void MathOperation::Divide(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType)
    {
        divFunctions[lhsDataType][rhsDataType](lhs, rhs);
    }

    //Compare--------------------------
    //---------------------------------
    //---------------------------------
    //---------------------------------

    uint64_t MathOperation::CompareUInt8UInt8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8Int8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8UInt16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8Int16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8UInt32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8Int32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8UInt64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8Int64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8Single(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt8Double(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8UInt8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8Int8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8UInt16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8Int16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8UInt32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8Int32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8UInt64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8Int64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8Single(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt8Double(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16UInt8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16Int8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16UInt16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16Int16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16UInt32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16Int32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16UInt64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16Int64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16Single(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt16Double(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16UInt8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16Int8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16UInt16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16Int16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16UInt32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16Int32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16UInt64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16Int64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16Single(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt16Double(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32UInt8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32Int8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32UInt16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32Int16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32UInt32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32Int32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32UInt64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32Int64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32Single(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt32Double(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32UInt8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32Int8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32UInt16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32Int16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32UInt32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32Int32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32UInt64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32Int64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32Single(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt32Double(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64UInt8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64Int8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64UInt16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64Int16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64UInt32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64Int32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64UInt64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64Int64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64Single(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareUInt64Double(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64UInt8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64Int8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64UInt16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64Int16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64UInt32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64Int32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64UInt64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64Int64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64Single(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareInt64Double(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleUInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleUInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleUInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleUInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleSingle(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareSingleDouble(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleUInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleUInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleUInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleUInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleSingle(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }

    uint64_t MathOperation::CompareDoubleDouble(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    int64_t result = (*ptrLhs - *ptrRhs);
	    return result;
    }


    //Add------------------------------
    //---------------------------------
    //---------------------------------
    //---------------------------------

    void MathOperation::AddUInt8UInt8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8Int8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8UInt16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8Int16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8UInt32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8Int32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8UInt64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8Int64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8Single(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt8Double(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8UInt8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8Int8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8UInt16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8Int16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8UInt32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8Int32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8UInt64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8Int64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8Single(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt8Double(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16UInt8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16Int8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16UInt16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16Int16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16UInt32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16Int32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16UInt64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16Int64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16Single(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt16Double(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16UInt8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16Int8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16UInt16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16Int16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16UInt32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16Int32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16UInt64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16Int64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16Single(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt16Double(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32UInt8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32Int8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32UInt16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32Int16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32UInt32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32Int32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32UInt64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32Int64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32Single(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt32Double(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32UInt8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32Int8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32UInt16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32Int16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32UInt32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32Int32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32UInt64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32Int64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32Single(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt32Double(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64UInt8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64Int8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64UInt16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64Int16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64UInt32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64Int32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64UInt64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64Int64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64Single(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddUInt64Double(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64UInt8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64Int8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64UInt16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64Int16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64UInt32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64Int32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64UInt64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64Int64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64Single(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddInt64Double(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleUInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleUInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleUInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleUInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleSingle(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddSingleDouble(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleUInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleUInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleUInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleUInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleSingle(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::AddDoubleDouble(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs += *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }


    //Subtract-------------------------
    //---------------------------------
    //---------------------------------
    //---------------------------------

    void MathOperation::SubtractUInt8UInt8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8Int8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8UInt16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8Int16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8UInt32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8Int32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8UInt64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8Int64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8Single(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt8Double(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8UInt8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8Int8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8UInt16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8Int16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8UInt32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8Int32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8UInt64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8Int64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8Single(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt8Double(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16UInt8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16Int8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16UInt16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16Int16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16UInt32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16Int32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16UInt64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16Int64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16Single(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt16Double(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16UInt8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16Int8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16UInt16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16Int16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16UInt32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16Int32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16UInt64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16Int64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16Single(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt16Double(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32UInt8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32Int8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32UInt16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32Int16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32UInt32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32Int32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32UInt64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32Int64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32Single(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt32Double(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32UInt8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32Int8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32UInt16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32Int16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32UInt32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32Int32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32UInt64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32Int64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32Single(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt32Double(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64UInt8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64Int8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64UInt16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64Int16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64UInt32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64Int32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64UInt64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64Int64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64Single(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractUInt64Double(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64UInt8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64Int8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64UInt16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64Int16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64UInt32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64Int32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64UInt64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64Int64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64Single(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractInt64Double(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleUInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleUInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleUInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleUInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleSingle(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractSingleDouble(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleUInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleUInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleUInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleUInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleSingle(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::SubtractDoubleDouble(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs -= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }


    //Multiply-------------------------
    //---------------------------------
    //---------------------------------
    //---------------------------------

    void MathOperation::MultiplyUInt8UInt8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8Int8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8UInt16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8Int16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8UInt32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8Int32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8UInt64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8Int64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8Single(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt8Double(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8UInt8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8Int8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8UInt16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8Int16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8UInt32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8Int32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8UInt64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8Int64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8Single(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt8Double(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16UInt8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16Int8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16UInt16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16Int16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16UInt32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16Int32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16UInt64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16Int64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16Single(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt16Double(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16UInt8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16Int8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16UInt16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16Int16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16UInt32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16Int32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16UInt64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16Int64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16Single(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt16Double(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32UInt8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32Int8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32UInt16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32Int16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32UInt32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32Int32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32UInt64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32Int64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32Single(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt32Double(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32UInt8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32Int8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32UInt16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32Int16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32UInt32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32Int32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32UInt64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32Int64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32Single(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt32Double(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64UInt8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64Int8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64UInt16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64Int16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64UInt32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64Int32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64UInt64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64Int64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64Single(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyUInt64Double(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64UInt8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64Int8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64UInt16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64Int16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64UInt32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64Int32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64UInt64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64Int64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64Single(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyInt64Double(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleUInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleUInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleUInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleUInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleSingle(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplySingleDouble(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleUInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleUInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleUInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleUInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleSingle(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::MultiplyDoubleDouble(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs *= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }


    //Divide---------------------------
    //---------------------------------
    //---------------------------------
    //---------------------------------

    void MathOperation::DivideUInt8UInt8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8Int8(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8UInt16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8Int16(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8UInt32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8Int32(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8UInt64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8Int64(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8Single(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt8Double(byte* lhs, byte* rhs)
    {
	    uint8_t* ptrLhs = reinterpret_cast<uint8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8UInt8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8Int8(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8UInt16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8Int16(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8UInt32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8Int32(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8UInt64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8Int64(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8Single(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt8Double(byte* lhs, byte* rhs)
    {
	    int8_t* ptrLhs = reinterpret_cast<int8_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16UInt8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16Int8(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16UInt16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16Int16(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16UInt32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16Int32(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16UInt64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16Int64(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16Single(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt16Double(byte* lhs, byte* rhs)
    {
	    uint16_t* ptrLhs = reinterpret_cast<uint16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16UInt8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16Int8(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16UInt16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16Int16(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16UInt32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16Int32(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16UInt64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16Int64(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16Single(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt16Double(byte* lhs, byte* rhs)
    {
	    int16_t* ptrLhs = reinterpret_cast<int16_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32UInt8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32Int8(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32UInt16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32Int16(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32UInt32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32Int32(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32UInt64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32Int64(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32Single(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt32Double(byte* lhs, byte* rhs)
    {
	    uint32_t* ptrLhs = reinterpret_cast<uint32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32UInt8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32Int8(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32UInt16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32Int16(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32UInt32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32Int32(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32UInt64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32Int64(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32Single(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt32Double(byte* lhs, byte* rhs)
    {
	    int32_t* ptrLhs = reinterpret_cast<int32_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64UInt8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64Int8(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64UInt16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64Int16(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64UInt32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64Int32(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64UInt64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64Int64(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64Single(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideUInt64Double(byte* lhs, byte* rhs)
    {
	    uint64_t* ptrLhs = reinterpret_cast<uint64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64UInt8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64Int8(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64UInt16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64Int16(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64UInt32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64Int32(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64UInt64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64Int64(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64Single(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideInt64Double(byte* lhs, byte* rhs)
    {
	    int64_t* ptrLhs = reinterpret_cast<int64_t*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleUInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleInt8(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleUInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleInt16(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleUInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleInt32(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleUInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleInt64(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleSingle(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideSingleDouble(byte* lhs, byte* rhs)
    {
	    float* ptrLhs = reinterpret_cast<float*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleUInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint8_t* ptrRhs = reinterpret_cast<uint8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleInt8(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int8_t* ptrRhs = reinterpret_cast<int8_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleUInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint16_t* ptrRhs = reinterpret_cast<uint16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleInt16(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int16_t* ptrRhs = reinterpret_cast<int16_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleUInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint32_t* ptrRhs = reinterpret_cast<uint32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleInt32(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int32_t* ptrRhs = reinterpret_cast<int32_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleUInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    uint64_t* ptrRhs = reinterpret_cast<uint64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleInt64(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    int64_t* ptrRhs = reinterpret_cast<int64_t*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleSingle(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    float* ptrRhs = reinterpret_cast<float*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }

    void MathOperation::DivideDoubleDouble(byte* lhs, byte* rhs)
    {
	    double* ptrLhs = reinterpret_cast<double*>(lhs);
	    double* ptrRhs = reinterpret_cast<double*>(rhs);
	    *ptrLhs /= *ptrRhs;
	    zeroFlag = *ptrLhs == 0 ? 1 : 0;
    }
}
