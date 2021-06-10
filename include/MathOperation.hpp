#ifndef STACKVM_MATHOPERATION_HPP
#define STACKVM_MATHOPERATION_HPP

#include "Specification.hpp"
#include <cstdint>
#include <iostream>

namespace StackVM
{
    //WARNING: This class contains generated code, so it's not recommend to casually start changing things
    typedef int64_t  (*CmpCallbackPtr)(byte* lhs, byte* rhs);
    typedef void     (*AddCallbackPtr)(byte* lhs, byte* rhs);
    typedef void     (*SubCallbackPtr)(byte* lhs, byte* rhs);
    typedef void     (*MulCallbackPtr)(byte* lhs, byte* rhs);
    typedef void     (*DivCallbackPtr)(byte* lhs, byte* rhs);

    class MathOperation
    {
    public:
        static int GetZeroFlag();
        static int GetCompareFlag();
        static void ClearFlags();
        static void Compare(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType);
        static void Add(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType);
        static void Subtract(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType);
        static void Multiply(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType);
        static void Divide(byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType);
    private:
        static int zeroFlag;
        static int compareFlag;
        static CmpCallbackPtr cmpFunctions[][10];
        static AddCallbackPtr addFunctions[][10];
        static SubCallbackPtr subFunctions[][10];
        static MulCallbackPtr mulFunctions[][10];
        static DivCallbackPtr divFunctions[][10];
        static void SetFlags(int flagCompare, int flagZero);

        template<typename T1, typename T2>
        static int64_t CompareTypeWithType(T1 lhs, T2 rhs)
        {
            if(lhs > rhs)
            {
                //std::cout << "LHS is greater than RHS\n";
                return 1;
            }
            else if(lhs < rhs)
            {
                //std::cout << "LHS is less than RHS\n";
                return -1;
            }
            else
            {
                //std::cout << "LHS is equal to RHS\n";
                return 0;
            }
        }

        //Compare--------------------------
        //---------------------------------
        //---------------------------------
        //---------------------------------

