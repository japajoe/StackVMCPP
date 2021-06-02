#include "CompilerUtility.hpp"

namespace StackVM
{
    bool CompilerUtility::isInitialized = false;
    std::map<std::string, OpCodeInfo> CompilerUtility::opcodeInfoMap;
    std::map<std::string, uint32_t> CompilerUtility::registerMap;
    std::map<std::string, DefineDirective> CompilerUtility::directivesMap;
    std::map<Type, std::string> CompilerUtility::typeToStringMap;

    void CompilerUtility::Initialize()
    {
        if(isInitialized)
            return;

        opcodeInfoMap["mov"]       = OpCodeInfo(OpCode::MOV,       OperandInfo::Two,        OperandTypeOption::RegisterOrVariable,  OperandTypeOption::All);
        opcodeInfoMap["inc"]       = OpCodeInfo(OpCode::INC,       OperandInfo::One,        OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["dec"]       = OpCodeInfo(OpCode::DEC,       OperandInfo::One,        OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["add"]       = OpCodeInfo(OpCode::ADD,       OperandInfo::Two,        OperandTypeOption::RegisterOrVariable,  OperandTypeOption::All);
        opcodeInfoMap["sub"]       = OpCodeInfo(OpCode::SUB,       OperandInfo::Two,        OperandTypeOption::RegisterOrVariable,  OperandTypeOption::All);
        opcodeInfoMap["mul"]       = OpCodeInfo(OpCode::MUL,       OperandInfo::Two,        OperandTypeOption::RegisterOrVariable,  OperandTypeOption::All);
        opcodeInfoMap["div"]       = OpCodeInfo(OpCode::DIV,       OperandInfo::Two,        OperandTypeOption::RegisterOrVariable,  OperandTypeOption::All);
        opcodeInfoMap["push"]      = OpCodeInfo(OpCode::PUSH,      OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushi8"]    = OpCodeInfo(OpCode::PUSHI8,    OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushu8"]    = OpCodeInfo(OpCode::PUSHU8,    OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushf"]     = OpCodeInfo(OpCode::PUSHF,     OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushd"]     = OpCodeInfo(OpCode::PUSHD,     OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushi32"]   = OpCodeInfo(OpCode::PUSHI32,   OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushu32"]   = OpCodeInfo(OpCode::PUSHU32,   OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushi16"]   = OpCodeInfo(OpCode::PUSHI16,   OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushu16"]   = OpCodeInfo(OpCode::PUSHU16,   OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushi64"]   = OpCodeInfo(OpCode::PUSHI64,   OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pushu64"]   = OpCodeInfo(OpCode::PUSHU64,   OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["pop"]       = OpCodeInfo(OpCode::POP,       OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popi8"]     = OpCodeInfo(OpCode::POPI8,     OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popu8"]     = OpCodeInfo(OpCode::POPU8,     OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popf"]      = OpCodeInfo(OpCode::POPF,      OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popd"]      = OpCodeInfo(OpCode::POPD,      OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popi32"]    = OpCodeInfo(OpCode::POPI32,    OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popu32"]    = OpCodeInfo(OpCode::POPU32,    OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popi16"]    = OpCodeInfo(OpCode::POPI16,    OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popu16"]    = OpCodeInfo(OpCode::POPU16,    OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popi64"]    = OpCodeInfo(OpCode::POPI64,    OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["popu64"]    = OpCodeInfo(OpCode::POPU64,    OperandInfo::Optional,   OperandTypeOption::RegisterOrVariable);
        opcodeInfoMap["print"]     = OpCodeInfo(OpCode::PRINT,     OperandInfo::None);
        opcodeInfoMap["cmp"]       = OpCodeInfo(OpCode::CMP,       OperandInfo::Two,        OperandTypeOption::All,                 OperandTypeOption::All);
        opcodeInfoMap["jmp"]       = OpCodeInfo(OpCode::JMP,       OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["je"]        = OpCodeInfo(OpCode::JE,        OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["jne"]       = OpCodeInfo(OpCode::JNE,       OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["jg"]        = OpCodeInfo(OpCode::JG,        OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["jge"]       = OpCodeInfo(OpCode::JGE,       OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["jl"]        = OpCodeInfo(OpCode::JL,        OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["jle"]       = OpCodeInfo(OpCode::JLE,       OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["jz"]        = OpCodeInfo(OpCode::JZ,        OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["jnz"]       = OpCodeInfo(OpCode::JNZ,       OperandInfo::One,        OperandTypeOption::All);
        opcodeInfoMap["nop"]       = OpCodeInfo(OpCode::NOP,       OperandInfo::None);
        opcodeInfoMap["hlt"]       = OpCodeInfo(OpCode::HLT,       OperandInfo::None);
        
        registerMap["eax"] = 0;
        registerMap["ebx"] = 1;
        registerMap["ecx"] = 2;
        registerMap["edx"] = 3;
        registerMap["ebp"] = 4;
        registerMap["esp"] = 5;
        registerMap["edi"] = 6;
        registerMap["eip"] = 7;
        registerMap["esi"] = 8;
        registerMap["rax"] = 9;
        registerMap["rbx"] = 10;
        registerMap["rcx"] = 11;
        registerMap["rdx"] = 12;

        directivesMap["db"] = DefineDirective::DB;
        directivesMap["dw"] = DefineDirective::DW;
        directivesMap["dd"] = DefineDirective::DD;
        directivesMap["dq"] = DefineDirective::DQ;

        typeToStringMap[Type::Int8]     = "Int8";
        typeToStringMap[Type::Int16]    = "Int16";
        typeToStringMap[Type::Int32]    = "Int32";
        typeToStringMap[Type::Int64]    = "Int64";
        typeToStringMap[Type::UInt8]    = "UInt8";
        typeToStringMap[Type::UInt16]   = "UInt16";
        typeToStringMap[Type::UInt32]   = "UInt32";
        typeToStringMap[Type::UInt64]   = "UInt64";
        typeToStringMap[Type::Double]   = "Double";
        typeToStringMap[Type::Single]   = "Single";

        isInitialized = true;
    }

    std::vector<LineInfo> CompilerUtility::PreProcess(const std::string& source)
    {
        auto sourceLines = StringUtility::Split(source, '\n');

        std::vector<LineInfo> lines;

        for(size_t i = 0; i < sourceLines.size(); i++)
        {
            lines.push_back(LineInfo(sourceLines[i], i + 1));
        }

        RemoveTrailingComments(lines);
        RemoveWhiteSpace(lines);
        RemoveEmptyLines(lines);
        RemoveCommentLines(lines);
        return lines;
    }

    bool CompilerUtility::Tokenize(std::vector<LineInfo>& lines, std::vector<Token>& tokens)
    {
        enum TokenizationState
        {
            DoData,
            DoInstructions
        };

        TokenizationState tokenizationState = TokenizationState::DoData;

        for(size_t i = 0; i < lines.size(); i++)
        {
            bool containsSpaceCharLiteral = false;

            if(StringUtility::Contains(lines[i].text, "' '"))
            {
                containsSpaceCharLiteral = true;
                lines[i].text = StringUtility::Replace(lines[i].text, "' '", "");
            }

            std::vector<std::string> components = StringUtility::Split(lines[i].text, ' ');

            if(containsSpaceCharLiteral)
            {
                components.push_back("' '");
                

                auto it = components.begin();

                while(it != components.end()) 
                {            
                    if(it->size() == 0) 
                    {
                        it = components.erase(it);
                    }
                    else 
                    {
                        ++it;
                    }
                }
            }            

            if(components.size() == 0)
                components.push_back(lines[i].text);

            for(size_t j = 0; j < components.size(); j++)
            {
                if(StringUtility::EndsWith(components[j], ","))
                    components[j].pop_back();

                if(StringUtility::Contains(components[j], "'"))
                    StringUtility::Replace(components[j], "'", "");
            }

            if(lines[i].text == "section .data")
            {
                tokenizationState = TokenizationState::DoData;
                continue;
            }
            else if(lines[i].text == "section .text")
            {
                tokenizationState = TokenizationState::DoInstructions;
                continue;
            }

            switch(tokenizationState)
            {
                case TokenizationState::DoData:
                {
                    if(components.size() != 4)
                    {
                        WriteError(lines[i].lineNumber, "Malformed instruction");                        
                        return false;
                    }
                    else if(StringUtility::StartsWithNumber(components[0]))
                    {
                        WriteError(lines[i].lineNumber, "Variable names can not start with a number");
                        return false;
                    }
                    else if(CompilerUtility::IsDirectiveToken(components[0]))
                    {
                        WriteError(lines[i].lineNumber, "Variables can not have the same name as a define directive");
                        return false;
                    }
                    else if(CompilerUtility::IsRegisterLabelToken(components[0]))
                    {
                        WriteError(lines[i].lineNumber, "Variables can not have the same name as a register");
                        return false;
                    }

                    tokens.push_back(Token(TokenType::VARIABLE_LABEL, components[0], lines[i].lineNumber));

                    if(!CompilerUtility::IsDirectiveToken(components[1]))
                    {
                        WriteError(lines[i].lineNumber, "Unknown define directive '" + components[1] + "'");
                        return false;
                    }

                    tokens.push_back(Token(TokenType::DIRECTIVE_SPECIFIER, StringUtility::ToLowerCase(components[1]), lines[i].lineNumber));

                    uint64_t value = 0;

                    if(!StringUtility::ParseNumberLexical<uint64_t>(components[3], value))
                    {
                        if(components[3].size() == 3)
                        {
                            if(StringUtility::StartsWith(components[3], "'") && StringUtility::EndsWith(components[3], "'"))
                            {
                                tokens.push_back(Token(TokenType::CHARACTER_LITERAL, components[3], lines[i].lineNumber));
                            }
                            else
                            {
                                WriteError(lines[i].lineNumber, "Invalid value '" + components[3] + "'");
                                return false;
                            }                            
                        }
                        else
                        {
                            WriteError(lines[i].lineNumber, "Invalid value '" + components[3] + "'");
                            return false;
                        }
                    }
                    else
                    {
                        tokens.push_back(Token(TokenType::INTEGER_LITERAL, components[3], lines[i].lineNumber));
                    }

                    break;
                }
                case TokenizationState::DoInstructions:
                {
                    if(StringUtility::EndsWith(components[0], ":"))
                    {
                        if(!StringUtility::StartsWithNumber(components[0]))
                        {
                            components[0].pop_back();
                            tokens.push_back(Token(TokenType::FUNCTION_LABEL, components[0], lines[i].lineNumber));
                            break;
                        }
                        else
                        {
                            WriteError(lines[i].lineNumber, "Invalid label identifier '" + components[0] + "'. Labels can not start with a number");
                            return false;
                        }
                    }

                    components[0] = StringUtility::ToLowerCase(components[0]);

                    if(!CompilerUtility::IsOpCodeToken(components[0]))
                    {
                        WriteError(lines[i].lineNumber, "Invalid OpCode '" + components[0] + "'");
                        return false;
                    }

                    //Find out how many operands opcode takes
                    OpCodeInfo opcodeInfo = CompilerUtility::opcodeInfoMap[components[0]];

                    switch(opcodeInfo.operandInfo)
                    {
                        case OperandInfo::None:
                        {
                            if(components.size() != 1)
                            {
                                WriteError(lines[i].lineNumber, "Invalid number of operands. Expected 0 but got " + std::to_string(components.size() - 1));
                                return false;
                            }
                            
                            tokens.push_back(Token(TokenType::OPCODE, components[0], lines[i].lineNumber));                         
                            
                            break;
                        }
                        case OperandInfo::Optional:
                        {
                            if(components.size() == 1)
                            {
                                tokens.push_back(Token(TokenType::OPCODE, components[0], lines[i].lineNumber));
                            }
                            else if(components.size() == 2)
                            {
                                tokens.push_back(Token(TokenType::OPCODE, components[0], lines[i].lineNumber));
                                tokens.push_back(Token(TokenType::OPERAND, components[1], lines[i].lineNumber));
                            }
                            else
                            {
                                WriteError(lines[i].lineNumber, "Invalid number of operands. Expected 0 or 1 but got " + std::to_string(components.size() - 1));
                                return false;
                            }                            

                            break;
                        }
                        case OperandInfo::One:
                        {
                            if(components.size() != 2)
                            {
                                WriteError(lines[i].lineNumber, "Invalid number of operands. Expected 1 but got " + std::to_string(components.size() - 1));
                                return false;
                            }

                            tokens.push_back(Token(TokenType::OPCODE, components[0], lines[i].lineNumber));
                            tokens.push_back(Token(TokenType::OPERAND, components[1], lines[i].lineNumber));

                            break;
                        }
                        case OperandInfo::Two:
                        {
                            if(components.size() != 3)
                            {
                                WriteError(lines[i].lineNumber, "Invalid number of operands. Expected 2 but got " + std::to_string(components.size() - 1));
                                return false;
                            } 

                            tokens.push_back(Token(TokenType::OPCODE, components[0], lines[i].lineNumber));
                            tokens.push_back(Token(TokenType::OPERAND, components[1], lines[i].lineNumber));
                            tokens.push_back(Token(TokenType::OPERAND, components[2], lines[i].lineNumber));

                            break;
                        }
                    }                    

                    break;
                }
            }
        }

        return true;
    }

    void CompilerUtility::RemoveWhiteSpace(std::vector<LineInfo>& lines)
    {
        for(size_t i = 0; i < lines.size(); i++)
        {
            std::string code = StringUtility::TrimWhiteSpace(lines[i].text);
            lines[i].text = code;
        }        
    }

    void CompilerUtility::RemoveEmptyLines(std::vector<LineInfo>& lines)
    {
        auto it = lines.begin();

        while(it != lines.end()) 
        {            
            if(it->text.size() == 0) 
            {
                it = lines.erase(it);
            }
            else 
            {
                ++it;
            }
        }          
    }

    void CompilerUtility::RemoveCommentLines(std::vector<LineInfo>& lines)
    {
        auto it = lines.begin();

        while(it != lines.end()) 
        {
            if(StringUtility::StartsWith(it->text, ";"))
            {
                it = lines.erase(it);
            }
            else 
            {
                ++it;
            }
        }        
    }

    void CompilerUtility::RemoveTrailingComments(std::vector<LineInfo>& lines)
    {
        for(size_t i = 0; i < lines.size(); i++)
        {
            if(StringUtility::Contains(lines[i].text, ";"))
            {
                auto components = StringUtility::Split(lines[i].text, ';');
                
                if(components.size() > 0)
                {
                    lines[i].text = components[0];
                }
            }
        }        
    }

    Type CompilerUtility::GetNumberTypeFromText(const std::string& text)
    {
        bool isSigned = false;
        std::string t = text;
        if(StringUtility::StartsWith(t, "-"))
        {
            t = t.replace(0, 1, "");
            isSigned = true;
        }        
        
        uint64_t val = 0;
        
        StringUtility::ParseNumber<uint64_t>(t, val);

        if(isSigned)
        {
            if(val > 2147483647)
                return Type::Int64;
            else if(val > 32767 && val <= 2147483647)
                return Type::Int32;
            else if(val > 127 && val <= 32767)
                return Type::Int16;
            else            
                return Type::UInt8;            
        }
        else
        {
            if(val > 4294967295)
                return Type::UInt64;
            else if(val > 65535 && val <= 4294967295)
                return Type::UInt32;
            else if(val > 255 && val <= 65535)
                return Type::UInt16;
            else
                return Type::UInt8;  
        }        
    }

    bool CompilerUtility::IsDirectiveToken(const std::string& text)
    {
        return directivesMap.count(StringUtility::ToLowerCase(text)) > 0;
    }

    bool CompilerUtility::IsRegisterLabelToken(const std::string& text)
    {
        return registerMap.count(StringUtility::ToLowerCase(text)) > 0;
    }

    bool CompilerUtility::IsFunctionLabelToken(const std::string& text)
    {
        return false;
    }

    bool CompilerUtility::IsVariableLabelToken(const std::string& text)
    {
        return false;
    }

    bool CompilerUtility::IsOpCodeToken(const std::string& text)
    {
        return opcodeInfoMap.count(StringUtility::ToLowerCase(text)) > 0;
    }

    bool CompilerUtility::IsIntegerLiteralToken(const std::string& text)
    {
        uint64_t value = 0;
        return StringUtility::ParseNumberLexical<uint64_t>(text, value);
    }

    bool CompilerUtility::LineHasVariableDeclaration(const std::string& text)
    {
        if(StringUtility::Contains(text, ":"))
        {
            if(!StringUtility::StartsWith(text, ":") && !StringUtility::EndsWith(text, ":"))
            {
                auto components = StringUtility::Split(text, ' ');

                if(components.size() == 4)
                {
                    if(directivesMap.count(components[2]) > 0)
                        return true;
                }
            }
        }

        return false;
    }

    bool CompilerUtility::LineHasFunctionDeclaration(const std::string& text)
    {
        if(StringUtility::Contains(text, ":"))
        {
            if(StringUtility::EndsWith(text, ":"))
            {
                if(!StringUtility::StartsWithNumber(text))
                    return true;
            }
        }

        return false;
    }

    int CompilerUtility::WriteStringValueToBuffer(const std::string& text, byte* buffer, Type type)
    {
        int bytesWritten = 0;

        switch(type)
        {
            case Type::Int8:
            {
                char value = static_cast<char>(text[0]);
                memcpy(buffer, &value, sizeof(char));
                bytesWritten = sizeof(char);
                break;
            }
            case Type::Int16:
            {
                int16_t value = 0;
                
                if(!StringUtility::ParseNumberLexical<int16_t>(text, value))
                {
                    return 0;
                }

                memcpy(buffer, &value, sizeof(int16_t));
                bytesWritten = sizeof(int16_t);
                break;
            }
            case Type::Int32:
            {
                int32_t value = 0;
                
                if(!StringUtility::ParseNumberLexical<int32_t>(text, value))
                {
                    return 0;
                }

                memcpy(buffer, &value, sizeof(int32_t));
                bytesWritten = sizeof(int32_t);
                break;
            }
            case Type::Int64:
            {
                int64_t value = 0;
                
                if(!StringUtility::ParseNumberLexical<int64_t>(text, value))
                {
                    return 0;
                }

                memcpy(buffer, &value, sizeof(int64_t));
                bytesWritten = sizeof(int64_t);
                break;
            }
            case Type::UInt8:
            {
                unsigned char value = static_cast<unsigned char>(text[0]);
                memcpy(buffer, &value, sizeof(unsigned char));
                bytesWritten = sizeof(unsigned char);
                break;
            }
            case Type::UInt16:
            {
                uint16_t value = 0;
                
                if(!StringUtility::ParseNumberLexical<uint16_t>(text, value))
                {
                    return 0;
                }

                memcpy(buffer, &value, sizeof(uint16_t));
                bytesWritten = sizeof(uint16_t);
                break;
            }
            case Type::UInt32:
            {
                uint32_t value = 0;
                
                if(!StringUtility::ParseNumberLexical<uint32_t>(text, value))
                {
                    return 0;
                }
                
                memcpy(buffer, &value, sizeof(uint32_t));
                bytesWritten = sizeof(uint32_t);
                break;
            }
            case Type::UInt64:
            {
                uint64_t value = 0;
                
                if(!StringUtility::ParseNumberLexical<uint64_t>(text, value))
                {
                    return 0;
                }

                memcpy(buffer, &value, sizeof(uint64_t));
                bytesWritten = sizeof(uint64_t);
                break;
            }
            case Type::Single:
            {
                float value = 0;
                
                if(!StringUtility::ParseNumberLexical<float>(text, value))
                {
                    return 0;
                }

                memcpy(buffer, &value, sizeof(float));
                bytesWritten = sizeof(float);
                break;
            }
            case Type::Double:
            {
                double value = 0;
                
                if(!StringUtility::ParseNumberLexical<double>(text, value))
                {
                    return 0;
                }

                memcpy(buffer, &value, sizeof(double));
                bytesWritten = sizeof(double);
                break;
            }
            default:
            {   
                bytesWritten = 0;                                         
                break;
            }
        } 

        return bytesWritten;       
    }

    bool CompilerUtility::NumberIsSigned(const std::string& text)
    {
        return text[0] == '-';
    }

    size_t CompilerUtility::CountTokens(const std::vector<Token>& tokens, TokenType type)
    {
        int count = 0;
        for(size_t i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].type == type)
                count++;
        }

        return count;
    }

    void CompilerUtility::WriteError(int lineNumber, const std::string& error)
    {
        std::cout << "Tokenizer -> Error on line " << lineNumber << ": " << error << std::endl;
    }    
}