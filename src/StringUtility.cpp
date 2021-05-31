#include "StringUtility.hpp"
#include <algorithm>
#include <locale>
#include <cstdlib> //std::strtol

namespace StackVM
{
    const std::string WHITESPACE = " \n\r\t\f\v";

    std::string StringUtility::Replace(std::string& haystack, const std::string& needle, const std::string& replacement)
    {
        size_t start_pos = 0;
        while((start_pos = haystack.find(needle, start_pos)) != std::string::npos) {
            haystack.replace(start_pos, needle.length(), replacement);
            start_pos += replacement.length(); // Handles case where 'to' is a substring of 'from'
        }
        return haystack;
    }

    std::vector<std::string> StringUtility::Split(const std::string& text, const char* delimiter)
    {
        std::vector<std::string> components; // Empty on creation
        char characters[64000];

        strncpy(characters, text.c_str(), sizeof(characters));
        characters[sizeof(characters) - 1] = 0;
        char* sPointer = strtok(characters, delimiter);	
        int paramCount = 0;

        while(sPointer != NULL)
        {
            std::string component(sPointer);
            components.push_back(sPointer);
            sPointer = strtok(NULL, delimiter);
            paramCount++;		
        }

        free(sPointer);

        return components;
    }

    std::vector<std::string> StringUtility::Split(const std::string& text, char delimiter) 
    {
        std::istringstream stream(text);
        std::vector<std::string> tokens;
        std::string token;

        while(std::getline(stream, token, delimiter)) 
        {
            tokens.push_back(token);
        }

        if(text.back() == delimiter)
            tokens.push_back("");

        return tokens;
    }

    bool StringUtility::StartsWith(const std::string& haystack, const std::string& needle)
    {
        if(needle.length() > haystack.length())
            return false;

        for(size_t i = 0; i < needle.length(); i++)
        {
            if(haystack[i] != needle[i])
                return false;
        }
        return true;
    }

    bool StringUtility::EndsWith(const std::string& haystack, const std::string& needle)
    {
        if(needle.length() > haystack.length())
            return false;
        
        size_t startIndex = haystack.length() - needle.length();
        size_t endIndex = startIndex + needle.length();
        
        size_t index = 0;

        for(size_t i = startIndex; i < endIndex; i++)
        {
            if(haystack[i] != needle[index])
                return false;
            index++;
        }

        return true;
    }

    bool StringUtility::StartsWithNumber(const std::string& text)
    {
        char x = '0';

        for(int i = 0; x < 10; x++)
        {
            if(text[0] == x)
                return true;
            x++;
        }

        return false;
    }

    int StringUtility::GetLines(const std::string& text)
    {
        int lineCount = std::count(text.begin(), text.end(), '\n');
        
        return lineCount+1;
    }

    bool StringUtility::Contains(const std::string& haystack, const std::string& needle)
    {	
        if (haystack.find(needle) != std::string::npos) 
        {
            return true;
        }
        return false;
    }

    int StringUtility::Count(const std::string& haystack, const std::string& needle)
    {
        int count = 0;
        if(needle.length() > haystack.length())
            return 0;
        
        int characterIndex = 0;
        int needleSize = needle.length();

        for(size_t i = 0; i < haystack.length(); i++)
        {
            if(haystack[i] == needle[characterIndex])
            {
                characterIndex++;
            }
            else
            {
                characterIndex = 0;
            }		

            if(characterIndex == needleSize)
            {
                characterIndex = 0;
                count++;
            }
        }

        return count;
    }

    std::vector<int> StringUtility::CountWithOffset(const std::string& haystack, const std::string& needle)
    {
        std::vector<int> offsets;

        if(needle.length() > haystack.length())
            return offsets;
        
        int characterIndex = 0;
        int needleSize = needle.length();

        for(size_t i = 0; i < haystack.length(); i++)
        {
            if(haystack[i] == needle[characterIndex])
            {
                characterIndex++;
            }
            else
            {
                characterIndex = 0;
            }		

            if(characterIndex == needleSize)
            {
                int offset = (i + 1) - needleSize;
                offsets.push_back(offset);
                characterIndex = 0;
            }
        }

        return offsets;	
    }

    std::string StringUtility::GetFileNameWithExtension(const std::string& text)
    {
        std::string filename;
        auto components = StringUtility::Split(text, '/');

        if(components.size() > 0)
        {
            size_t last = components.size() - 1;
            filename = components[last];
        }

        return filename;
    }

    std::string StringUtility::GetFileExtension(const std::string& text, bool includePeriod)
    {
        std::string extension;

        auto components = StringUtility::Split(text, ".");
        if(components.size() > 1)
        {
            size_t last = components.size() - 1;
            extension = components[last];
            if(includePeriod)
                extension = "." + extension;		
        }
        
        return extension;
    }

    std::string StringUtility::ToLower(const std::string& text)
    {
        std::locale loc;
        std::string t;
        
        for (std::string::size_type i = 0; i < text.length(); ++i)
        {
            t += std::tolower(text[i],loc);
        }
        return t;
    }

    std::string StringUtility::ToLowerCase(const std::string& text)
    {
        std::string new_string{ text };
        std::transform(new_string.begin(), new_string.end(), new_string.begin(), [](unsigned char character) {
            return std::tolower(character);
        });

        return new_string;
    }

    std::string StringUtility::ToUpperCase(const std::string& text)
    {
        std::string new_string{ text };
        std::transform(new_string.begin(), new_string.end(), new_string.begin(), [](unsigned char character) {
            return std::toupper(character);
        });

        return new_string;
    }

    std::string StringUtility::TrimLeadingWhiteSpace(const std::string& text)
    {
        size_t start = text.find_first_not_of(WHITESPACE);
        return (start == std::string::npos) ? "" : text.substr(start);
    }
    std::string StringUtility::TrimTrailingWhiteSpace(const std::string& text)
    {
        size_t end = text.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : text.substr(0, end + 1);
    }

    std::string StringUtility::TrimWhiteSpace(const std::string& text)
    {
        return TrimTrailingWhiteSpace(TrimLeadingWhiteSpace(text));
    }

    int StringUtility::ToInt32(const std::string& text)
    {
        int v = 0;
        char* end;
        v = std::strtol(text.c_str(), &end, 10);
        return v;
    }

    long StringUtility::ToInt64(const std::string& text)
    {
        std::stringstream buffer(text);
        long value = 0;
        buffer >> value;
        return value;
    }
}