        static int64_t CompareUInt8UInt8(byte* lhs, byte* rhs);
        static int64_t CompareUInt8Int8(byte* lhs, byte* rhs);
        static int64_t CompareUInt8UInt16(byte* lhs, byte* rhs);
        static int64_t CompareUInt8Int16(byte* lhs, byte* rhs);
        static int64_t CompareUInt8UInt32(byte* lhs, byte* rhs);
        static int64_t CompareUInt8Int32(byte* lhs, byte* rhs);
        static int64_t CompareUInt8UInt64(byte* lhs, byte* rhs);
        static int64_t CompareUInt8Int64(byte* lhs, byte* rhs);
        static int64_t CompareUInt8Single(byte* lhs, byte* rhs);
        static int64_t CompareUInt8Double(byte* lhs, byte* rhs);
        static int64_t CompareInt8UInt8(byte* lhs, byte* rhs);
        static int64_t CompareInt8Int8(byte* lhs, byte* rhs);
        static int64_t CompareInt8UInt16(byte* lhs, byte* rhs);
        static int64_t CompareInt8Int16(byte* lhs, byte* rhs);
        static int64_t CompareInt8UInt32(byte* lhs, byte* rhs);
        static int64_t CompareInt8Int32(byte* lhs, byte* rhs);
        static int64_t CompareInt8UInt64(byte* lhs, byte* rhs);
        static int64_t CompareInt8Int64(byte* lhs, byte* rhs);
        static int64_t CompareInt8Single(byte* lhs, byte* rhs);
        static int64_t CompareInt8Double(byte* lhs, byte* rhs);
        static int64_t CompareUInt16UInt8(byte* lhs, byte* rhs);
        static int64_t CompareUInt16Int8(byte* lhs, byte* rhs);
        static int64_t CompareUInt16UInt16(byte* lhs, byte* rhs);
        static int64_t CompareUInt16Int16(byte* lhs, byte* rhs);
        static int64_t CompareUInt16UInt32(byte* lhs, byte* rhs);
        static int64_t CompareUInt16Int32(byte* lhs, byte* rhs);
        static int64_t CompareUInt16UInt64(byte* lhs, byte* rhs);
        static int64_t CompareUInt16Int64(byte* lhs, byte* rhs);
        static int64_t CompareUInt16Single(byte* lhs, byte* rhs);
        static int64_t CompareUInt16Double(byte* lhs, byte* rhs);
        static int64_t CompareInt16UInt8(byte* lhs, byte* rhs);
        static int64_t CompareInt16Int8(byte* lhs, byte* rhs);
        static int64_t CompareInt16UInt16(byte* lhs, byte* rhs);
        static int64_t CompareInt16Int16(byte* lhs, byte* rhs);
        static int64_t CompareInt16UInt32(byte* lhs, byte* rhs);
        static int64_t CompareInt16Int32(byte* lhs, byte* rhs);
        static int64_t CompareInt16UInt64(byte* lhs, byte* rhs);
        static int64_t CompareInt16Int64(byte* lhs, byte* rhs);
        static int64_t CompareInt16Single(byte* lhs, byte* rhs);
        static int64_t CompareInt16Double(byte* lhs, byte* rhs);
        static int64_t CompareUInt32UInt8(byte* lhs, byte* rhs);
        static int64_t CompareUInt32Int8(byte* lhs, byte* rhs);
        static int64_t CompareUInt32UInt16(byte* lhs, byte* rhs);
        static int64_t CompareUInt32Int16(byte* lhs, byte* rhs);
        static int64_t CompareUInt32UInt32(byte* lhs, byte* rhs);
        static int64_t CompareUInt32Int32(byte* lhs, byte* rhs);
        static int64_t CompareUInt32UInt64(byte* lhs, byte* rhs);
        static int64_t CompareUInt32Int64(byte* lhs, byte* rhs);
        static int64_t CompareUInt32Single(byte* lhs, byte* rhs);
        static int64_t CompareUInt32Double(byte* lhs, byte* rhs);
        static int64_t CompareInt32UInt8(byte* lhs, byte* rhs);
        static int64_t CompareInt32Int8(byte* lhs, byte* rhs);
        static int64_t CompareInt32UInt16(byte* lhs, byte* rhs);
        static int64_t CompareInt32Int16(byte* lhs, byte* rhs);
        static int64_t CompareInt32UInt32(byte* lhs, byte* rhs);
        static int64_t CompareInt32Int32(byte* lhs, byte* rhs);
        static int64_t CompareInt32UInt64(byte* lhs, byte* rhs);
        static int64_t CompareInt32Int64(byte* lhs, byte* rhs);
        static int64_t CompareInt32Single(byte* lhs, byte* rhs);
        static int64_t CompareInt32Double(byte* lhs, byte* rhs);
        static int64_t CompareUInt64UInt8(byte* lhs, byte* rhs);
        static int64_t CompareUInt64Int8(byte* lhs, byte* rhs);
        static int64_t CompareUInt64UInt16(byte* lhs, byte* rhs);
        static int64_t CompareUInt64Int16(byte* lhs, byte* rhs);
        static int64_t CompareUInt64UInt32(byte* lhs, byte* rhs);
        static int64_t CompareUInt64Int32(byte* lhs, byte* rhs);
        static int64_t CompareUInt64UInt64(byte* lhs, byte* rhs);
        static int64_t CompareUInt64Int64(byte* lhs, byte* rhs);
        static int64_t CompareUInt64Single(byte* lhs, byte* rhs);
        static int64_t CompareUInt64Double(byte* lhs, byte* rhs);
        static int64_t CompareInt64UInt8(byte* lhs, byte* rhs);
        static int64_t CompareInt64Int8(byte* lhs, byte* rhs);
        static int64_t CompareInt64UInt16(byte* lhs, byte* rhs);
        static int64_t CompareInt64Int16(byte* lhs, byte* rhs);
        static int64_t CompareInt64UInt32(byte* lhs, byte* rhs);
        static int64_t CompareInt64Int32(byte* lhs, byte* rhs);
        static int64_t CompareInt64UInt64(byte* lhs, byte* rhs);
        static int64_t CompareInt64Int64(byte* lhs, byte* rhs);
        static int64_t CompareInt64Single(byte* lhs, byte* rhs);
        static int64_t CompareInt64Double(byte* lhs, byte* rhs);
        static int64_t CompareSingleUInt8(byte* lhs, byte* rhs);
        static int64_t CompareSingleInt8(byte* lhs, byte* rhs);
        static int64_t CompareSingleUInt16(byte* lhs, byte* rhs);
        static int64_t CompareSingleInt16(byte* lhs, byte* rhs);
        static int64_t CompareSingleUInt32(byte* lhs, byte* rhs);
        static int64_t CompareSingleInt32(byte* lhs, byte* rhs);
        static int64_t CompareSingleUInt64(byte* lhs, byte* rhs);
        static int64_t CompareSingleInt64(byte* lhs, byte* rhs);
        static int64_t CompareSingleSingle(byte* lhs, byte* rhs);
        static int64_t CompareSingleDouble(byte* lhs, byte* rhs);
        static int64_t CompareDoubleUInt8(byte* lhs, byte* rhs);
        static int64_t CompareDoubleInt8(byte* lhs, byte* rhs);
        static int64_t CompareDoubleUInt16(byte* lhs, byte* rhs);
        static int64_t CompareDoubleInt16(byte* lhs, byte* rhs);
        static int64_t CompareDoubleUInt32(byte* lhs, byte* rhs);
        static int64_t CompareDoubleInt32(byte* lhs, byte* rhs);
        static int64_t CompareDoubleUInt64(byte* lhs, byte* rhs);
        static int64_t CompareDoubleInt64(byte* lhs, byte* rhs);
        static int64_t CompareDoubleSingle(byte* lhs, byte* rhs);
        static int64_t CompareDoubleDouble(byte* lhs, byte* rhs);

