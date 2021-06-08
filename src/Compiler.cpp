#include "Compiler.hpp"
#include "StandardLibrary.hpp"

namespace StackVM
{
    Compiler::Compiler()
    {
        CompilerUtility::Initialize();

        functionMap["abs"]          = reinterpret_cast<uint64_t>(StandardLibrary::Abs);
        functionMap["clamp"]        = reinterpret_cast<uint64_t>(StandardLibrary::Clamp);
        functionMap["cos"]          = reinterpret_cast<uint64_t>(StandardLibrary::Cos);
        functionMap["lerp"]         = reinterpret_cast<uint64_t>(StandardLibrary::Lerp);
        functionMap["pow"]          = reinterpret_cast<uint64_t>(StandardLibrary::Pow);
        functionMap["sin"]          = reinterpret_cast<uint64_t>(StandardLibrary::Sin);
        functionMap["sign"]         = reinterpret_cast<uint64_t>(StandardLibrary::Sign);
        functionMap["sqrt"]         = reinterpret_cast<uint64_t>(StandardLibrary::Sqrt);
        functionMap["getTimeStamp"] = reinterpret_cast<uint64_t>(StandardLibrary::GetTimeStamp);
        functionMap["print"]        = reinterpret_cast<uint64_t>(StandardLibrary::Print);
        functionMap["printline"]    = reinterpret_cast<uint64_t>(StandardLibrary::PrintLine);
        functionMap["printnum"]     = reinterpret_cast<uint64_t>(StandardLibrary::PrintNum);
        functionMap["endline"]      = reinterpret_cast<uint64_t>(StandardLibrary::EndLine);
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

        size_t index = 0;
        size_t numInstructions = 0;
        Token prevToken = tokens[0];

        for(size_t i = 0 ; i < tokens.size(); i++)
        {
            if(i > 0)
                prevToken = tokens[i-1];

            if(tokens[i].type == TokenType::OPCODE)
            {
                if(prevToken.type == TokenType::FUNCTION_LABEL)
                {
                    labelMap[prevToken.text] = numInstructions;
                }
                numInstructions++;
            }
        }

        for(size_t i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].type == TokenType::VARIABLE_LABEL || 
               tokens[i].type == TokenType::FUNCTION_LABEL ||
               tokens[i].type == TokenType::OPCODE)
            {
                
                if(!ProcessToken(tokens, i))
                {
                    return false;
                }
            }
        }

        //Convert all indices of instructions with a jump to a pointer
        // for(size_t i = 0; i < assembly.instructions.size(); i++)
        // {
        //     if(CompilerUtility::IsJumpInstruction(assembly.instructions[i].opcode))
        //     {
        //         uint64_t offsetDst = *(uint64_t*)&assembly.instructions[i].lhs;
        //         uint64_t dst = reinterpret_cast<uint64_t>(&assembly.instructions[offsetDst]);
        //         memcpy(&assembly.instructions[i].lhs[0], &dst, sizeof(uint64_t));
        //     }            
        // }

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
                //Token& identifierToken = tokens[index];
                //labelMap[identifierToken.text] = 0;
                //labelMap[identifierToken.text] = assembly->instructions.size();
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

                            if(leftOperandToken.type == TokenType::OPERAND)
                            {
                                if(!ProcessSingleOperandInstruction(tokens, index, opcodeInfo))
                                {
                                    return false;
                                }                                
                            }
                            else
                            {
                                assembly->instructions.push_back(Instruction(opcode));
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

                            if(leftOperandToken.type == TokenType::OPERAND)
                            {
                                if(!ProcessSingleOperandInstruction(tokens, index, opcodeInfo))
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                WriteError(leftOperandToken.lineNumber, "Unexpected token '" + leftOperandToken.text + "'");
                                return false;                                
                            }                            
                        }
                        break;
                    }
                    case OperandInfo::Two:
                    {
                        if((index + 1) >= tokens.size())
                        {
                            WriteError(identifierToken.lineNumber, "Passing 0 operands to instruction which requires 2");
                            return false;
                        }
                        else if((index + 2) >= tokens.size())
                        {
                            WriteError(identifierToken.lineNumber, "Passing 1 operand to instruction which requires 2");
                            return false;
                        }
                        else
                        {
                            Token& leftOperandToken = tokens[index+1];
                            Token& rightOperandToken = tokens[index+2];

                            if(leftOperandToken.type == TokenType::OPERAND)
                            {
                                if(rightOperandToken.type == TokenType::OPERAND)
                                {
                                    if(!ProcessDoubleOperandInstruction(tokens, index, opcodeInfo))
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    WriteError(rightOperandToken.lineNumber, "Unexpected token '" + rightOperandToken.text + "'");
                                    return false;  
                                }
                            }
                            else
                            {
                                WriteError(leftOperandToken.lineNumber, "Unexpected token '" + leftOperandToken.text + "'");
                                return false;   
                            }
                        }
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

        if(leftOperandToken.type != TokenType::OPERAND)
        {
            WriteError(leftOperandToken.lineNumber, "Trying to process token as TokenType::OPERAND while it is of a different type");
            return false;
        }

        if(CompilerUtility::IsDirectiveToken(leftOperandToken.text))
        {
            WriteError(leftOperandToken.lineNumber, "Invalid operand value. The value '" + leftOperandToken.text + "' is reserved for define directives");
            return false;
        }

        OperandType leftOperandType;       
        Type leftType;        
        byte leftValue[8];        
        memset(leftValue, 0, 8);        

        if(DecodeInstruction(leftOperandToken, opcodeInfo.leftTypeOption, leftOperandType, leftType, leftValue))
        {
            assembly->instructions.push_back(Instruction(opcodeInfo.code, leftValue, leftType, leftOperandType));
        }
        else
        {
            return false;
        }        

        return true;
    }

    bool Compiler::ProcessDoubleOperandInstruction(std::vector<Token>& tokens, size_t index, const OpCodeInfo& opcodeInfo)
    {
        OpCode opcode = opcodeInfo.code;
        Token& leftOperandToken = tokens[index+1];
        Token& rightOperandToken = tokens[index+2];

        if(leftOperandToken.type != TokenType::OPERAND)
        {
            WriteError(leftOperandToken.lineNumber, "Trying to process token as TokenType::OPERAND while it is of a different type");
            return false;
        }
        
        if(rightOperandToken.type != TokenType::OPERAND)
        {
            WriteError(rightOperandToken.lineNumber, "Trying to process token as TokenType::OPERAND while it is of a different type");
            return false;
        }

        if(CompilerUtility::IsDirectiveToken(leftOperandToken.text))
        {
            WriteError(leftOperandToken.lineNumber, "Invalid operand value. The value '" + leftOperandToken.text + "' is reserved for define directives");
            return false;
        }

        if(CompilerUtility::IsDirectiveToken(rightOperandToken.text))
        {
            WriteError(rightOperandToken.lineNumber, "Invalid operand value. The value '" + leftOperandToken.text + "' is reserved for define directives");
            return false;
        }                

        OperandType leftOperandType;
        OperandType rightOperandType;
        Type leftType;
        Type rightType;
        byte leftValue[8];
        byte rightValue[8];
        memset(leftValue, 0, 8);
        memset(rightValue, 0, 8);

        if(DecodeInstruction(leftOperandToken, opcodeInfo.leftTypeOption, leftOperandType, leftType, leftValue))
        {
            if(DecodeInstruction(rightOperandToken, opcodeInfo.rightTypeOption, rightOperandType, rightType, rightValue))
            {
                assembly->instructions.push_back(Instruction(opcodeInfo.code, leftValue, leftType, leftOperandType, rightValue, rightType, rightOperandType));
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        return true;        
    }

    bool Compiler::DecodeInstruction(Token& operandToken, OperandTypeOption operandTypeOption, OperandType& operandType, Type& operandValueType, byte* operandValue)
    {
        switch(operandTypeOption)
        {
            case OperandTypeOption::All:
            {
                if(CompilerUtility::registerMap.count(operandToken.text) > 0)
                {
                    uint32_t value = CompilerUtility::registerMap[operandToken.text];
                    memcpy(operandValue, &value, sizeof(uint32_t));
                    operandType = OperandType::Register;
                    operandValueType = Type::UInt32;
                }
                else if(dataMap.count(operandToken.text) > 0)
                {
                    uint32_t value = dataMap[operandToken.text];
                    memcpy(operandValue, &value, sizeof(uint32_t));
                    operandType = OperandType::Variable;
                    operandValueType = Type::UInt32;
                }                                        
                else if(labelMap.count(operandToken.text) > 0)
                {
                    uint64_t value = labelMap[operandToken.text];
                    memcpy(operandValue, &value, sizeof(uint64_t));
                    operandType = OperandType::IntegerLiteral;
                    operandValueType = Type::UInt64;
                }
                else if(functionMap.count(operandToken.text) > 0)
                {
                    uint64_t value = functionMap[operandToken.text];
                    memcpy(operandValue, &value, sizeof(uint64_t));
                    operandType = OperandType::IntegerLiteral;
                    operandValueType = Type::UInt64;
                }
                else
                {
                    uint64_t temp = 0;
                    if(StringUtility::ParseNumberLexical<uint64_t>(operandToken.text, temp))
                    {
                        operandValueType = CompilerUtility::GetNumberTypeFromText(operandToken.text);                        

                        //Force minimum size of integers to 4 bytes
                        if(operandValueType == Type::UInt8)
                            operandValueType = Type::UInt32;
                        else if(operandValueType == Type::Int8)
                            operandValueType = Type::Int32;

                        int bytesWritten = CompilerUtility::WriteStringValueToBuffer(operandToken.text, operandValue, operandValueType);

                        if(bytesWritten > 0)
                        {
                            operandType = OperandType::IntegerLiteral;
                        }
                        else
                        {
                            WriteError(operandToken.lineNumber, "Failed to write value '" + operandToken.text + "' to instruction");
                            return false;
                        }
                    }
                    else
                    {
                        if(StringUtility::StartsWith(operandToken.text, "\\") && operandToken.text.size() == 2)
                        {
                            char character;
                            
                            switch(operandToken.text[1])
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
                                case '0':  character = '\0'; break;
                                default:
                                {
                                    WriteError(operandToken.lineNumber, "Unknown escape sequence '" + operandToken.text + "'");
                                    return false;
                                }
                            }

                            operandValueType = Type::Int8;
                            operandType = OperandType::IntegerLiteral;
                            memcpy(operandValue, &character, sizeof(char));
                        }
                        else
                        {
                            char character = operandToken.text[0];
                            operandValueType = Type::Int8;
                            operandType = OperandType::IntegerLiteral;
                            memcpy(operandValue, &character, sizeof(char));
                        }
                    }
                }
                break;
            }
            case OperandTypeOption::RegisterOrVariable:
            {
                if(CompilerUtility::registerMap.count(operandToken.text) > 0)
                {
                    uint32_t value = CompilerUtility::registerMap[operandToken.text];
                    memcpy(operandValue, &value, sizeof(uint32_t));
                    operandType = OperandType::Register;
                    operandValueType = Type::UInt32;
                }
                else if(dataMap.count(operandToken.text) > 0)
                {
                    uint32_t value = dataMap[operandToken.text];
                    memcpy(operandValue, &value, sizeof(uint32_t));
                    operandType = OperandType::Variable;
                    operandValueType = Type::UInt32;
                }                                        
                else if(labelMap.count(operandToken.text) > 0)
                {
                    uint64_t value = labelMap[operandToken.text];
                    memcpy(operandValue, &value, sizeof(uint64_t));
                    operandType = OperandType::IntegerLiteral;
                    operandValueType = Type::UInt64;
                }
                else
                {
                    WriteError(operandToken.lineNumber, "Unexpected value '" + operandToken.text + "'");
                    return false;
                }                                        
                break;
            }
        }        

        return true;
    }
    
    void Compiler::WriteError(int lineNumber, const std::string& error)
    {
        std::cout << "Compiler -> Error on line " << lineNumber << ": " << error << std::endl;
    }
}