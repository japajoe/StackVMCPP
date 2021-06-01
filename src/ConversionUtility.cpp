#include "ConversionUtility.hpp"
#include <cstring>

namespace StackVM
{
    void ConversionUtility::CastSourceToDestinationType(byte* src, byte* dst, Type srcType, Type dstType)
    {
        switch(srcType)
        {
            case Type::Double:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        double vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        double vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        double vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        double vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        double vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        double vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        double vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        double vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        double vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<uint64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        double vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(double));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }
            case Type::Int16:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        int16_t vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        int16_t vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        int16_t vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        int16_t vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        int16_t vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        int16_t vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        int16_t vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        int16_t vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        int16_t vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<uint64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        int16_t vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(int16_t));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }
            case Type::Int32:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        int32_t vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        int32_t vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        int32_t vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        int32_t vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        int32_t vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        int32_t vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        int32_t vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        int32_t vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        int32_t vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<uint64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        int32_t vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(int32_t));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }                                                                           
            case Type::Int64:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        int64_t vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        int64_t vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        int64_t vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        int64_t vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        int64_t vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        int64_t vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        int64_t vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        int64_t vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        int64_t vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<uint64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        int64_t vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(int64_t));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }
            case Type::Int8:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        char vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        char vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        char vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        char vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        char vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        char vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        char vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        char vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        char vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<uint64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        char vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(char));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }
            case Type::Single:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        float vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        float vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        float vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        float vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        float vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        float vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        float vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        float vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        float vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<uint64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        float vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(float));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }               
            case Type::UInt16:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        uint16_t vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        uint16_t vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        uint16_t vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        uint16_t vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        uint16_t vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        uint16_t vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        uint16_t vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        uint16_t vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        uint16_t vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<uint64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        uint16_t vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(uint16_t));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }               
            case Type::UInt32:
            {

                break;
            }               
            case Type::UInt64:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        uint64_t vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        uint64_t vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        uint64_t vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        uint64_t vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        uint64_t vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        uint64_t vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        uint64_t vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        uint64_t vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        uint64_t vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        uint64_t vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(uint64_t));
                        vDst = static_cast<unsigned char>(vSrc);
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }               
            case Type::UInt8:
            {
                switch(dstType)
                {
                    case Type::Double:
                    {
                        unsigned char vSrc;
                        double vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<double>(vSrc);
                        memcpy(dst, &vDst, sizeof(double));
                        break;
                    }
                    case Type::Int16:
                    {
                        unsigned char vSrc;
                        int16_t vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<int16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int16_t));
                        break;
                    }
                    case Type::Int32:
                    {
                        unsigned char vSrc;
                        int32_t vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<int32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int32_t));
                        break;
                    }
                    case Type::Int64:
                    {
                        unsigned char vSrc;
                        int64_t vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<int64_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(int64_t));
                        break;       
                    }
                    case Type::Int8:
                    {
                        unsigned char vSrc;
                        char vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<char>(vSrc);
                        memcpy(dst, &vDst, sizeof(char));
                        break;
                    }
                    case Type::Single:
                    {
                        unsigned char vSrc;
                        float vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<float>(vSrc);
                        memcpy(dst, &vDst, sizeof(float));
                        break;        
                    }
                    case Type::UInt16:
                    {
                        unsigned char vSrc;
                        uint16_t vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<uint16_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint16_t));
                        break;       
                    }
                    case Type::UInt32:
                    {
                        unsigned char vSrc;
                        uint32_t vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = static_cast<uint32_t>(vSrc);
                        memcpy(dst, &vDst, sizeof(uint32_t));
                        break;        
                    }
                    case Type::UInt64:
                    {
                        unsigned char vSrc;
                        uint64_t vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(uint64_t));
                        break;                            
                    }
                    case Type::UInt8:
                    {
                        unsigned char vSrc;
                        unsigned char vDst;
                        memcpy(&vSrc, src, sizeof(unsigned char));
                        vDst = vSrc;
                        memcpy(dst, &vDst, sizeof(unsigned char));
                        break;                                    
                    }
                }
                break;
            }
        }
    }
}