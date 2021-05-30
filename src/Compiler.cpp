#include "Compiler.hpp"
#include "StringUtility.hpp"
#include <iostream>
#include <cstring>

namespace StackVM
{
    Compiler::Compiler()
    {
        opcodeInfoMap["mov"]       = OpCodeInfo(OpCode::MOV,       OperandInfo::Two);
        opcodeInfoMap["inc"]       = OpCodeInfo(OpCode::INC,       OperandInfo::One);
        opcodeInfoMap["dec"]       = OpCodeInfo(OpCode::DEC,       OperandInfo::One);
        opcodeInfoMap["add"]       = OpCodeInfo(OpCode::ADD,       OperandInfo::None);
        opcodeInfoMap["sub"]       = OpCodeInfo(OpCode::SUB,       OperandInfo::None);
        opcodeInfoMap["mul"]       = OpCodeInfo(OpCode::MUL,       OperandInfo::None);
        opcodeInfoMap["div"]       = OpCodeInfo(OpCode::DIV,       OperandInfo::None);
        opcodeInfoMap["push"]      = OpCodeInfo(OpCode::PUSH,      OperandInfo::One);
        opcodeInfoMap["pushi8"]    = OpCodeInfo(OpCode::PUSHI8,    OperandInfo::One);
        opcodeInfoMap["pushu8"]    = OpCodeInfo(OpCode::PUSHU8,    OperandInfo::One);
        opcodeInfoMap["pushf"]     = OpCodeInfo(OpCode::PUSHF,     OperandInfo::One);
        opcodeInfoMap["pushd"]     = OpCodeInfo(OpCode::PUSHD,     OperandInfo::One);
        opcodeInfoMap["pushi32"]   = OpCodeInfo(OpCode::PUSHI32,   OperandInfo::One);
        opcodeInfoMap["pushu32"]   = OpCodeInfo(OpCode::PUSHU32,   OperandInfo::One);
        opcodeInfoMap["pushi16"]   = OpCodeInfo(OpCode::PUSHI16,   OperandInfo::One);
        opcodeInfoMap["pushu16"]   = OpCodeInfo(OpCode::PUSHU16,   OperandInfo::One);
        opcodeInfoMap["pushi64"]   = OpCodeInfo(OpCode::PUSHI64,   OperandInfo::One);
        opcodeInfoMap["pushu64"]   = OpCodeInfo(OpCode::PUSHU64,   OperandInfo::One);
        opcodeInfoMap["pop"]       = OpCodeInfo(OpCode::POP,       OperandInfo::Optional);
        opcodeInfoMap["popi8"]     = OpCodeInfo(OpCode::POPI8,     OperandInfo::Optional);
        opcodeInfoMap["popu8"]     = OpCodeInfo(OpCode::POPU8,     OperandInfo::Optional);
        opcodeInfoMap["popf"]      = OpCodeInfo(OpCode::POPF,      OperandInfo::Optional);
        opcodeInfoMap["popd"]      = OpCodeInfo(OpCode::POPD,      OperandInfo::Optional);
        opcodeInfoMap["popi32"]    = OpCodeInfo(OpCode::POPI32,    OperandInfo::Optional);
        opcodeInfoMap["popu32"]    = OpCodeInfo(OpCode::POPU32,    OperandInfo::Optional);
        opcodeInfoMap["popi16"]    = OpCodeInfo(OpCode::POPI16,    OperandInfo::Optional);
        opcodeInfoMap["popu16"]    = OpCodeInfo(OpCode::POPU16,    OperandInfo::Optional);
        opcodeInfoMap["popi64"]    = OpCodeInfo(OpCode::POPI64,    OperandInfo::Optional);
        opcodeInfoMap["popu64"]    = OpCodeInfo(OpCode::POPU64,    OperandInfo::Optional);
        opcodeInfoMap["print"]     = OpCodeInfo(OpCode::PRINT,     OperandInfo::None);
        opcodeInfoMap["cmp"]       = OpCodeInfo(OpCode::CMP,       OperandInfo::Two);
        opcodeInfoMap["jmp"]       = OpCodeInfo(OpCode::JMP,       OperandInfo::One);
        opcodeInfoMap["je"]        = OpCodeInfo(OpCode::JE,        OperandInfo::One);
        opcodeInfoMap["jne"]       = OpCodeInfo(OpCode::JNE,       OperandInfo::One);
        opcodeInfoMap["jg"]        = OpCodeInfo(OpCode::JG,        OperandInfo::One);
        opcodeInfoMap["jge"]       = OpCodeInfo(OpCode::JGE,       OperandInfo::One);
        opcodeInfoMap["jl"]        = OpCodeInfo(OpCode::JL,        OperandInfo::One);
        opcodeInfoMap["jle"]       = OpCodeInfo(OpCode::JLE,       OperandInfo::One);
        opcodeInfoMap["jz"]        = OpCodeInfo(OpCode::JZ,        OperandInfo::One);
        opcodeInfoMap["jnz"]       = OpCodeInfo(OpCode::JNZ,       OperandInfo::One);
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
    }

