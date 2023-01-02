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
        size_t capacity;
        size_t typeIndex;
        T* buffer;
        Type* types;

        void increment_pointer()
        {
            sp += 8;
            typeIndex++;
        }

        void decrement_pointer()
        {
            sp -= 8;
            typeIndex--;
        }

        void set_type(Type type, size_t index)
        {
            types[index] = type;
        }

    public:
        Stack()
        {
            this->sp = 0;
            this->typeIndex = 0;
            this->capacity = 1024 * 1024;
            this->buffer = new T[capacity];
            this->types = new Type[capacity / 8];
            memset(buffer, 0, capacity * sizeof(T));
            memset(buffer, 0, capacity / 8);
        }
        Stack(size_t length)
        {
            this->sp = 0;
            this->typeIndex = 0;
            this->capacity = length;
            this->buffer = new T[length];
            this->types = new Type[length / 8];
            memset(buffer, 0, length * sizeof(T));
            memset(buffer, 0, length / 8);
        }

        ~Stack()
        {
            if(buffer != nullptr)
            {
                delete[] buffer;
                buffer = nullptr;
            }
            if(types != nullptr)
            {
                delete[] types;
                types = nullptr;
            }            
        }

        bool is_stack_overflow() const
        {
            return sp >= capacity;
        }

        bool is_stack_underflow() const
        {
            return sp < 8;
        }

        bool push(unsigned char* value, Type type)
        {
            if (is_stack_overflow())
                return false;

            switch(type)
            {
                case Type::String:
                    memcpy(&buffer[sp], &value, sizeof(void*));
                    break;
                case Type::Double:
                    memcpy(&buffer[sp], value, sizeof(double));
                    break;
                case Type::Int16:
                    memcpy(&buffer[sp], value, sizeof(int16_t));
                    break;
                case Type::Int32:
                    memcpy(&buffer[sp], value, sizeof(int32_t));
                    break;
                case Type::Int64:
                    memcpy(&buffer[sp], value, sizeof(int64_t));
                    break;       
                case Type::Int8:
                    memcpy(&buffer[sp], value, sizeof(char));
                    break;      
                case Type::Single:
                    memcpy(&buffer[sp], value, sizeof(float));
                    break;        
                case Type::UInt16:
                    memcpy(&buffer[sp], value, sizeof(uint16_t));
                    break;       
                case Type::UInt32:
                    memcpy(&buffer[sp], value, sizeof(uint32_t));
                    break;
                case Type::UInt64:
                    memcpy(&buffer[sp], value, sizeof(uint64_t));
                    break;                            
                case Type::UInt8:
                    memcpy(&buffer[sp], value, sizeof(unsigned char));
                    break;
                default:
                    return false;
            }

            set_type(type, typeIndex);
            increment_pointer();

            return true;
        }

        bool push_char(char value)
        {
            if (is_stack_overflow())
                return false;
            memcpy(&buffer[sp], &value, sizeof(char));
            set_type(Type::Int8, typeIndex);
            increment_pointer();
            return true;
        }

        bool push_int16(int16_t value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(int16_t));
            set_type(Type::Int16, typeIndex);
            increment_pointer();
            return true;
        }

        bool push_int32(int32_t value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(int32_t));
            set_type(Type::Int32, typeIndex);
            increment_pointer();
            return true;
        }        

        bool push_int64(int64_t value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(int64_t));
            set_type(Type::Int64, typeIndex);
            increment_pointer();
            return true;
        }

        bool push_uchar(unsigned char value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(unsigned char));
            set_type(Type::UInt8, typeIndex);
            increment_pointer();
            return true;
        }

        bool push_uint16(uint16_t value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(uint16_t));
            set_type(Type::UInt16, typeIndex);
            increment_pointer();
            return true;
        }

        bool push_uint32(uint32_t value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(uint32_t));
            set_type(Type::UInt32, typeIndex);
            increment_pointer();
            return true;
        }        

        bool push_uint64(uint64_t value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(uint64_t));
            set_type(Type::UInt64, typeIndex);
            increment_pointer();
            return true;
        }

        bool push_float(float value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(float));
            set_type(Type::Single, typeIndex);
            increment_pointer();
            return true;
        }        

        bool push_double(double value)
        {
            if (is_stack_overflow())
                return false;            
            memcpy(&buffer[sp], &value, sizeof(double));
            set_type(Type::Double, typeIndex);
            increment_pointer();
            return true;
        }

        bool pop()
        {
            if(is_stack_underflow())
                return false;
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;                
        }

        bool pop_bytes(unsigned char* value)
        {
            if(is_stack_underflow())
                return false;
            value = &buffer[sp - 8];
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }

        bool pop_char(char& value)
        {
            if(is_stack_underflow())
                return false;            
            value = *(char*)&buffer[sp - 8];
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }

        bool pop_int16(int16_t& value)
        {
            if(is_stack_underflow())
                return false;  
            memcpy(&value, &buffer[sp - 8], sizeof(int16_t));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }

        bool pop_int32(int32_t& value)
        {
            if(is_stack_underflow())
                return false;              
            memcpy(&value, &buffer[sp - 8], sizeof(int32_t));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }        

        bool pop_int64(int64_t& value)
        {
            if(is_stack_underflow())
                return false;            
            memcpy(&value, &buffer[sp - 8], sizeof(int64_t));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }

        bool pop_uchar(unsigned char& value)
        {
            if(is_stack_underflow())
                return false;              
            memcpy(&value, &buffer[sp - 8], sizeof(unsigned char));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }

        bool pop_uint16(uint16_t& value)
        {
            if(is_stack_underflow())
                return false;              
            memcpy(&value, &buffer[sp - 8], sizeof(uint16_t));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }

        bool pop_uint32(uint32_t& value)
        {
            if(is_stack_underflow())
                return false;
            memcpy(&value, &buffer[sp - 8], sizeof(uint32_t));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }        

        bool pop_uint64(uint64_t& value)
        {
            if(is_stack_underflow())
                return false;            
            memcpy(&value, &buffer[sp - 8], sizeof(uint64_t));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }       

        bool pop_float(float& value)
        {
            if(is_stack_underflow())
                return false;              
            memcpy(&value, &buffer[sp - 8], sizeof(float));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }        

        bool pop_double(double& value)
        {
            if(is_stack_underflow())
                return false;                
            memcpy(&value, &buffer[sp - 8], sizeof(double));
            set_type(Type::Undefined, typeIndex - 1);
            decrement_pointer();
            return true;
        }
        
        template<typename U>
        bool try_pop(U& value)
        {
            Type type = get_top_type();

            switch(type)
            {
                case Type::String:
                    return false;
                case Type::Double:
                {
                    double v;
                    if (!pop_double(v))
                        return false;                    
                    value = static_cast<U>(v);
                    break;
                }
                case Type::Int16:
                {
                    int16_t v;
                    if (!pop_int16(v))
                        return false;
                    value = static_cast<U>(v);
                    break;
                }
                case Type::Int32:
                {
                    int32_t v;
                    if (!pop_int32(v))
                        return false;
                    value = static_cast<U>(v);
                    break;
                }
                case Type::Int64:
                {
                    int64_t v;
                    if (!pop_int64(v))
                        return false;                    
                    value = static_cast<U>(v);                    
                    break;
                }
                case Type::Int8:
                {
                    char v;
                    if (!pop_char(v))
                        return false;                    
                    value = static_cast<U>(v);                    
                    break;      
                }
                case Type::Single:
                {
                    float v;
                    if (!pop_float(v))
                        return false;                    
                    value = static_cast<U>(v);                         
                    break;        
                }
                case Type::UInt16:
                {
                    uint16_t v;
                    if (!pop_uint16(v))
                        return false;                    
                    value = static_cast<U>(v);                      
                    break;       
                }
                case Type::UInt32:
                {
                    uint32_t v;
                    if (!pop_uint32(v))
                        return false;                    
                    value = static_cast<U>(v);                                          
                    break;
                }
                case Type::UInt64:
                {
                    uint64_t v;
                    if (!pop_uint64(v))
                        return false;                    
                    value = static_cast<U>(v);                                                              
                    break;                            
                }
                case Type::UInt8:
                {
                    unsigned char v;
                    if (!pop_uchar(v))
                        return false;                    
                    value = static_cast<U>(v);                       
                    break;
                }
                default:
                    return false;
            }

            return true;
        }
        
        bool try_pop_as_string(std::string& str)
        {
            Type type = get_top_type();

            switch(type)
            {
                case Type::String:
                    return false;
                case Type::Double:
                {
                    double value;
                    if(!pop_double(value))
                        return false;                    
                    str = std::to_string(value);
                    break;
                }
                case Type::Int16:
                {
                    int16_t value;
                    if(!pop_int16(value))
                        return false;
                    str = std::to_string(value);
                    break;
                }
                case Type::Int32:
                {
                    int32_t value;
                    if(!pop_int32(value))
                        return false;
                    str = std::to_string(value);
                    break;
                }
                case Type::Int64:
                {
                    int64_t value;
                    if(!pop_int64(value))
                        return false;                    
                    str = std::to_string(value);
                    break;
                }
                case Type::Int8:
                {
                    char value;
                    if(!pop_char(value))
                        return false;
                    str = std::to_string(value);
                    break;
                }
                case Type::Single:
                {
                    float value;
                    if(!pop_float(value))
                        return false;                    
                    str = std::to_string(value);
                    break;
                }
                case Type::UInt16:
                {
                    uint16_t value;
                    if(!pop_uint16(value))
                        return false;                       
                    str = std::to_string(value);
                    break;       
                }
                case Type::UInt32:
                {
                    uint32_t value;
                    if(!pop_uint32(value))
                        return false;                       
                    str = std::to_string(value);
                    break;
                }
                case Type::UInt64:
                {
                    uint64_t value;
                    if(!pop_uint64(value))
                        return false;
                    str = std::to_string(value);
                    break;                            
                }
                case Type::UInt8:
                {
                    unsigned char value;
                    if(!pop_uchar(value))
                        return false;                    
                    str = std::to_string(value);
                    break;
                }
                default:
                    return false;
            }

            return true;
        }        

        Type get_top_type()
        {
            if(typeIndex < 1)
                return Type::Undefined;
            return types[typeIndex-1];
        }

        bool check_type(Type type, int64_t index)
        {
            uint64_t i = sp + index;

            if(i < 0 || i > ((capacity / 8) - 1))
                return false;

            return types[i] == type;
        }

        template<typename ...Param>
        bool check_types_top_to_bottom(const Param& ... param)
        {
            int64_t i = 0;

            for(const auto p : {param...}) 
            {
                int64_t index = 0 - (i+1);

                Type type = static_cast<Type>(p);

                if(!check_type(type, index))
                {
                    return false;
                }

                i++;
            }        

            return true;
        }

        template<typename ...Param>
        bool check_types_bottom_to_top(const Param& ... param)
        {
            const std::size_t nArgs = sizeof...(Param);

            int64_t i = nArgs - 1;

            for(const auto p : {param...}) 
            {
                int64_t index = 0 - (i+1);

                Type type = static_cast<Type>(p);

                if(!check_type(type, index))
                {
                    return false;
                }

                i--;
            }        

            return true;
        }

        void clear()
        {
            sp = 0;
            typeIndex = 0;
        }

        size_t get_capacity() const
        {
            return this->capacity;
        }

        size_t get_size() const
        {
            this->sp > 0 ? this->sp / 8 : 0;
            return this->sp / 8;
        }
    };

    //Old code below, will get removed at some point

    // template<typename T>
    // class Stack
    // {
    // private:
    //     size_t sp;
    //     size_t length;
    //     T* buffer;
    // public:
    //     Stack()
    //     {
    //         sp = 0;
    //         length = 1024 * 1024;
    //         buffer = new T[length];
    //         memset(buffer, 0, length * sizeof(T));
    //     }
    //     Stack(size_t length)
    //     {
    //         this->sp = 0;
    //         this->length = length;
    //         this->buffer = new T[length];
    //         memset(buffer, 0, length * sizeof(T));
    //     }

    //     ~Stack()
    //     {
    //         if(buffer != nullptr)
    //         {
    //             delete[] buffer;
    //             buffer = nullptr;
    //         }
    //     }

    //     template<typename U>
    //     void push_from_type(unsigned char* value)
    //     {
    //         memcpy(&buffer[sp], value, sizeof(U));
    //         sp += sizeof(U);
    //     }

    //     void push(unsigned char* value, Type type)
    //     {
    //         switch(type)
    //         {
    //             case Type::Double:
    //                 memcpy(&buffer[sp], value, sizeof(double));
    //                 sp += sizeof(double);
    //                 break;
    //             case Type::Int16:
    //                 memcpy(&buffer[sp], value, sizeof(int16_t));
    //                 sp += sizeof(int16_t);
    //                 break;
    //             case Type::Int32:
    //                 memcpy(&buffer[sp], value, sizeof(int32_t));
    //                 sp += sizeof(int32_t);
    //                 break;
    //             case Type::Int64:
    //                 memcpy(&buffer[sp], value, sizeof(int64_t));
    //                 sp += sizeof(int64_t);
    //                 break;       
    //             case Type::Int8:
    //                 memcpy(&buffer[sp], value, sizeof(char));
    //                 sp += sizeof(char);                   
    //                 break;      
    //             case Type::Single:
    //                 memcpy(&buffer[sp], value, sizeof(float));
    //                 sp += sizeof(float);           
    //                 break;        
    //             case Type::UInt16:
    //                 memcpy(&buffer[sp], value, sizeof(uint16_t));
    //                 sp += sizeof(uint16_t);                 
    //                 break;       
    //             case Type::UInt32:
    //                 memcpy(&buffer[sp], value, sizeof(uint32_t));
    //                 sp += sizeof(uint32_t);
    //                 break;
    //             case Type::UInt64:
    //                 memcpy(&buffer[sp], value, sizeof(uint64_t));
    //                 sp += sizeof(uint64_t);       
    //                 break;                            
    //             case Type::UInt8:
    //                 memcpy(&buffer[sp], value, sizeof(unsigned char));
    //                 sp += sizeof(unsigned char);
    //                 break;
    //             default:
    //                 break;                                                                                                                                                                                                                                                                                                                                                                       
    //         }
    //     }

    //     void push_bytes(unsigned char* value)
    //     {
    //         memcpy(&buffer[sp], value, 8);
    //         sp += 8;
    //     }

    //     void push_char(const char& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(char));
    //         sp += sizeof(char);
    //     }

    //     void push_int16(const int16_t& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(int16_t));
    //         sp += sizeof(int16_t);
    //     }

    //     void push_int32(const int32_t& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(int32_t));
    //         sp += sizeof(int32_t);
    //     }        

    //     void push_int64(const int64_t& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(int64_t));
    //         sp += sizeof(int64_t);
    //     }

    //     void push_uchar(const unsigned char& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(unsigned char));
    //         sp += sizeof(unsigned char);
    //     }

    //     void push_uint16(const uint16_t& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(uint16_t));
    //         sp += sizeof(uint16_t);
    //     }

    //     void push_uint32(const uint32_t& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(uint32_t));
    //         sp += sizeof(uint32_t);
    //     }        

    //     void push_uint64(const uint64_t& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(uint64_t));
    //         sp += sizeof(uint64_t);
    //     }        

    //     void push_pointer(void* value)
    //     {
    //         memcpy(&buffer[sp], value, sizeof(void*));
    //         sp += sizeof(void*);
    //     }        

    //     void push_float(const float& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(float));
    //         sp += sizeof(float);
    //     }        

    //     void push_double(const double& value)
    //     {
    //         memcpy(&buffer[sp], &value, sizeof(double));
    //         sp += sizeof(double);
    //     }

    //     unsigned char* pop_bytes()
    //     {
    //         unsigned char* value = &buffer[sp - 8];
    //         sp -= 8;
    //         return value;
    //     }

    //     char pop_char()
    //     {
    //         //char value;
    //         char value = *(char*)&buffer[sp - sizeof(char)];
    //         //memcpy(&value, &buffer[sp - sizeof(char)], sizeof(char));
    //         sp -= sizeof(char);
    //         return value;
    //     }

    //     int16_t pop_int16()
    //     {
    //         int16_t value;
    //         memcpy(&value, &buffer[sp - sizeof(int16_t)], sizeof(int16_t));
    //         sp -= sizeof(int16_t);
    //         return value;
    //     }

    //     int32_t pop_int32()
    //     {
    //         int32_t value;
    //         memcpy(&value, &buffer[sp - sizeof(int32_t)], sizeof(int32_t));
    //         sp -= sizeof(int32_t);
    //         return value;
    //     }        

    //     int64_t pop_int64()
    //     {
    //         int64_t value;
    //         memcpy(&value, &buffer[sp - sizeof(int64_t)], sizeof(int64_t));
    //         sp -= sizeof(int64_t);
    //         return value;
    //     }

    //     unsigned char pop_uchar()
    //     {
    //         unsigned char value;
    //         memcpy(&value, &buffer[sp - sizeof(unsigned char)], sizeof(unsigned char));
    //         sp -= sizeof(unsigned char);
    //         return value;
    //     }

    //     uint16_t pop_uint16()
    //     {
    //         uint16_t value;
    //         memcpy(&value, &buffer[sp - sizeof(uint16_t)], sizeof(uint16_t));
    //         sp -= sizeof(uint16_t);
    //         return value;
    //     }

    //     uint32_t pop_uint32()
    //     {
    //         uint32_t value;
    //         memcpy(&value, &buffer[sp - sizeof(uint32_t)], sizeof(uint32_t));
    //         sp -= sizeof(uint32_t);
    //         return value;
    //     }        

    //     uint64_t pop_uint64()
    //     {
    //         uint64_t value;
    //         memcpy(&value, &buffer[sp - sizeof(uint64_t)], sizeof(uint64_t));
    //         sp -= sizeof(uint64_t);
    //         return value;
    //     }

    //     void* pop_pointer()
    //     {
    //         void* value;
    //         memcpy(value, &buffer[sp - sizeof(void*)], sizeof(void*));
    //         sp -= sizeof(void*);
    //         return value;
    //     }        

    //     float pop_float()
    //     {
    //         float value;
    //         memcpy(&value, &buffer[sp - sizeof(float)], sizeof(float));
    //         sp -= sizeof(float);
    //         return value;
    //     }        

    //     double pop_double()
    //     {
    //         double value = 0;
    //         memcpy(&value, &buffer[sp - sizeof(double)], sizeof(double));
    //         sp -= sizeof(double);
    //         return value;
    //     }               

    //     void set_pointer(int32_t index)
    //     {
    //         sp = index;
    //     }

    //     void clear()
    //     {
    //         sp = 0;
    //     }

    //     size_t capacity() const
    //     {
    //         return this->length;
    //     }

    //     size_t size() const
    //     {
    //         return this->sp;
    //     }

    //     size_t getPointer() const
    //     {
    //         if(sp)
    //             return (this->sp - 1);
    //         return 0;
    //     }
    // };        
}
#endif