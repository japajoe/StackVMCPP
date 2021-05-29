#ifndef STACKVM_VIRTUALMACHINE_HPP
#define STACKVM_VIRTUALMACHINE_HPP

#include <cstdint>
#include <vector>
#include <chrono>
#include <functional>
#include "Specification.hpp"
#include "Assembly.hpp"
#include "Instruction.hpp"
#include "Stack.hpp"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

typedef high_resolution_clock::time_point TimePoint;

namespace StackVM
{
    class VirtualMachine
    {
    private:
        Stack<byte> stack;
        std::vector<byte> registers;
        Type registerDataType[13];
        Assembly* assembly;
        Instruction* program;
        Instruction* currentInstruction;
        Instruction* entryInstruction;
        int32_t zeroFlag;
        int32_t compareFlag;
        TimePoint startTime;
        TimePoint endTime;
        int32_t elapsedTime;
        byte* GetLeftOperandPointer(Instruction* instruction);
        byte* GetRightOperandPointer(Instruction* instruction);
        Type GetLeftOperandDataType(Instruction* instruction);
        Type GetRightOperandDataType(Instruction* instruction);
        int32_t GetSourceRegisterIndex(Instruction* instruction);
        int32_t GetDestinationRegisterIndex(Instruction* instruction);        
        void SetDestinationRegisterDataType(Instruction* instruction, Type type);
        void ResetState();
        void LogMessage(const std::string& message);

        template<typename T>
        T* GetLeftOperandPointerType(Instruction* instruction)
        {
            byte* ptr = nullptr;

            switch(instruction->lhsOperandType)
            {
                case OperandType::IntegerLiteral:
                    ptr = &instruction->lhs[0];
                    break;
                case OperandType::Register:
                    ptr = &registers[0] + (instruction->GetLeftValue<int32_t>() * (sizeof(byte) * 8));
                    break;
                case OperandType::Variable:
                    ptr = &assembly->data[0] + (instruction->GetLeftValue<int32_t>() * (sizeof(byte) * 8));
                    break;
            }
            
            return reinterpret_cast<T*>(ptr);
        }

        template<typename T>
        T* GetRightOperandPointerType(Instruction* instruction)
        {
            byte* ptr = nullptr;

            switch(instruction->rhsOperandType)
            {
                case OperandType::IntegerLiteral:
                    ptr = &instruction->rhs[0];
                    break;
                case OperandType::Register:
                    ptr = &registers[0] + (instruction->GetRightValue<int32_t>() * (sizeof(byte) * 8));
                    break;
                case OperandType::Variable:
                    ptr = &assembly->data[0] + (instruction->GetRightValue<int32_t>() * (sizeof(byte) * 8));
                    break;
            }
            
            return reinterpret_cast<T*>(ptr);
        }

        Type GetRegisterDataType(Instruction* instruction) const;

    public:
        VirtualMachine();
        bool LoadProgram(Assembly* assembly);
        bool Execute();
        void Stop();
    };
}
#endif