    bool Compiler::Compile(const std::string& source, Assembly& assembly)
    {
        assembly.instructions.clear();
        assembly.data.clear();
        
        auto sourceLines = StringUtility::Split(source, '\n');

        std::vector<LineInfo> lines;

        for(size_t i = 0; i < sourceLines.size(); i++)
        {
            lines.push_back(LineInfo(sourceLines[i], i + 1));
        }

        RemoveWhiteSpace(lines);
        RemoveEmptyLines(lines);
        RemoveCommentLines(lines);
        RemoveTrailingComments(lines);
        
        std::map<std::string, uint32_t> dataMap;
        std::map<std::string, uint32_t> labelMap;

        for(size_t i = 0; i < lines.size(); i++)
        {
            if(StringUtility::EndsWith(lines[i].text, ":"))
            {
                if(!ProcessLabels(lines, i, &assembly, labelMap))
                    return false;
            }
        }         

        for(size_t i = 0; i < lines.size(); i++)
        {
            if(StringUtility::Contains(lines[i].text, "section .data"))
            {
                if(!ProcessData(lines, i + 1, &assembly, dataMap))
                    return false;
            }
        }

        for(size_t i = 0; i < lines.size(); i++)
        {
            if(StringUtility::Contains(lines[i].text, "section .text"))
            {
                if(!ProcessText(lines, i + 1, &assembly, labelMap, dataMap))
                    return false;
            }
        }

       

        return true;

    }

    void Compiler::RemoveWhiteSpace(std::vector<LineInfo>& lines)
    {
        for(size_t i = 0; i < lines.size(); i++)
        {
            std::string code = StringUtility::TrimWhiteSpace(lines[i].text);
            lines[i].text = code;
        }
    }

    void Compiler::RemoveEmptyLines(std::vector<LineInfo>& lines)
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
    
    void Compiler::RemoveCommentLines(std::vector<LineInfo>& lines)
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

    void Compiler::RemoveTrailingComments(std::vector<LineInfo>& lines)
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

    void Compiler::Dump(const std::vector<LineInfo>& lines)
    {
        for(size_t i = 0; i < lines.size(); i++)
        {
            std::cout << lines[i].text << std::endl;
        }
    }