        //Add------------------------------
        //---------------------------------
        //---------------------------------
        //---------------------------------

        static void AddUInt8UInt8(byte* lhs, byte* rhs);
        static void AddUInt8Int8(byte* lhs, byte* rhs);
        static void AddUInt8UInt16(byte* lhs, byte* rhs);
        static void AddUInt8Int16(byte* lhs, byte* rhs);
        static void AddUInt8UInt32(byte* lhs, byte* rhs);
        static void AddUInt8Int32(byte* lhs, byte* rhs);
        static void AddUInt8UInt64(byte* lhs, byte* rhs);
        static void AddUInt8Int64(byte* lhs, byte* rhs);
        static void AddUInt8Single(byte* lhs, byte* rhs);
        static void AddUInt8Double(byte* lhs, byte* rhs);
        static void AddInt8UInt8(byte* lhs, byte* rhs);
        static void AddInt8Int8(byte* lhs, byte* rhs);
        static void AddInt8UInt16(byte* lhs, byte* rhs);
        static void AddInt8Int16(byte* lhs, byte* rhs);
        static void AddInt8UInt32(byte* lhs, byte* rhs);
        static void AddInt8Int32(byte* lhs, byte* rhs);
        static void AddInt8UInt64(byte* lhs, byte* rhs);
        static void AddInt8Int64(byte* lhs, byte* rhs);
        static void AddInt8Single(byte* lhs, byte* rhs);
        static void AddInt8Double(byte* lhs, byte* rhs);
        static void AddUInt16UInt8(byte* lhs, byte* rhs);
        static void AddUInt16Int8(byte* lhs, byte* rhs);
        static void AddUInt16UInt16(byte* lhs, byte* rhs);
        static void AddUInt16Int16(byte* lhs, byte* rhs);
        static void AddUInt16UInt32(byte* lhs, byte* rhs);
        static void AddUInt16Int32(byte* lhs, byte* rhs);
        static void AddUInt16UInt64(byte* lhs, byte* rhs);
        static void AddUInt16Int64(byte* lhs, byte* rhs);
        static void AddUInt16Single(byte* lhs, byte* rhs);
        static void AddUInt16Double(byte* lhs, byte* rhs);
        static void AddInt16UInt8(byte* lhs, byte* rhs);
        static void AddInt16Int8(byte* lhs, byte* rhs);
        static void AddInt16UInt16(byte* lhs, byte* rhs);
        static void AddInt16Int16(byte* lhs, byte* rhs);
        static void AddInt16UInt32(byte* lhs, byte* rhs);
        static void AddInt16Int32(byte* lhs, byte* rhs);
        static void AddInt16UInt64(byte* lhs, byte* rhs);
        static void AddInt16Int64(byte* lhs, byte* rhs);
        static void AddInt16Single(byte* lhs, byte* rhs);
        static void AddInt16Double(byte* lhs, byte* rhs);
        static void AddUInt32UInt8(byte* lhs, byte* rhs);
        static void AddUInt32Int8(byte* lhs, byte* rhs);
        static void AddUInt32UInt16(byte* lhs, byte* rhs);
        static void AddUInt32Int16(byte* lhs, byte* rhs);
        static void AddUInt32UInt32(byte* lhs, byte* rhs);
        static void AddUInt32Int32(byte* lhs, byte* rhs);
        static void AddUInt32UInt64(byte* lhs, byte* rhs);
        static void AddUInt32Int64(byte* lhs, byte* rhs);
        static void AddUInt32Single(byte* lhs, byte* rhs);
        static void AddUInt32Double(byte* lhs, byte* rhs);
        static void AddInt32UInt8(byte* lhs, byte* rhs);
        static void AddInt32Int8(byte* lhs, byte* rhs);
        static void AddInt32UInt16(byte* lhs, byte* rhs);
        static void AddInt32Int16(byte* lhs, byte* rhs);
        static void AddInt32UInt32(byte* lhs, byte* rhs);
        static void AddInt32Int32(byte* lhs, byte* rhs);
        static void AddInt32UInt64(byte* lhs, byte* rhs);
        static void AddInt32Int64(byte* lhs, byte* rhs);
        static void AddInt32Single(byte* lhs, byte* rhs);
        static void AddInt32Double(byte* lhs, byte* rhs);
        static void AddUInt64UInt8(byte* lhs, byte* rhs);
        static void AddUInt64Int8(byte* lhs, byte* rhs);
        static void AddUInt64UInt16(byte* lhs, byte* rhs);
        static void AddUInt64Int16(byte* lhs, byte* rhs);
        static void AddUInt64UInt32(byte* lhs, byte* rhs);
        static void AddUInt64Int32(byte* lhs, byte* rhs);
        static void AddUInt64UInt64(byte* lhs, byte* rhs);
        static void AddUInt64Int64(byte* lhs, byte* rhs);
        static void AddUInt64Single(byte* lhs, byte* rhs);
        static void AddUInt64Double(byte* lhs, byte* rhs);
        static void AddInt64UInt8(byte* lhs, byte* rhs);
        static void AddInt64Int8(byte* lhs, byte* rhs);
        static void AddInt64UInt16(byte* lhs, byte* rhs);
        static void AddInt64Int16(byte* lhs, byte* rhs);
        static void AddInt64UInt32(byte* lhs, byte* rhs);
        static void AddInt64Int32(byte* lhs, byte* rhs);
        static void AddInt64UInt64(byte* lhs, byte* rhs);
        static void AddInt64Int64(byte* lhs, byte* rhs);
        static void AddInt64Single(byte* lhs, byte* rhs);
        static void AddInt64Double(byte* lhs, byte* rhs);
        static void AddSingleUInt8(byte* lhs, byte* rhs);
        static void AddSingleInt8(byte* lhs, byte* rhs);
        static void AddSingleUInt16(byte* lhs, byte* rhs);
        static void AddSingleInt16(byte* lhs, byte* rhs);
        static void AddSingleUInt32(byte* lhs, byte* rhs);
        static void AddSingleInt32(byte* lhs, byte* rhs);
        static void AddSingleUInt64(byte* lhs, byte* rhs);
        static void AddSingleInt64(byte* lhs, byte* rhs);
        static void AddSingleSingle(byte* lhs, byte* rhs);
        static void AddSingleDouble(byte* lhs, byte* rhs);
        static void AddDoubleUInt8(byte* lhs, byte* rhs);
        static void AddDoubleInt8(byte* lhs, byte* rhs);
        static void AddDoubleUInt16(byte* lhs, byte* rhs);
        static void AddDoubleInt16(byte* lhs, byte* rhs);
        static void AddDoubleUInt32(byte* lhs, byte* rhs);
        static void AddDoubleInt32(byte* lhs, byte* rhs);
        static void AddDoubleUInt64(byte* lhs, byte* rhs);
        static void AddDoubleInt64(byte* lhs, byte* rhs);
        static void AddDoubleSingle(byte* lhs, byte* rhs);
        static void AddDoubleDouble(byte* lhs, byte* rhs);

