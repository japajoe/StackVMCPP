#ifndef STACKVM_TOKENIZER_HPP
#define STACKVM_TOKENIZER_HPP

#include <string>
#include <vector>
#include <iostream>

namespace StackVM
{
    enum TokenType_ : int
    {
        WHITESPACE,
        COMMENT,
        POTENTIAL_COMMENT,
        IDENTIFIER,
        INTEGER_LITERAL,
        STRING_LITERAL,
        CHARACTER_LITERAL,
        STRING_ESCAPE_SEQUENCE,
        OPERATOR,
        POTENTIAL_FLOATING_POINT,
        FLOATING_POINT_LITERAL
    };

    static const char* tokenTypeString[] =
    {
        "WHITESPACE",
        "COMMENT",
        "POTENTIAL_COMMENT",
        "IDENTIFIER",
        "INTEGER_LITERAL",
        "STRING_LITERAL",
        "CHARACTER_LITERAL",
        "STRING_ESCAPE_SEQUENCE",
        "OPERATOR",
        "POTENTIAL_FLOATING_POINT",
        "FLOATING_POINT_LITERAL"
    };

    class Token_
    {
    public:
        TokenType_ type;
        std::string text;
        size_t lineNumber;
        void Dump() const;
    };

    typedef std::vector<Token_> TokenList;

    class Tokenizer
    {
    private:
        static char whitespace[6];
        static void EndToken(TokenList& tokens, Token_& token);
    public:
        static bool Parse(const std::string& source, TokenList& tokens);
    };
};

#endif