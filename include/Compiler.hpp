#ifndef STACKVM_COMPILER_HPP
#define STACKVM_COMPILER_HPP

#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include "Instruction.hpp"
#include "Assembly.hpp"
#include "Specification.hpp"

namespace StackVM
{
    enum class DefineDirective : uint8_t
    {
        DB = 1,
        DW = 2,
        DD = 4,
        DQ = 8
    };

    enum class CompileStage
    {
        Begin,
        End,
        ProcessData,
        ProcessLabel,
        ProcessText
    };

    struct LineInfo
    {
        std::string text;
        size_t lineNumber;

        LineInfo(const std::string& text, size_t lineNumber)
        {
            this->text =text;
            this->lineNumber = lineNumber;
        }
    };

    struct PotentialLabel
    {
        int32_t instructionIndex;
        int32_t dataIndex;
        std::string labelText;
        int32_t operandIndex;
        int32_t lineNumber;

        PotentialLabel(int32_t instructionIndex, int32_t dataIndex, const std::string& labelText, int32_t operandIndex, int32_t lineNumber)
        {
            this->instructionIndex = instructionIndex;
            this->dataIndex = dataIndex;
            this->labelText = labelText;
            this->operandIndex = operandIndex;
            this->lineNumber = lineNumber;
        }
    };    

    class Compiler
    {
    public:
        Compiler();
        bool Compile(const std::string& source, Assembly& assembly);
    private:
        std::map<std::string, OpCodeInfo> opcodeInfoMap;
        std::map<std::string, uint32_t> registerMap;
        std::map<std::string, DefineDirective> directivesMap;
        void RemoveWhiteSpace(std::vector<LineInfo>& lines);
        void RemoveEmptyLines(std::vector<LineInfo>& lines);
        void RemoveCommentLines(std::vector<LineInfo>& lines);
        void RemoveTrailingComments(std::vector<LineInfo>& lines);
        void Dump(const std::vector<LineInfo>& lines);
        bool ProcessData(const std::vector<LineInfo>& lines, size_t offset, Assembly* assembly, std::map<std::string,uint32_t>& dataMap);
        bool ProcessLabels(std::vector<LineInfo>& lines, size_t offset, Assembly* assembly, std::map<std::string,uint32_t>& labelMap);
        bool ProcessText(const std::vector<LineInfo>& lines, size_t offset, Assembly* assembly, std::map<std::string,uint32_t>& labelMap, std::map<std::string,uint32_t>& dataMap);
        bool ProcessOneOperandInstruction(const LineInfo& line, OpCode opcode, const std::string operandText, Assembly* assembly, std::map<std::string,uint32_t>& labelMap, std::map<std::string,uint32_t>& dataMap);
        bool ProcessTwoOperandInstruction(const LineInfo& line, OpCode opcode, const std::string operandTextLHS, const std::string operandTextRHS, Assembly* assembly, std::map<std::string,uint32_t>& labelMap, std::map<std::string,uint32_t>& dataMap);
        bool ParseValueFromDirective(const std::string& text, size_t lineNumber, DefineDirective d, unsigned char* buffer, Type& type);
        Type GetNumberTypeFromText(const std::string& text);
        void LogMessage(const std::string& message);
    };
};

#endif