        //Subtract-------------------------
        //---------------------------------
        //---------------------------------
        //---------------------------------

        static void SubtractUInt8UInt8(byte* lhs, byte* rhs);
        static void SubtractUInt8Int8(byte* lhs, byte* rhs);
        static void SubtractUInt8UInt16(byte* lhs, byte* rhs);
        static void SubtractUInt8Int16(byte* lhs, byte* rhs);
        static void SubtractUInt8UInt32(byte* lhs, byte* rhs);
        static void SubtractUInt8Int32(byte* lhs, byte* rhs);
        static void SubtractUInt8UInt64(byte* lhs, byte* rhs);
        static void SubtractUInt8Int64(byte* lhs, byte* rhs);
        static void SubtractUInt8Single(byte* lhs, byte* rhs);
        static void SubtractUInt8Double(byte* lhs, byte* rhs);
        static void SubtractInt8UInt8(byte* lhs, byte* rhs);
        static void SubtractInt8Int8(byte* lhs, byte* rhs);
        static void SubtractInt8UInt16(byte* lhs, byte* rhs);
        static void SubtractInt8Int16(byte* lhs, byte* rhs);
        static void SubtractInt8UInt32(byte* lhs, byte* rhs);
        static void SubtractInt8Int32(byte* lhs, byte* rhs);
        static void SubtractInt8UInt64(byte* lhs, byte* rhs);
        static void SubtractInt8Int64(byte* lhs, byte* rhs);
        static void SubtractInt8Single(byte* lhs, byte* rhs);
        static void SubtractInt8Double(byte* lhs, byte* rhs);
        static void SubtractUInt16UInt8(byte* lhs, byte* rhs);
        static void SubtractUInt16Int8(byte* lhs, byte* rhs);
        static void SubtractUInt16UInt16(byte* lhs, byte* rhs);
        static void SubtractUInt16Int16(byte* lhs, byte* rhs);
        static void SubtractUInt16UInt32(byte* lhs, byte* rhs);
        static void SubtractUInt16Int32(byte* lhs, byte* rhs);
        static void SubtractUInt16UInt64(byte* lhs, byte* rhs);
        static void SubtractUInt16Int64(byte* lhs, byte* rhs);
        static void SubtractUInt16Single(byte* lhs, byte* rhs);
        static void SubtractUInt16Double(byte* lhs, byte* rhs);
        static void SubtractInt16UInt8(byte* lhs, byte* rhs);
        static void SubtractInt16Int8(byte* lhs, byte* rhs);
        static void SubtractInt16UInt16(byte* lhs, byte* rhs);
        static void SubtractInt16Int16(byte* lhs, byte* rhs);
        static void SubtractInt16UInt32(byte* lhs, byte* rhs);
        static void SubtractInt16Int32(byte* lhs, byte* rhs);
        static void SubtractInt16UInt64(byte* lhs, byte* rhs);
        static void SubtractInt16Int64(byte* lhs, byte* rhs);
        static void SubtractInt16Single(byte* lhs, byte* rhs);
        static void SubtractInt16Double(byte* lhs, byte* rhs);
        static void SubtractUInt32UInt8(byte* lhs, byte* rhs);
        static void SubtractUInt32Int8(byte* lhs, byte* rhs);
        static void SubtractUInt32UInt16(byte* lhs, byte* rhs);
        static void SubtractUInt32Int16(byte* lhs, byte* rhs);
        static void SubtractUInt32UInt32(byte* lhs, byte* rhs);
        static void SubtractUInt32Int32(byte* lhs, byte* rhs);
        static void SubtractUInt32UInt64(byte* lhs, byte* rhs);
        static void SubtractUInt32Int64(byte* lhs, byte* rhs);
        static void SubtractUInt32Single(byte* lhs, byte* rhs);
        static void SubtractUInt32Double(byte* lhs, byte* rhs);
        static void SubtractInt32UInt8(byte* lhs, byte* rhs);
        static void SubtractInt32Int8(byte* lhs, byte* rhs);
        static void SubtractInt32UInt16(byte* lhs, byte* rhs);
        static void SubtractInt32Int16(byte* lhs, byte* rhs);
        static void SubtractInt32UInt32(byte* lhs, byte* rhs);
        static void SubtractInt32Int32(byte* lhs, byte* rhs);
        static void SubtractInt32UInt64(byte* lhs, byte* rhs);
        static void SubtractInt32Int64(byte* lhs, byte* rhs);
        static void SubtractInt32Single(byte* lhs, byte* rhs);
        static void SubtractInt32Double(byte* lhs, byte* rhs);
        static void SubtractUInt64UInt8(byte* lhs, byte* rhs);
        static void SubtractUInt64Int8(byte* lhs, byte* rhs);
        static void SubtractUInt64UInt16(byte* lhs, byte* rhs);
        static void SubtractUInt64Int16(byte* lhs, byte* rhs);
        static void SubtractUInt64UInt32(byte* lhs, byte* rhs);
        static void SubtractUInt64Int32(byte* lhs, byte* rhs);
        static void SubtractUInt64UInt64(byte* lhs, byte* rhs);
        static void SubtractUInt64Int64(byte* lhs, byte* rhs);
        static void SubtractUInt64Single(byte* lhs, byte* rhs);
        static void SubtractUInt64Double(byte* lhs, byte* rhs);
        static void SubtractInt64UInt8(byte* lhs, byte* rhs);
        static void SubtractInt64Int8(byte* lhs, byte* rhs);
        static void SubtractInt64UInt16(byte* lhs, byte* rhs);
        static void SubtractInt64Int16(byte* lhs, byte* rhs);
        static void SubtractInt64UInt32(byte* lhs, byte* rhs);
        static void SubtractInt64Int32(byte* lhs, byte* rhs);
        static void SubtractInt64UInt64(byte* lhs, byte* rhs);
        static void SubtractInt64Int64(byte* lhs, byte* rhs);
        static void SubtractInt64Single(byte* lhs, byte* rhs);
        static void SubtractInt64Double(byte* lhs, byte* rhs);
        static void SubtractSingleUInt8(byte* lhs, byte* rhs);
        static void SubtractSingleInt8(byte* lhs, byte* rhs);
        static void SubtractSingleUInt16(byte* lhs, byte* rhs);
        static void SubtractSingleInt16(byte* lhs, byte* rhs);
        static void SubtractSingleUInt32(byte* lhs, byte* rhs);
        static void SubtractSingleInt32(byte* lhs, byte* rhs);
        static void SubtractSingleUInt64(byte* lhs, byte* rhs);
        static void SubtractSingleInt64(byte* lhs, byte* rhs);
        static void SubtractSingleSingle(byte* lhs, byte* rhs);
        static void SubtractSingleDouble(byte* lhs, byte* rhs);
        static void SubtractDoubleUInt8(byte* lhs, byte* rhs);
        static void SubtractDoubleInt8(byte* lhs, byte* rhs);
        static void SubtractDoubleUInt16(byte* lhs, byte* rhs);
        static void SubtractDoubleInt16(byte* lhs, byte* rhs);
        static void SubtractDoubleUInt32(byte* lhs, byte* rhs);
        static void SubtractDoubleInt32(byte* lhs, byte* rhs);
        static void SubtractDoubleUInt64(byte* lhs, byte* rhs);
        static void SubtractDoubleInt64(byte* lhs, byte* rhs);
        static void SubtractDoubleSingle(byte* lhs, byte* rhs);
        static void SubtractDoubleDouble(byte* lhs, byte* rhs);

