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

        std::cout << "Compilation done" << std::endl;

        // std::cout << "Assembly data:" << std::endl;
        // for (auto const& x : dataMap)
        // {
        //     std::cout   << x.first  // string (key)
        //                 << " offset: " 
        //                 << x.second // string's value 
        //                 << std::endl;
        // }   
        // std::cout << std::endl;
        // std::cout << "Assembly function labels:" << std::endl;
        // for (auto const& x : labelMap)
        // {
        //     std::cout   << x.first  // string (key)
        //                 << " offset: "
        //                 << x.second // string's value 
        //                 << std::endl;
        // }             

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
                        assembly->types.push_back(type);

                        uint32_t index = assembly->data.size();

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
                labelMap[identifierToken.text] = 0;
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
                        if((index + 1) < tokens.size())
                        {
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
                                                WriteError(leftOperandToken.lineNumber, "Failed to convert '" + leftOperandToken.text + "' to a number");
                                                return false;
                                            }
                                        }
                                        break;
                                    }
                                    case OperandTypeOption::RegisterOrVariable:
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                        else
                        {
                            assembly->instructions.push_back(Instruction(opcode));
                        }
                        
                        break;
                    }
                    case OperandInfo::One:
                    {

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
    
    void CompilerTest::WriteError(int lineNumber, const std::string& error)
    {
        std::cout << "Compiler -> Error on line " << lineNumber << ": " << error << std::endl;
    }
}