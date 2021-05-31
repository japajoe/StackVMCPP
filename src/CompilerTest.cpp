#include "CompilerTest.hpp"

namespace StackVM
{
    CompilerTest::CompilerTest()
    {
        CompilerUtility::Initialize();
    }

    bool CompilerTest::Compile(const std::string& source, Assembly& assembly)
    {
        this->assembly = &assembly;
        assembly.instructions.clear();
        assembly.data.clear();
        
        auto sourceLines = StringUtility::Split(source, '\n');

        std::vector<LineInfo> lines;

        for(size_t i = 0; i < sourceLines.size(); i++)
        {
            lines.push_back(LineInfo(sourceLines[i], i + 1));
        }

        CompilerUtility::RemoveWhiteSpace(lines);
        CompilerUtility::RemoveEmptyLines(lines);
        CompilerUtility::RemoveCommentLines(lines);
        CompilerUtility::RemoveTrailingComments(lines);

        std::vector<Token> tokens;

        if(!CompilerUtility::Tokenize(lines, tokens))
            return false;

        size_t tokenCount = tokens.size();
        size_t index = 0;

        for(size_t i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].type == TokenType::VARIABLE_LABEL || tokens[i].type == TokenType::OPCODE)
            {
                index = i;
                ProcessToken(tokens, index);
            }
        }

        return true;
    }

    bool CompilerTest::ProcessToken(std::vector<Token>& tokens, size_t index)
    {        
        switch(tokens[index].type)
        {
            case TokenType::VARIABLE_LABEL:
            {
                if((index + 2) >= tokens.size())
                {
                    WriteError(tokens[index].lineNumber, "Can not process token because it falls outside the range of tokens");
                    return false;
                }

                Token& directiveToken = tokens[index+1];
                Token& valueToken     = tokens[index+2];

                if(directiveToken.type == TokenType::DIRECTIVE_SPECIFIER)
                {
                    DefineDirective directive = CompilerUtility::directivesMap[directiveToken.text];

                    bool valueIsSigned = CompilerUtility::NumberIsSigned(valueToken.text);

                    Type type = Type::UInt64;

                    switch(directive)
                    {
                        case DefineDirective::DB:
                        {
                            type = valueIsSigned ? Type::Int8 : Type::UInt8;
                            break;
                        }
                        case DefineDirective::DW:
                        {
                            type = valueIsSigned ? Type::Int16 : Type::UInt16;
                            break;
                        }
                        case DefineDirective::DD:
                        {
                            if(StringUtility::Contains(valueToken.text, "."))
                            {
                                type = Type::Single;
                            }
                            else
                            {
                                type = valueIsSigned ? Type::Int32 : Type::UInt32;
                                break;
                            }
                            break;
                        }
                        case DefineDirective::DQ:
                        {
                            if(StringUtility::Contains(valueToken.text, "."))
                            {
                                type = Type::Double;
                            }
                            else
                            {
                                type = valueIsSigned ? Type::Int64 : Type::UInt64;
                                break;
                            }
                            break;                                
                        }
                    }

                    assembly->types.push_back(type);
                    
                    byte data[8];
                    memset(data, 0, 8);
                    int bytesWritten = CompilerUtility::WriteStringValueToBuffer(valueToken.text, data, type);

                    if(bytesWritten > 0)
                    {
                        for(size_t i = 0; i < bytesWritten; i++)
                            assembly->data.push_back(data[i]);
                    }
                    else
                    {
                        WriteError(valueToken.lineNumber, "Could not write value '" + valueToken.text + "' to buffer");
                        return false;
                    }
                }
                break;
            }
            case TokenType::OPCODE:
            {
                break;
            }
            default:
            {
                break;
            }
        }

        return true;
    }
    
    void CompilerTest::WriteError(int lineNumber, const std::string& error)
    {
        std::cout << "Compiler -> Error on line " << lineNumber << ": " << error << std::endl;
    }
}