        //Multiply-------------------------
        //---------------------------------
        //---------------------------------
        //---------------------------------

        static void MultiplyUInt8UInt8(byte* lhs, byte* rhs);
        static void MultiplyUInt8Int8(byte* lhs, byte* rhs);
        static void MultiplyUInt8UInt16(byte* lhs, byte* rhs);
        static void MultiplyUInt8Int16(byte* lhs, byte* rhs);
        static void MultiplyUInt8UInt32(byte* lhs, byte* rhs);
        static void MultiplyUInt8Int32(byte* lhs, byte* rhs);
        static void MultiplyUInt8UInt64(byte* lhs, byte* rhs);
        static void MultiplyUInt8Int64(byte* lhs, byte* rhs);
        static void MultiplyUInt8Single(byte* lhs, byte* rhs);
        static void MultiplyUInt8Double(byte* lhs, byte* rhs);
        static void MultiplyInt8UInt8(byte* lhs, byte* rhs);
        static void MultiplyInt8Int8(byte* lhs, byte* rhs);
        static void MultiplyInt8UInt16(byte* lhs, byte* rhs);
        static void MultiplyInt8Int16(byte* lhs, byte* rhs);
        static void MultiplyInt8UInt32(byte* lhs, byte* rhs);
        static void MultiplyInt8Int32(byte* lhs, byte* rhs);
        static void MultiplyInt8UInt64(byte* lhs, byte* rhs);
        static void MultiplyInt8Int64(byte* lhs, byte* rhs);
        static void MultiplyInt8Single(byte* lhs, byte* rhs);
        static void MultiplyInt8Double(byte* lhs, byte* rhs);
        static void MultiplyUInt16UInt8(byte* lhs, byte* rhs);
        static void MultiplyUInt16Int8(byte* lhs, byte* rhs);
        static void MultiplyUInt16UInt16(byte* lhs, byte* rhs);
        static void MultiplyUInt16Int16(byte* lhs, byte* rhs);
        static void MultiplyUInt16UInt32(byte* lhs, byte* rhs);
        static void MultiplyUInt16Int32(byte* lhs, byte* rhs);
        static void MultiplyUInt16UInt64(byte* lhs, byte* rhs);
        static void MultiplyUInt16Int64(byte* lhs, byte* rhs);
        static void MultiplyUInt16Single(byte* lhs, byte* rhs);
        static void MultiplyUInt16Double(byte* lhs, byte* rhs);
        static void MultiplyInt16UInt8(byte* lhs, byte* rhs);
        static void MultiplyInt16Int8(byte* lhs, byte* rhs);
        static void MultiplyInt16UInt16(byte* lhs, byte* rhs);
        static void MultiplyInt16Int16(byte* lhs, byte* rhs);
        static void MultiplyInt16UInt32(byte* lhs, byte* rhs);
        static void MultiplyInt16Int32(byte* lhs, byte* rhs);
        static void MultiplyInt16UInt64(byte* lhs, byte* rhs);
        static void MultiplyInt16Int64(byte* lhs, byte* rhs);
        static void MultiplyInt16Single(byte* lhs, byte* rhs);
        static void MultiplyInt16Double(byte* lhs, byte* rhs);
        static void MultiplyUInt32UInt8(byte* lhs, byte* rhs);
        static void MultiplyUInt32Int8(byte* lhs, byte* rhs);
        static void MultiplyUInt32UInt16(byte* lhs, byte* rhs);
        static void MultiplyUInt32Int16(byte* lhs, byte* rhs);
        static void MultiplyUInt32UInt32(byte* lhs, byte* rhs);
        static void MultiplyUInt32Int32(byte* lhs, byte* rhs);
        static void MultiplyUInt32UInt64(byte* lhs, byte* rhs);
        static void MultiplyUInt32Int64(byte* lhs, byte* rhs);
        static void MultiplyUInt32Single(byte* lhs, byte* rhs);
        static void MultiplyUInt32Double(byte* lhs, byte* rhs);
        static void MultiplyInt32UInt8(byte* lhs, byte* rhs);
        static void MultiplyInt32Int8(byte* lhs, byte* rhs);
        static void MultiplyInt32UInt16(byte* lhs, byte* rhs);
        static void MultiplyInt32Int16(byte* lhs, byte* rhs);
        static void MultiplyInt32UInt32(byte* lhs, byte* rhs);
        static void MultiplyInt32Int32(byte* lhs, byte* rhs);
        static void MultiplyInt32UInt64(byte* lhs, byte* rhs);
        static void MultiplyInt32Int64(byte* lhs, byte* rhs);
        static void MultiplyInt32Single(byte* lhs, byte* rhs);
        static void MultiplyInt32Double(byte* lhs, byte* rhs);
        static void MultiplyUInt64UInt8(byte* lhs, byte* rhs);
        static void MultiplyUInt64Int8(byte* lhs, byte* rhs);
        static void MultiplyUInt64UInt16(byte* lhs, byte* rhs);
        static void MultiplyUInt64Int16(byte* lhs, byte* rhs);
        static void MultiplyUInt64UInt32(byte* lhs, byte* rhs);
        static void MultiplyUInt64Int32(byte* lhs, byte* rhs);
        static void MultiplyUInt64UInt64(byte* lhs, byte* rhs);
        static void MultiplyUInt64Int64(byte* lhs, byte* rhs);
        static void MultiplyUInt64Single(byte* lhs, byte* rhs);
        static void MultiplyUInt64Double(byte* lhs, byte* rhs);
        static void MultiplyInt64UInt8(byte* lhs, byte* rhs);
        static void MultiplyInt64Int8(byte* lhs, byte* rhs);
        static void MultiplyInt64UInt16(byte* lhs, byte* rhs);
        static void MultiplyInt64Int16(byte* lhs, byte* rhs);
        static void MultiplyInt64UInt32(byte* lhs, byte* rhs);
        static void MultiplyInt64Int32(byte* lhs, byte* rhs);
        static void MultiplyInt64UInt64(byte* lhs, byte* rhs);
        static void MultiplyInt64Int64(byte* lhs, byte* rhs);
        static void MultiplyInt64Single(byte* lhs, byte* rhs);
        static void MultiplyInt64Double(byte* lhs, byte* rhs);
        static void MultiplySingleUInt8(byte* lhs, byte* rhs);
        static void MultiplySingleInt8(byte* lhs, byte* rhs);
        static void MultiplySingleUInt16(byte* lhs, byte* rhs);
        static void MultiplySingleInt16(byte* lhs, byte* rhs);
        static void MultiplySingleUInt32(byte* lhs, byte* rhs);
        static void MultiplySingleInt32(byte* lhs, byte* rhs);
        static void MultiplySingleUInt64(byte* lhs, byte* rhs);
        static void MultiplySingleInt64(byte* lhs, byte* rhs);
        static void MultiplySingleSingle(byte* lhs, byte* rhs);
        static void MultiplySingleDouble(byte* lhs, byte* rhs);
        static void MultiplyDoubleUInt8(byte* lhs, byte* rhs);
        static void MultiplyDoubleInt8(byte* lhs, byte* rhs);
        static void MultiplyDoubleUInt16(byte* lhs, byte* rhs);
        static void MultiplyDoubleInt16(byte* lhs, byte* rhs);
        static void MultiplyDoubleUInt32(byte* lhs, byte* rhs);
        static void MultiplyDoubleInt32(byte* lhs, byte* rhs);
        static void MultiplyDoubleUInt64(byte* lhs, byte* rhs);
        static void MultiplyDoubleInt64(byte* lhs, byte* rhs);
        static void MultiplyDoubleSingle(byte* lhs, byte* rhs);
        static void MultiplyDoubleDouble(byte* lhs, byte* rhs);

