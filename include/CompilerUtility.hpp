#ifndef STACKVM_COMPILEUTILITY_HPP
#define STACKVM_COMPILEUTILITY_HPP

#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include "Instruction.hpp"
#include "Assembly.hpp"
#include "Specification.hpp"
#include "StringUtility.hpp"

namespace StackVM
{
    enum class TokenType
    {
        OPCODE,
        DIRECTIVE_SPECIFIER,
        FUNCTION_LABEL,
        VARIABLE_LABEL,
        INTEGER_LITERAL,
        CHARACTER_LITERAL,        
        OPERAND
    };

    class Token
    {
    public:
        TokenType type;
        std::string text;
        size_t lineNumber;

        Token(TokenType type, const std::string& text, size_t lineNumber)
        {
            this->type = type;
            this->text = text;
            this->lineNumber = lineNumber;
        }
    };

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

    class CompilerUtility
    {
    private:
        static bool isInitialized;
        static void WriteError(int lineNumber, const std::string& error);
    public:
        static std::map<std::string, OpCodeInfo> opcodeInfoMap;
        static std::map<std::string, uint32_t> registerMap;
        static std::map<std::string, DefineDirective> directivesMap;
        static void Initialize();
        static bool Tokenize(const std::vector<LineInfo>& lines, std::vector<Token>& tokens);
        static void RemoveWhiteSpace(std::vector<LineInfo>& lines);
        static void RemoveEmptyLines(std::vector<LineInfo>& lines);
        static void RemoveCommentLines(std::vector<LineInfo>& lines);
        static void RemoveTrailingComments(std::vector<LineInfo>& lines);
        static Type GetNumberTypeFromText(const std::string& text);
        static bool IsDirectiveToken(const std::string& text);
        static bool IsRegisterLabelToken(const std::string& text);
        static bool IsFunctionLabelToken(const std::string& text);
        static bool IsVariableLabelToken(const std::string& text);
        static bool IsOpCodeToken(const std::string& text);
        static bool IsIntegerLiteralToken(const std::string& text);
        static bool LineHasVariableDeclaration(const std::string& text);
        static bool LineHasFunctionDeclaration(const std::string& text);
        static int WriteStringValueToBuffer(const std::string& text, byte* buffer, Type type);
        static bool NumberIsSigned(const std::string& text);
        
    };
};

#endif