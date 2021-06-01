#include "Compiler.hpp"

namespace StackVM
{
    Compiler::Compiler()
    {
        CompilerUtility::Initialize();
    }

    bool Compiler::Compile(const std::string& source, Assembly& assembly)
    {
        this->assembly = &assembly;
        assembly.instructions.clear();
        assembly.data.clear();        

        std::vector<LineInfo> lines = CompilerUtility::PreProcess(source);
        std::vector<Token> tokens;

        if(!CompilerUtility::Tokenize(lines, tokens))
            return false;          

        size_t tokenCount = tokens.size();
        size_t index = 0;

        size_t numVariables = CompilerUtility::CountTokens(tokens, TokenType::VARIABLE_LABEL);
        size_t numFunctions = CompilerUtility::CountTokens(tokens, TokenType::FUNCTION_LABEL);
        size_t numOpcodes = CompilerUtility::CountTokens(tokens, TokenType::OPCODE);

        for(size_t i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].type == TokenType::VARIABLE_LABEL || 
               tokens[i].type == TokenType::FUNCTION_LABEL ||
               tokens[i].type == TokenType::OPCODE)
            {
                index = i;
                if(!ProcessToken(tokens, index))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool Compiler::ProcessToken(std::vector<Token>& tokens, size_t index)
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

                Token& identifierToken = tokens[index];
                Token& directiveToken  = tokens[index+1];
                Token& valueToken      = tokens[index+2];

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
                    
                    byte data[8];
                    memset(data, 0, 8);
                    int bytesWritten = CompilerUtility::WriteStringValueToBuffer(valueToken.text, data, type);

                    if(bytesWritten > 0)
                    {
                        uint32_t index = assembly->types.size();
                        assembly->types.push_back(type);


                        assembly->indices.push_back(assembly->data.size());

                        for(size_t i = 0; i < bytesWritten; i++)
                            assembly->data.push_back(data[i]);                        
                        
                        dataMap[identifierToken.text] = index;
                    }
                    else
                    {
                        WriteError(valueToken.lineNumber, "Could not write value '" + valueToken.text + "' to buffer");
                        return false;
                    }
                }
                break;
            }
            case TokenType::FUNCTION_LABEL:
            {
                Token& identifierToken = tokens[index];
                //labelMap[identifierToken.text] = 0;
                labelMap[identifierToken.text] = assembly->instructions.size();
                break;
            }
            case TokenType::OPCODE:
            {                
                Token& identifierToken = tokens[index];                
                OpCodeInfo opcodeInfo = CompilerUtility::opcodeInfoMap[identifierToken.text];
                OpCode opcode = opcodeInfo.code;

                switch(opcodeInfo.operandInfo)
                {
                    case OperandInfo::None:
                    {                     
                        assembly->instructions.push_back(Instruction(opcode));
                        break;
                    }
                    case OperandInfo::Optional:
                    {      
                        if((index + 1) >= tokens.size())
                        {
                            assembly->instructions.push_back(Instruction(opcode));
                        }
                        else
                        {
                            Token& leftOperandToken = tokens[index+1];

                            if(leftOperandToken.type != TokenType::OPERAND)
                            {
                                assembly->instructions.push_back(Instruction(opcode));
                            }
                            else
                            {
                                if(!ProcessSingleOperandInstruction(tokens, index, opcodeInfo))
                                {
                                    return false;
                                }
                            }
                        }
                        
                        break;
                    }
                    case OperandInfo::One:
                    {
                        if((index + 1) >= tokens.size())
                        {
                            WriteError(identifierToken.lineNumber, "Passing 0 operands to instruction which requires 1");
                            return false;
                        }
                        else
                        {
                            Token& leftOperandToken = tokens[index+1];

                            if(leftOperandToken.type != TokenType::OPERAND)
                            {
                                WriteError(identifierToken.lineNumber, "Unexpected token '" + identifierToken.text + "'");
                                return false;
                            }
                            else
                            {
                                if(!ProcessSingleOperandInstruction(tokens, index, opcodeInfo))
                                {
                                    return false;
                                }
                            }                            
                        }
                        break;
                    }
                    case OperandInfo::Two:
                    {

                        break;
                    }
                }

                break;
            }
            default:
            {
                break;
            }
        }

        return true;
    }

    bool Compiler::ProcessSingleOperandInstruction(std::vector<Token>& tokens, size_t index, const OpCodeInfo& opcodeInfo)
    {
        OpCode opcode = opcodeInfo.code;

        Token& leftOperandToken = tokens[index+1];
        if(leftOperandToken.type == TokenType::OPERAND)
        {
            if(CompilerUtility::IsDirectiveToken(leftOperandToken.text))
            {
                WriteError(leftOperandToken.lineNumber, "Invalid operand value. The value '" + leftOperandToken.text + "' is reserved for define directives");
                return false;
            }
            
            switch(opcodeInfo.leftTypeOption)
            {
                case OperandTypeOption::All:
                {
                    if(CompilerUtility::registerMap.count(leftOperandToken.text) > 0)
                    {
                        uint32_t value = CompilerUtility::registerMap[leftOperandToken.text];
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::Register));
                    }
                    else if(dataMap.count(leftOperandToken.text) > 0)
                    {
                        uint32_t value = dataMap[leftOperandToken.text];
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::Variable));
                    }                                        
                    else if(labelMap.count(leftOperandToken.text) > 0)
                    {
                        uint32_t value = labelMap[leftOperandToken.text];                                            
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                    }
                    else
                    {
                        uint64_t temp = 0;
                        if(StringUtility::ParseNumberLexical<uint64_t>(leftOperandToken.text, temp))
                        {
                            Type type = CompilerUtility::GetNumberTypeFromText(leftOperandToken.text);                            

                            //Force minimum size of integers to 4 bytes
                            if(type == Type::UInt8)
                                type = Type::UInt32;
                            else if(type == Type::Int8)
                                type = Type::Int32;

                            byte leftValue[8];
                            memset(leftValue, 0, 8);
                            int bytesWritten = CompilerUtility::WriteStringValueToBuffer(leftOperandToken.text, leftValue, type);

                            if(bytesWritten > 0)
                            {
                                assembly->instructions.push_back(Instruction(opcode, leftValue, type, OperandType::IntegerLiteral));
                            }
                            else
                            {
                                WriteError(leftOperandToken.lineNumber, "Failed to write value '" + leftOperandToken.text + "' to instruction");
                                return false;
                            }
                        }
                        else
                        {
                            if(StringUtility::StartsWith(leftOperandToken.text, "\\") && leftOperandToken.text.size() == 2)
                            {
                                char character;
                                
                                switch(leftOperandToken.text[1])
                                {
                                    case 'a':  character = '\a'; break;
                                    case 'b':  character = '\b'; break;
                                    case 'f':  character = '\f'; break;
                                    case 'n':  character = '\n'; break;
                                    case 'r':  character = '\r'; break;
                                    case 't':  character = '\t'; break;
                                    case 'v':  character = '\v'; break;
                                    case '\\':  character = '\\'; break;
                                    case '\'':  character = '\''; break;
                                    case '"':  character = '"'; break;
                                    case '?':  character = '\?'; break;
                                    default:
                                    {
                                        WriteError(leftOperandToken.lineNumber, "Unknown escape sequence '" + leftOperandToken.text + "'");
                                        return false;
                                    }
                                }

                                Type type = Type::Int8;
                                byte leftValue[8];
                                memset(leftValue, 0, 8);
                                memcpy(leftValue, &character, sizeof(char));
                                assembly->instructions.push_back(Instruction(opcode, leftValue, type, OperandType::IntegerLiteral));
                            }
                            else
                            {
                                char character = leftOperandToken.text[0];
                                Type type = Type::Int8;
                                byte leftValue[8];
                                memset(leftValue, 0, 8);
                                memcpy(leftValue, &character, sizeof(char));
                                assembly->instructions.push_back(Instruction(opcode, leftValue, type, OperandType::IntegerLiteral));
                            }
                        }
                    }
                    break;
                }
                case OperandTypeOption::RegisterOrVariable:
                {
                    if(CompilerUtility::registerMap.count(leftOperandToken.text) > 0)
                    {
                        uint32_t value = CompilerUtility::registerMap[leftOperandToken.text];
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::Register));
                    }
                    else if(dataMap.count(leftOperandToken.text) > 0)
                    {
                        uint32_t value = dataMap[leftOperandToken.text];                                            
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::Variable));
                    }                                        
                    else if(labelMap.count(leftOperandToken.text) > 0)
                    {
                        uint32_t value = labelMap[leftOperandToken.text];                                            
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                    }
                    else
                    {
                        WriteError(leftOperandToken.lineNumber, "Unexpected value '" + leftOperandToken.text + "'");
                        return false;
                    }                                        
                    break;
                }
            }
        }
        else
        {
            WriteError(leftOperandToken.lineNumber, "Trying to process token as TokenType::OPERAND while it is of a different type");
            return false;
        }

        return true;
    }
    
    void Compiler::WriteError(int lineNumber, const std::string& error)
    {
        std::cout << "Compiler -> Error on line " << lineNumber << ": " << error << std::endl;
    }
}