        //Divide---------------------------
        //---------------------------------
        //---------------------------------
        //---------------------------------

        static void DivideUInt8UInt8(byte* lhs, byte* rhs);
        static void DivideUInt8Int8(byte* lhs, byte* rhs);
        static void DivideUInt8UInt16(byte* lhs, byte* rhs);
        static void DivideUInt8Int16(byte* lhs, byte* rhs);
        static void DivideUInt8UInt32(byte* lhs, byte* rhs);
        static void DivideUInt8Int32(byte* lhs, byte* rhs);
        static void DivideUInt8UInt64(byte* lhs, byte* rhs);
        static void DivideUInt8Int64(byte* lhs, byte* rhs);
        static void DivideUInt8Single(byte* lhs, byte* rhs);
        static void DivideUInt8Double(byte* lhs, byte* rhs);
        static void DivideInt8UInt8(byte* lhs, byte* rhs);
        static void DivideInt8Int8(byte* lhs, byte* rhs);
        static void DivideInt8UInt16(byte* lhs, byte* rhs);
        static void DivideInt8Int16(byte* lhs, byte* rhs);
        static void DivideInt8UInt32(byte* lhs, byte* rhs);
        static void DivideInt8Int32(byte* lhs, byte* rhs);
        static void DivideInt8UInt64(byte* lhs, byte* rhs);
        static void DivideInt8Int64(byte* lhs, byte* rhs);
        static void DivideInt8Single(byte* lhs, byte* rhs);
        static void DivideInt8Double(byte* lhs, byte* rhs);
        static void DivideUInt16UInt8(byte* lhs, byte* rhs);
        static void DivideUInt16Int8(byte* lhs, byte* rhs);
        static void DivideUInt16UInt16(byte* lhs, byte* rhs);
        static void DivideUInt16Int16(byte* lhs, byte* rhs);
        static void DivideUInt16UInt32(byte* lhs, byte* rhs);
        static void DivideUInt16Int32(byte* lhs, byte* rhs);
        static void DivideUInt16UInt64(byte* lhs, byte* rhs);
        static void DivideUInt16Int64(byte* lhs, byte* rhs);
        static void DivideUInt16Single(byte* lhs, byte* rhs);
        static void DivideUInt16Double(byte* lhs, byte* rhs);
        static void DivideInt16UInt8(byte* lhs, byte* rhs);
        static void DivideInt16Int8(byte* lhs, byte* rhs);
        static void DivideInt16UInt16(byte* lhs, byte* rhs);
        static void DivideInt16Int16(byte* lhs, byte* rhs);
        static void DivideInt16UInt32(byte* lhs, byte* rhs);
        static void DivideInt16Int32(byte* lhs, byte* rhs);
        static void DivideInt16UInt64(byte* lhs, byte* rhs);
        static void DivideInt16Int64(byte* lhs, byte* rhs);
        static void DivideInt16Single(byte* lhs, byte* rhs);
        static void DivideInt16Double(byte* lhs, byte* rhs);
        static void DivideUInt32UInt8(byte* lhs, byte* rhs);
        static void DivideUInt32Int8(byte* lhs, byte* rhs);
        static void DivideUInt32UInt16(byte* lhs, byte* rhs);
        static void DivideUInt32Int16(byte* lhs, byte* rhs);
        static void DivideUInt32UInt32(byte* lhs, byte* rhs);
        static void DivideUInt32Int32(byte* lhs, byte* rhs);
        static void DivideUInt32UInt64(byte* lhs, byte* rhs);
        static void DivideUInt32Int64(byte* lhs, byte* rhs);
        static void DivideUInt32Single(byte* lhs, byte* rhs);
        static void DivideUInt32Double(byte* lhs, byte* rhs);
        static void DivideInt32UInt8(byte* lhs, byte* rhs);
        static void DivideInt32Int8(byte* lhs, byte* rhs);
        static void DivideInt32UInt16(byte* lhs, byte* rhs);
        static void DivideInt32Int16(byte* lhs, byte* rhs);
        static void DivideInt32UInt32(byte* lhs, byte* rhs);
        static void DivideInt32Int32(byte* lhs, byte* rhs);
        static void DivideInt32UInt64(byte* lhs, byte* rhs);
        static void DivideInt32Int64(byte* lhs, byte* rhs);
        static void DivideInt32Single(byte* lhs, byte* rhs);
        static void DivideInt32Double(byte* lhs, byte* rhs);
        static void DivideUInt64UInt8(byte* lhs, byte* rhs);
        static void DivideUInt64Int8(byte* lhs, byte* rhs);
        static void DivideUInt64UInt16(byte* lhs, byte* rhs);
        static void DivideUInt64Int16(byte* lhs, byte* rhs);
        static void DivideUInt64UInt32(byte* lhs, byte* rhs);
        static void DivideUInt64Int32(byte* lhs, byte* rhs);
        static void DivideUInt64UInt64(byte* lhs, byte* rhs);
        static void DivideUInt64Int64(byte* lhs, byte* rhs);
        static void DivideUInt64Single(byte* lhs, byte* rhs);
        static void DivideUInt64Double(byte* lhs, byte* rhs);
        static void DivideInt64UInt8(byte* lhs, byte* rhs);
        static void DivideInt64Int8(byte* lhs, byte* rhs);
        static void DivideInt64UInt16(byte* lhs, byte* rhs);
        static void DivideInt64Int16(byte* lhs, byte* rhs);
        static void DivideInt64UInt32(byte* lhs, byte* rhs);
        static void DivideInt64Int32(byte* lhs, byte* rhs);
        static void DivideInt64UInt64(byte* lhs, byte* rhs);
        static void DivideInt64Int64(byte* lhs, byte* rhs);
        static void DivideInt64Single(byte* lhs, byte* rhs);
        static void DivideInt64Double(byte* lhs, byte* rhs);
        static void DivideSingleUInt8(byte* lhs, byte* rhs);
        static void DivideSingleInt8(byte* lhs, byte* rhs);
        static void DivideSingleUInt16(byte* lhs, byte* rhs);
        static void DivideSingleInt16(byte* lhs, byte* rhs);
        static void DivideSingleUInt32(byte* lhs, byte* rhs);
        static void DivideSingleInt32(byte* lhs, byte* rhs);
        static void DivideSingleUInt64(byte* lhs, byte* rhs);
        static void DivideSingleInt64(byte* lhs, byte* rhs);
        static void DivideSingleSingle(byte* lhs, byte* rhs);
        static void DivideSingleDouble(byte* lhs, byte* rhs);
        static void DivideDoubleUInt8(byte* lhs, byte* rhs);
        static void DivideDoubleInt8(byte* lhs, byte* rhs);
        static void DivideDoubleUInt16(byte* lhs, byte* rhs);
        static void DivideDoubleInt16(byte* lhs, byte* rhs);
        static void DivideDoubleUInt32(byte* lhs, byte* rhs);
        static void DivideDoubleInt32(byte* lhs, byte* rhs);
        static void DivideDoubleUInt64(byte* lhs, byte* rhs);
        static void DivideDoubleInt64(byte* lhs, byte* rhs);
        static void DivideDoubleSingle(byte* lhs, byte* rhs);
        static void DivideDoubleDouble(byte* lhs, byte* rhs);
    };
}
#endif
