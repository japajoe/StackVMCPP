#include "Lexer.hpp"
#include "StringUtility.hpp"
#include <iostream>

namespace StackVM
{
    std::vector<Token> Lexer::CreateTokens(const std::string& source)
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



        std::vector<Token> tokens;
        return tokens;
    }

    void Lexer::RemoveWhiteSpace(std::vector<LineInfo>& lines)
    {
        for(size_t i = 0; i < lines.size(); i++)
        {
            std::string code = StringUtility::TrimWhiteSpace(lines[i].text);
            lines[i].text = code;
        }        
    }

    void Lexer::RemoveEmptyLines(std::vector<LineInfo>& lines)
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

    void Lexer::RemoveCommentLines(std::vector<LineInfo>& lines)
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

    void Lexer::RemoveTrailingComments(std::vector<LineInfo>& lines)
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
}