    bool Compiler::ProcessData(const std::vector<LineInfo>& lines, size_t offset, Assembly* assembly, std::map<std::string,uint32_t>& dataMap)
    {
        size_t dataIndex = 0;
        unsigned char buffer[8];
        memset(buffer, 0, 8);

        for(size_t i = offset; i < lines.size(); i++)
        {
            if(StringUtility::Contains(lines[i].text, ":"))
            {
                auto components = StringUtility::Split(lines[i].text, " ");

                if(components.size() == 4)
                {
                    std::string identifier = components[0];
                    std::string type = StringUtility::ToLowerCase(components[1]);
                    std::string value = components[3];

                    if(directivesMap.count(type) == 0)
                    {
                        std::cout << "Unknown type '" << components[1] << "' one line " << lines[i].lineNumber << std::endl;
                        return false;
                    }                    

                    DefineDirective directive = directivesMap[type];
                    Type tp;

                    if(StringUtility::StartsWith(value, "'") && StringUtility::EndsWith(value, "'"))
                    {
                        auto characters = StringUtility::Split(value, '\'');
                        if(characters.size() > 0)
                        {
                            char character = characters[0][0];
                            memcpy(buffer, &character, sizeof(char));

                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if(!ParseValueFromDirective(value, lines[i].lineNumber, directive, buffer, tp))
                            return false;
                    }
                    
                    size_t dataSize = static_cast<size_t>(directive);

                    dataMap[identifier] = assembly->data.size();

                    for(size_t i = 0; i < dataSize; i++)
                        assembly->data.push_back(buffer[i]);

                    assembly->types.push_back(tp);
                }                
                else
                {
                    if(StringUtility::EndsWith(lines[i].text, ":"))
                    {
                        continue;
                    }
                    else
                    {
                        std::cout << "Malformed instruction '" << lines[i].text << "'" << " at line " << lines[i].lineNumber << std::endl;
                        return false;
                    }
                }                
            }
        }

        return true;
    }

    bool Compiler::ProcessLabels(std::vector<LineInfo>& lines, size_t offset, Assembly* assembly, std::map<std::string,uint32_t>& labelMap)
    {
        for(size_t i = offset; i < lines.size(); i++)
        {
            if(StringUtility::EndsWith(lines[i].text, ":"))
            {
                std::string label = lines[i].text;
                label.pop_back();
                labelMap[label] = i;
            }
        }

        return true;
    }    

    bool Compiler::ProcessText(const std::vector<LineInfo>& lines, size_t offset, Assembly* assembly, std::map<std::string,uint32_t>& labelMap, std::map<std::string,uint32_t>& dataMap)
    {
        for(size_t i = offset; i < lines.size(); i++)
        {
            auto components = StringUtility::Split(lines[i].text, ' ');

            if(components.size() > 0)
            {
                std::string opcode = StringUtility::ToLowerCase(components[0]);

                if(StringUtility::EndsWith(lines[i].text, ":"))
                    continue;

                if(opcodeInfoMap.count(opcode) == 0)
                {
                    std::cout << "Unknown OpCode " << components[0] << " on line " << lines[i].lineNumber << std::endl;
                    return false;
                }

                OpCodeInfo info = opcodeInfoMap[opcode];

                switch(info.operandInfo)
                {
                    case OperandInfo::None:
                    {
                        if(components.size() > 1)
                        {
                            std::cout << "Unexpected number of operands on line " << lines[i].lineNumber << ". Expected 0, delivered " << (components.size() - 1) << std::endl;
                            return false;
                        }

                        assembly->instructions.push_back(Instruction(info.code));

                        break;
                    }
                    case OperandInfo::Optional:
                    {
                        if(components.size() == 1)
                        {
                            assembly->instructions.push_back(Instruction(info.code));
                        }
                        else if(components.size() > 2)
                        {
                            std::cout << "Unexpected number of operands on line " << lines[i].lineNumber << ". Expected 0 or 1, delivered " << (components.size() - 1) << std::endl;
                            return false;
                        }
                        else
                        {
                            if(!ProcessOneOperandInstruction(lines[i], info.code, components[1], assembly, labelMap, dataMap))
                                return false;
                        }

                        break;
                    }
                    case OperandInfo::One:
                    {
                        if(components.size() > 2 || components.size() == 1)
                        {
                            std::cout << "Unexpected number of operands on line " << lines[i].lineNumber << ". Expected 1, delivered " << (components.size() - 1) << std::endl;
                            return false;
                        }
                        else
                        {
                            if(!ProcessOneOperandInstruction(lines[i], info.code, components[1], assembly, labelMap, dataMap))
                                return false;
                        }                        

                        break;
                    }                    
                    case OperandInfo::Two:
                    {
                        if(components.size() != 3)
                        {
                            std::cout << "Unexpected number of operands on line " << lines[i].lineNumber << ". Expected 2, delivered " << (components.size() - 1) << std::endl;
                            return false;
                        }
                        break;
                    }                    

                }
            }
        }

        return true;
    }

    bool Compiler::ProcessOneOperandInstruction(const LineInfo& line, OpCode opcode, const std::string operandText, Assembly* assembly, std::map<std::string,uint32_t>& labelMap, std::map<std::string,uint32_t>& dataMap)
    {
        //Check whether operand is a register, variable or integer literal
        if(registerMap.count(operandText) > 0)
        {
            uint32_t reg = registerMap[operandText];
            assembly->instructions.push_back(Instruction(opcode, reg, OperandType::Register));
        }
        else if(labelMap.count(operandText) > 0)
        {
            uint32_t location = labelMap[operandText];
            assembly->instructions.push_back(Instruction(opcode, location, OperandType::IntegerLiteral));
        }
        else if(dataMap.count(operandText) > 0)
        {
            uint32_t variable = dataMap[operandText];
            assembly->instructions.push_back(Instruction(opcode, variable, OperandType::Variable));
        }        
        else
        {
            uint64_t val = 0;
            if(!StringUtility::ParseNumberLexical<uint64_t>(operandText, val))
            {
                std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                return false;
            }

            //Possible floating point number
            if(StringUtility::Contains(operandText, "."))
            {
                if(StringUtility::EndsWith(operandText, "f"))
                {
                    float val = 0;
                    if(!StringUtility::ParseNumber<float>(operandText, val))
                    {
                        std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                        return false;
                    }
                    assembly->instructions.push_back(Instruction(opcode, val, OperandType::IntegerLiteral));
                }
                else
                {
                    double val = 0;
                    if(!StringUtility::ParseNumber<double>(operandText, val))
                    {
                        std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                        return false;
                    }
                    assembly->instructions.push_back(Instruction(opcode, val, OperandType::IntegerLiteral));
                }
            }
            else
            {
                uint64_t val = 0;

                if(!StringUtility::ParseNumber<uint64_t>(operandText, val))
                {
                    std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                    return false;                                        
                }

                Type type = GetNumberTypeFromText(operandText);

                switch(type)
                {
                    case Type::Int8:
                    {
                        char value = static_cast<char>(operandText[0]);
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));         
                        break;
                    }
                    case Type::Int16:
                    {
                        int16_t value = 0;
                        
                        if(!StringUtility::ParseNumber<int16_t>(operandText, value))
                        {
                            std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                            return false; 
                        }

                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                        break;
                    }
                    case Type::Int32:
                    {
                        int32_t value = 0;
                        
                        if(!StringUtility::ParseNumber<int32_t>(operandText, value))
                        {
                            std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                            return false; 
                        }

                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                        break;
                    }
                    case Type::Int64:
                    {
                        int64_t value = 0;
                        
                        if(!StringUtility::ParseNumber<int64_t>(operandText, value))
                        {
                            std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                            return false; 
                        }

                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                        break;
                    }
                    case Type::UInt8:
                    {
                        unsigned char value = static_cast<unsigned char>(operandText[0]);
                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                        break;
                    }
                    case Type::UInt16:
                    {
                        uint16_t value = 0;
                        
                        if(!StringUtility::ParseNumber<uint16_t>(operandText, value))
                        {
                            std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                            return false; 
                        }

                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                        break;
                    }
                    case Type::UInt32:
                    {
                        uint32_t value = 0;
                        
                        if(!StringUtility::ParseNumber<uint32_t>(operandText, value))
                        {
                            std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                            return false; 
                        }

                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                        break;
                    }
                    case Type::UInt64:
                    {
                        uint64_t value = 0;
                        
                        if(!StringUtility::ParseNumber<uint64_t>(operandText, value))
                        {
                            std::cout << "Failed to parse number '" << operandText << "' on line " << line.lineNumber << std::endl;
                            return false; 
                        }

                        assembly->instructions.push_back(Instruction(opcode, value, OperandType::IntegerLiteral));
                        break;
                    }
                    default:
                    {                                            
                        break;
                    }
                }
            }
        }        

