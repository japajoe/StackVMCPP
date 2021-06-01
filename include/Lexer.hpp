#ifndef STACKVM_LEXER_HPP
#define STACKVM_LEXER_HPP

#include <string>
#include <vector>
#include <cstdint>

namespace StackVM
{
    enum class TokenType
    {
        Whitespace,
        NumberLiteral,
        CharacterLiteral,
        Colon,
        Comma,
        Period,
        Quote,
        Identifier,
        DataSection,
        TextSections
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

    class Lexer
    {
    public:
        std::vector<Token> CreateTokens(const std::string& source);
    private:
        static void RemoveWhiteSpace(std::vector<LineInfo>& lines);
        static void RemoveEmptyLines(std::vector<LineInfo>& lines);
        static void RemoveCommentLines(std::vector<LineInfo>& lines);
        static void RemoveTrailingComments(std::vector<LineInfo>& lines);
    };
}

#endif