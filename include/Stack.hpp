#ifndef STACKVM_STACK_HPP
#define STACKVM_STACK_HPP

#include <cstring>
#include <cstdint>
#include <iostream>
#include "Specification.hpp"

namespace StackVM
{
    template<typename T>
    class Stack
    {
    private:
        size_t sp;
        size_t length;
        T* buffer;
    public:
        Stack()
        {
            sp = 0;
            length = 1024 * 1024;
            buffer = new T[length];
            memset(buffer, 0, length * sizeof(T));
        }
        Stack(size_t length)
        {
            this->sp = 0;
            this->length = length;
            this->buffer = new T[length];
            memset(buffer, 0, length * sizeof(T));
        }

        ~Stack()
        {
            if(buffer != nullptr)
            {
                delete[] buffer;
                buffer = nullptr;
            }
        }

        template<typename U>
        void push_from_type(unsigned char* value)
        {
            memcpy(&buffer[sp], value, sizeof(U));
            sp += sizeof(U);
        }

        void push(unsigned char* value, Type type)
        {
            switch(type)
            {
                case Type::Double:
                    memcpy(&buffer[sp], value, sizeof(double));
                    sp += sizeof(double);
                    break;
                case Type::Int16:
                    memcpy(&buffer[sp], value, sizeof(int16_t));
                    sp += sizeof(int16_t);
                    break;
                case Type::Int32:
                    memcpy(&buffer[sp], value, sizeof(int32_t));
                    sp += sizeof(int32_t);
                    break;
                case Type::Int64:
                    memcpy(&buffer[sp], value, sizeof(int64_t));
                    sp += sizeof(int64_t);
                    break;       
                case Type::Int8:
                    memcpy(&buffer[sp], value, sizeof(char));
                    sp += sizeof(char);                   
                    break;      
                case Type::Single:
                    memcpy(&buffer[sp], value, sizeof(float));
                    sp += sizeof(float);           
                    break;        
                case Type::UInt16:
                    memcpy(&buffer[sp], value, sizeof(uint16_t));
                    sp += sizeof(uint16_t);                 
                    break;       
                case Type::UInt32:
                    memcpy(&buffer[sp], value, sizeof(uint32_t));
                    sp += sizeof(uint32_t);
                    break;
                case Type::UInt64:
                    memcpy(&buffer[sp], value, sizeof(uint64_t));
                    sp += sizeof(uint64_t);       
                    break;                            
                case Type::UInt8:
                    memcpy(&buffer[sp], value, sizeof(unsigned char));
                    sp += sizeof(unsigned char);
                    break;
                default:
                    break;                                                                                                                                                                                                                                                                                                                                                                       
            }
        }

        void push_bytes(unsigned char* value)
        {
            memcpy(&buffer[sp], value, 8);
            sp += 8;
        }

        void push_char(const char& value)
        {
            memcpy(&buffer[sp], &value, sizeof(char));
            sp += sizeof(char);
        }

        void push_int16(const int16_t& value)
        {
            memcpy(&buffer[sp], &value, sizeof(int16_t));
            sp += sizeof(int16_t);
        }

        void push_int32(const int32_t& value)
        {
            memcpy(&buffer[sp], &value, sizeof(int32_t));
            sp += sizeof(int32_t);
        }        

        void push_int64(const int64_t& value)
        {
            memcpy(&buffer[sp], &value, sizeof(int64_t));
            sp += sizeof(int64_t);
        }

        void push_uchar(const unsigned char& value)
        {
            memcpy(&buffer[sp], &value, sizeof(unsigned char));
            sp += sizeof(unsigned char);
        }

        void push_uint16(const uint16_t& value)
        {
            memcpy(&buffer[sp], &value, sizeof(uint16_t));
            sp += sizeof(uint16_t);
        }

        void push_uint32(const uint32_t& value)
        {
            memcpy(&buffer[sp], &value, sizeof(uint32_t));
            sp += sizeof(uint32_t);
        }        

        void push_uint64(const uint64_t& value)
        {
            memcpy(&buffer[sp], &value, sizeof(uint64_t));
            sp += sizeof(uint64_t);
        }        

        void push_pointer(void* value)
        {
            memcpy(&buffer[sp], value, sizeof(void*));
            sp += sizeof(void*);
        }        

        void push_float(const float& value)
        {
            memcpy(&buffer[sp], &value, sizeof(float));
            sp += sizeof(float);
        }        

        void push_double(const double& value)
        {
            memcpy(&buffer[sp], &value, sizeof(double));
            sp += sizeof(double);
        }

        unsigned char* pop_bytes()
        {
            unsigned char* value = &buffer[sp - 8];
            sp -= 8;
            return value;
        }

        char pop_char()
        {
            char value;
            memcpy(&value, &buffer[sp - sizeof(char)], sizeof(char));
            sp -= sizeof(char);
            return value;
        }

        int16_t pop_int16()
        {
            int16_t value;
            memcpy(&value, &buffer[sp - sizeof(int16_t)], sizeof(int16_t));
            sp -= sizeof(int16_t);
            return value;
        }

        int32_t pop_int32()
        {
            int32_t value;
            memcpy(&value, &buffer[sp - sizeof(int32_t)], sizeof(int32_t));
            sp -= sizeof(int32_t);
            return value;
        }        

        int64_t pop_int64()
        {
            int64_t value;
            memcpy(&value, &buffer[sp - sizeof(int64_t)], sizeof(int64_t));
            sp -= sizeof(int64_t);
            return value;
        }

        unsigned char pop_uchar()
        {
            unsigned char value;
            memcpy(&value, &buffer[sp - sizeof(unsigned char)], sizeof(unsigned char));
            sp -= sizeof(unsigned char);
            return value;
        }

        uint16_t pop_uint16()
        {
            uint16_t value;
            memcpy(&value, &buffer[sp - sizeof(uint16_t)], sizeof(uint16_t));
            sp -= sizeof(uint16_t);
            return value;
        }

        uint32_t pop_uint32()
        {
            uint32_t value;
            memcpy(&value, &buffer[sp - sizeof(uint32_t)], sizeof(uint32_t));
            sp -= sizeof(uint32_t);
            return value;
        }        

        uint64_t pop_uint64()
        {
            uint64_t value;
            memcpy(&value, &buffer[sp - sizeof(uint64_t)], sizeof(uint64_t));
            sp -= sizeof(uint64_t);
            return value;
        }

        void* pop_pointer()
        {
            void* value;
            memcpy(value, &buffer[sp - sizeof(void*)], sizeof(void*));
            sp -= sizeof(void*);
            return value;
        }        

        float pop_float()
        {
            float value;
            memcpy(&value, &buffer[sp - sizeof(float)], sizeof(float));
            sp -= sizeof(float);
            return value;
        }        

        double pop_double()
        {
            double value = 0;
            memcpy(&value, &buffer[sp - sizeof(double)], sizeof(double));
            sp -= sizeof(double);
            return value;
        }               

        void set_pointer(int32_t index)
        {
            sp = index;
        }

        void clear()
        {
            sp = 0;
        }

        size_t capacity() const
        {
            return this->length;
        }

        size_t size() const
        {
            return this->sp;
        }

        size_t getPointer() const
        {
            if(sp)
                return (this->sp - 1);
            return 0;
        }
    };
}
#endif