        return true;
    }

    bool Compiler::ProcessTwoOperandInstruction(const LineInfo& line, OpCode opcode, const std::string operandTextLHS, const std::string operandTextRHS, Assembly* assembly, std::map<std::string,uint32_t>& labelMap, std::map<std::string,uint32_t>& dataMap)
    {
        byte valueLeft[8];
        byte valueRight[8];
        OperandType operandTypeLHS;
        OperandType operandTypeRHS;
        Type valueLeftType;
        Type valueRightType;

        memset(valueLeft, 0, 8);
        memset(valueRight, 0, 8);       

        //Check whether operand is a register, variable or integer literal
        if(registerMap.count(operandTextLHS) > 0)
        {
            uint32_t reg = registerMap[operandTextLHS];
            memcpy(valueLeft, &reg, sizeof(uint32_t));
            operandTypeLHS = OperandType::Register;
            valueLeftType = Type::UInt32;
        }
        else if(labelMap.count(operandTextLHS) > 0)
        {
            uint32_t location = labelMap[operandTextLHS];
            memcpy(valueLeft, &location, sizeof(uint32_t));
            operandTypeLHS = OperandType::IntegerLiteral;
            valueLeftType = Type::UInt32;
        }
        else if(dataMap.count(operandTextLHS) > 0)
        {
            uint32_t variable = dataMap[operandTextLHS];
            memcpy(valueLeft, &variable, sizeof(uint32_t));
            operandTypeLHS = OperandType::Variable;
            valueLeftType = Type::UInt32;
        }
        else
        {
            uint64_t val = 0;
            if(!StringUtility::ParseNumberLexical<uint64_t>(operandTextLHS, val))
            {
                std::cout << "Failed to parse number '" << operandTextLHS << "' on line " << line.lineNumber << std::endl;
                return false;
            }

            valueLeftType = GetNumberTypeFromText(operandTextLHS);
            operandTypeLHS = OperandType::IntegerLiteral;

            switch(valueLeftType)
            {
                case Type::Int8:
                {
                    char value = static_cast<char>(operandTextLHS[0]);
                    memcpy(valueLeft, &value, sizeof(char));
                    break;
                }
                case Type::Int16:
                {
                    int16_t value = 0;
                    
                    if(!StringUtility::ParseNumber<int16_t>(operandTextLHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextLHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueLeft, &value, sizeof(int16_t));
                    break;
                }
                case Type::Int32:
                {
                    int32_t value = 0;
                    
                    if(!StringUtility::ParseNumber<int32_t>(operandTextLHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextLHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueLeft, &value, sizeof(int32_t));
                    break;
                }
                case Type::Int64:
                {
                    int64_t value = 0;
                    
                    if(!StringUtility::ParseNumber<int64_t>(operandTextLHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextLHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueLeft, &value, sizeof(int64_t));
                    break;
                }
                case Type::UInt8:
                {
                    unsigned char value = static_cast<unsigned char>(operandTextLHS[0]);
                    memcpy(valueLeft, &value, sizeof(unsigned char));
                    break;
                }
                case Type::UInt16:
                {
                    uint16_t value = 0;
                    
                    if(!StringUtility::ParseNumber<uint16_t>(operandTextLHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextLHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueLeft, &value, sizeof(uint16_t));
                    break;
                }
                case Type::UInt32:
                {
                    uint32_t value = 0;
                    
                    if(!StringUtility::ParseNumber<uint32_t>(operandTextLHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextLHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueLeft, &value, sizeof(uint32_t));
                    break;
                }
                case Type::UInt64:
                {
                    uint64_t value = 0;
                    
                    if(!StringUtility::ParseNumber<uint64_t>(operandTextLHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextLHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueLeft, &value, sizeof(uint64_t));
                    break;
                }
                default:
                {                                            
                    break;
                }
            }

        }

        if(registerMap.count(operandTextRHS) > 0)
        {
            uint32_t reg = registerMap[operandTextRHS];
            memcpy(valueRight, &reg, sizeof(uint32_t));
            operandTypeRHS = OperandType::Register;
            valueRightType = Type::UInt32;
        }
        else if(labelMap.count(operandTextRHS) > 0)
        {
            uint32_t location = labelMap[operandTextRHS];
            memcpy(valueRight, &location, sizeof(uint32_t));
            operandTypeRHS = OperandType::IntegerLiteral;
            valueRightType = Type::UInt32;
        }
        else if(dataMap.count(operandTextRHS) > 0)
        {
            uint32_t variable = dataMap[operandTextRHS];
            memcpy(valueRight, &variable, sizeof(uint32_t));
            operandTypeRHS = OperandType::Variable;
            valueRightType = Type::UInt32;
        }
        else
        {
            uint64_t val = 0;
            if(!StringUtility::ParseNumberLexical<uint64_t>(operandTextRHS, val))
            {
                std::cout << "Failed to parse number '" << operandTextRHS << "' on line " << line.lineNumber << std::endl;
                return false;
            }

            valueRightType = GetNumberTypeFromText(operandTextRHS);
            operandTypeRHS = OperandType::IntegerLiteral;

            switch(valueRightType)
            {
                case Type::Int8:
                {
                    char value = static_cast<char>(operandTextRHS[0]);
                    memcpy(valueRight, &value, sizeof(char));
                    break;
                }
                case Type::Int16:
                {
                    int16_t value = 0;
                    
                    if(!StringUtility::ParseNumber<int16_t>(operandTextRHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextRHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueRight, &value, sizeof(int16_t));
                    break;
                }
                case Type::Int32:
                {
                    int32_t value = 0;
                    
                    if(!StringUtility::ParseNumber<int32_t>(operandTextRHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextRHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueRight, &value, sizeof(int32_t));
                    break;
                }
                case Type::Int64:
                {
                    int64_t value = 0;
                    
                    if(!StringUtility::ParseNumber<int64_t>(operandTextRHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextRHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueRight, &value, sizeof(int64_t));
                    break;
                }
                case Type::UInt8:
                {
                    unsigned char value = static_cast<unsigned char>(operandTextRHS[0]);
                    memcpy(valueRight, &value, sizeof(unsigned char));
                    break;
                }
                case Type::UInt16:
                {
                    uint16_t value = 0;
                    
                    if(!StringUtility::ParseNumber<uint16_t>(operandTextRHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextRHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueRight, &value, sizeof(uint16_t));
                    break;
                }
                case Type::UInt32:
                {
                    uint32_t value = 0;
                    
                    if(!StringUtility::ParseNumber<uint32_t>(operandTextRHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextRHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueRight, &value, sizeof(uint32_t));
                    break;
                }
                case Type::UInt64:
                {
                    uint64_t value = 0;
                    
                    if(!StringUtility::ParseNumber<uint64_t>(operandTextRHS, value))
                    {
                        std::cout << "Failed to parse number '" << operandTextRHS << "' on line " << line.lineNumber << std::endl;
                        return false; 
                    }

                    memcpy(valueRight, &value, sizeof(uint64_t));
                    break;
                }
                default:
                {                                            
                    break;
                }
            }

        }        

        assembly->instructions.push_back(Instruction(opcode, valueLeft, valueLeftType, operandTypeLHS, valueRight, valueRightType, operandTypeRHS));

        return true;
    }

    bool Compiler::ParseValueFromDirective(const std::string& text, size_t lineNumber, DefineDirective d, unsigned char* buffer, Type& type)
    {
        switch(d)
        {
            case DefineDirective::DB:
            {
                int16_t val = 0;

                if(!StringUtility::ParseNumber<int16_t>(text, val))
                {
                    std::cout << "Failed to parse number from text " << text << " on line" << lineNumber << std::endl;
                    return false;
                }
                
                if(val <= 0) //signed number
                {
                    char v = static_cast<char>(val);
                    memcpy(buffer, &v, sizeof(char));
                    type = Type::Int8;
                }
                else
                {
                    unsigned char v = static_cast<unsigned char>(val);
                    memcpy(buffer, &v, sizeof(unsigned char));
                    type = Type::UInt8;
                }
                break;
            }
            case DefineDirective::DW:
            {
                int32_t val = 0;

                if(!StringUtility::ParseNumber<int32_t>(text, val))
                {
                    std::cout << "Failed to parse number from text " << text << " on line" << lineNumber << std::endl;
                    return false;
                }
                
                if(val <= 0) //signed number
                {
                    int16_t v = static_cast<int16_t>(val);
                    memcpy(buffer, &v, sizeof(int16_t));
                    type = Type::Int16;
                }
                else
                {
                    uint16_t v = static_cast<uint16_t>(val);
                    memcpy(buffer, &v, sizeof(uint16_t));
                    type = Type::UInt16;
                }
                break;
            }
            case DefineDirective::DD:
            {
                //Treat as float
                if(StringUtility::Contains(text, "."))
                {
                    float val = 0;

                    if(!StringUtility::ParseNumber<float>(text, val))
                    {
                        std::cout << "Failed to parse number from text " << text << " on line" << lineNumber << std::endl;
                        return false;
                    }
                    
                    memcpy(buffer, &val, sizeof(float));
                    type = Type::Single;
                }
                else //Treat as int32/uint32
                {
                    int64_t val;

                    if(!StringUtility::ParseNumber<int64_t>(text, val))
                    {
                        std::cout << "Failed to parse number from text " << text << " on line" << lineNumber << std::endl;
                        return false;
                    }

                    if(val <= 0) //signed number
                    {
                        int32_t v = static_cast<int32_t>(val);
                        memcpy(buffer, &v, sizeof(int32_t));
                        type = Type::Int32;
                    }
                    else
                    {
                        uint32_t v = static_cast<uint32_t>(val);
                        memcpy(buffer, &v, sizeof(uint32_t));
                        type = Type::UInt32;
                    }                    
                }                

                break;
            }
            case DefineDirective::DQ:
            {
                //Treat as double
                if(StringUtility::Contains(text, "."))
                {
                    double val = 0;

                    if(!StringUtility::ParseNumber<double>(text, val))
                    {
                        std::cout << "Failed to parse number from text " << text << " on line" << lineNumber << std::endl;
                        return false;
                    }
                    
                    memcpy(buffer, &val, sizeof(double));
                    type = Type::Double;
                }
                else //Treat as int64/uint64
                {
                    uint64_t val;

                    if(!StringUtility::ParseNumber<uint64_t>(text, val))
                    {
                        std::cout << "Failed to parse number from text " << text << " on line" << lineNumber << std::endl;
                        return false;
                    }

                    if(val > 0 || val > 9223372036854775807) //unsigned number
                    {
                        memcpy(buffer, &val, sizeof(uint64_t));
                        type = Type::UInt64;
                    }
                    else
                    {
                        int64_t v = static_cast<int64_t>(val);
                        memcpy(buffer, &v, sizeof(int64_t));
                        type = Type::UInt32;
                    }                    
                }  
                break;
            }
        }
        return true;
    }

    Type Compiler::GetNumberTypeFromText(const std::string& text)
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
                return Type::Int8;            
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

}