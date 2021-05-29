#include "MathOperation.hpp"
#include <iostream>

namespace StackVM
{
    int MathOperation::zeroFlag = 0;
    int MathOperation::compareFlag = 0;
    bool debugOperations = false;

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

    void MathOperation::Add(Instruction* instruction, byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType, byte* registers, byte* assemblyData)
    {
        if(debugOperations)
            std::cout << "ADD: LHS type " << (int)lhsDataType << " RHS type " << (int)rhsDataType << std::endl;

        switch(lhsDataType)
        {
            case Type::Double:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<double*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }                                                                           
            case Type::Int64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Pointer:
            {
                break;
            }
            case Type::Single:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<float*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Add(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
        }            
    }

    void MathOperation::Subtract(Instruction* instruction, byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType, byte* registers, byte* assemblyData)
    {
        if(debugOperations)
            std::cout << "SUB: LHS type " << (int)lhsDataType << " RHS type " << (int)rhsDataType << std::endl;

        switch(lhsDataType)
        {
            case Type::Double:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<double*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }                                                                           
            case Type::Int64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Pointer:
            {
                break;
            }
            case Type::Single:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<float*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Subtract(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
        }            
    }

    void MathOperation::Multiply(Instruction* instruction, byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType, byte* registers, byte* assemblyData)
    {
        if(debugOperations)
            std::cout << "MUL: LHS type " << (int)lhsDataType << " RHS type " << (int)rhsDataType << std::endl;

        switch(lhsDataType)
        {
            case Type::Double:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<double*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }                                                                           
            case Type::Int64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Pointer:
            {
                break;
            }
            case Type::Single:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<float*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Multiply(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
        }            
    }

    void MathOperation::Divide(Instruction* instruction, byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType, byte* registers, byte* assemblyData)
    {
        if(debugOperations)
            std::cout << "DIV: LHS type " << (int)lhsDataType << " RHS type " << (int)rhsDataType << std::endl;

        switch(lhsDataType)
        {
            case Type::Double:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<double*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }                                                                           
            case Type::Int64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Pointer:
            {
                break;
            }
            case Type::Single:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<float*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        MathOperation::Divide(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
        }            
    }

    void MathOperation::Compare(Instruction* instruction, byte* lhs, byte* rhs, Type lhsDataType, Type rhsDataType, byte* registers, byte* assemblyData)
    {
        if(debugOperations)
            std::cout << "CMP: LHS type " << (int)lhsDataType << " RHS type " << (int)rhsDataType << std::endl;

        int64_t result = 0;

        switch(lhsDataType)
        {
            case Type::Double:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<double*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<int16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<int32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }                                                                           
            case Type::Int64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<int64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Int8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
            case Type::Pointer:
            {
                break;
            }
            case Type::Single:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<float*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt16:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<uint16_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt32:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<uint32_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt64:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<uint64_t*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }               
            case Type::UInt8:
            {
                switch(rhsDataType)
                {
                    case Type::Double:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<double*>(rhs));
                        break;
                    case Type::Int16:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int16_t*>(rhs));
                        break;
                    case Type::Int32:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int32_t*>(rhs));
                        break;
                    case Type::Int64:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<int64_t*>(rhs));
                        break;       
                    case Type::Int8:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<char*>(rhs));
                        break;      
                    case Type::Pointer:
                        break;
                    case Type::Single:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<float*>(rhs));
                        break;        
                    case Type::UInt16:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint16_t*>(rhs));
                        break;       
                    case Type::UInt32:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint32_t*>(rhs));
                        break;        
                    case Type::UInt64:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<uint64_t*>(rhs));
                        break;                            
                    case Type::UInt8:
                        result = MathOperation::Compare(reinterpret_cast<unsigned char*>(lhs), reinterpret_cast<unsigned char*>(rhs));
                        break;                                                                                                                                                                                                                                                                                                                                                         
                }
                break;
            }
        }  

        if(result == 0)
            compareFlag = 0;
        else if(result < 0)
            compareFlag = -1;
        else
            compareFlag = 1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
    //Add
    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////

    void MathOperation::Add(unsigned char* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(unsigned char* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "unsigned char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(char* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint16_t* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int16_t* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint32_t* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int32_t* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(uint64_t* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "uint64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(int64_t* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "int64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(float* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "float" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, unsigned char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, char* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, uint16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, int16_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, uint32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, int32_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, uint64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, int64_t* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, float* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Add(double* lhs, double* rhs)
    {
	    *lhs += *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Add" << " " << "double" << "," << "double" << " " << *lhs << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
    //Subtract
    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////

    void MathOperation::Subtract(unsigned char* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(unsigned char* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "unsigned char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(char* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint16_t* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int16_t* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint32_t* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int32_t* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(uint64_t* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "uint64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(int64_t* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "int64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(float* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "float" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, unsigned char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, char* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, uint16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, int16_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, uint32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, int32_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, uint64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, int64_t* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, float* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Subtract(double* lhs, double* rhs)
    {
	    *lhs -= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Subtract" << " " << "double" << "," << "double" << " " << *lhs << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
    //Multiply
    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////

    void MathOperation::Multiply(unsigned char* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(unsigned char* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "unsigned char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(char* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint16_t* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int16_t* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint32_t* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int32_t* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(uint64_t* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "uint64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(int64_t* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "int64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(float* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "float" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, unsigned char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, char* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, uint16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, int16_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, uint32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, int32_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, uint64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, int64_t* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, float* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Multiply(double* lhs, double* rhs)
    {
	    *lhs *= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Multiply" << " " << "double" << "," << "double" << " " << *lhs << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
    //Divide
    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////

    void MathOperation::Divide(unsigned char* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(unsigned char* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "unsigned char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(char* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "char" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint16_t* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int16_t* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int16_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint32_t* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int32_t* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int32_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(uint64_t* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "uint64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(int64_t* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "int64_t" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(float* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "float" << "," << "double" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, unsigned char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "unsigned char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, char* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "char" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, uint16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "uint16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, int16_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "int16_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, uint32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "uint32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, int32_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "int32_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, uint64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "uint64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, int64_t* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "int64_t" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, float* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "float" << " " << *lhs << std::endl;
    }

    void MathOperation::Divide(double* lhs, double* rhs)
    {
	    *lhs /= *rhs;
		zeroFlag = *lhs == 0 ? 1 : 0;
	    if(debugOperations)
		    std::cout << "Divide" << " " << "double" << "," << "double" << " " << *lhs << std::endl;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(unsigned char* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "unsigned char" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(char* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "char" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint16_t* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint16_t" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int16_t* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int16_t" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint32_t* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint32_t" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int32_t* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int32_t" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(uint64_t* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "uint64_t" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(int64_t* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "int64_t" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(float* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "float" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, unsigned char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "unsigned char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, char* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "char" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, uint16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "uint16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, int16_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "int16_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, uint32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "uint32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, int32_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "int32_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, uint64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "uint64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, int64_t* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "int64_t" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, float* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "float" << " " << *lhs << std::endl;
		return result;
    }

    int64_t MathOperation::Compare(double* lhs, double* rhs)
    {
	    int64_t result = (*lhs - *rhs);

	    if(debugOperations)
		    std::cout << "Compare" << " " << "double" << "," << "double" << " " << *lhs << std::endl;
		return result;
    }
}