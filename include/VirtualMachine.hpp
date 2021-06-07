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
        Instruction* currentInstruction;
        Instruction* entryInstruction;
        TimePoint startTime;
        TimePoint endTime;
        int32_t elapsedTime;
        byte* GetLeftOperandPointer(Instruction* instruction);
        byte* GetRightOperandPointer(Instruction* instruction);
        Type GetLeftOperandDataType(Instruction* instruction) const;
        Type GetRightOperandDataType(Instruction* instruction) const;
        uint16_t GetSizeOfType(Type type) const;
        int32_t GetDestinationRegisterIndex(Instruction* instruction) const;        
        void SetDestinationRegisterDataType(Instruction* instruction, Type type);
        void IncrementInstructionPointer();
        void IncrementInstructionPointer(uint64_t offset);
        void SetInstructionPointer(uint64_t offset);
        void ResetState();
        void LogMessage(const std::string& message);
    public:
        VirtualMachine();
        bool LoadProgram(Assembly* assembly);
        bool Execute();
        void Stop();
    };
}
#endif