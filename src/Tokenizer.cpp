#include "Tokenizer.hpp"

namespace StackVM
{
    char Tokenizer::whitespace[6] =
    {
        ' ',
        '\n',
        '\r',
        '\t',
        '\f',
        '\v'        
    };

    void Token_::Dump() const
    {
        int index = static_cast<int>(type);
        std::cout << "Token(" << tokenTypeString[index] << ", \"" << text << "\", " << lineNumber << ")\n";
    }    

    bool Tokenizer::Parse(const std::string& source, TokenList& tokens)
    {
        Token_ currentToken;
        currentToken.type = WHITESPACE;
        currentToken.lineNumber = 1;

        for(char character : source)
        {
            if(currentToken.type == STRING_ESCAPE_SEQUENCE)
            {
                switch(character)
                {
                    case 'n':
                        currentToken.text.append(1, '\n');
                        break;
                    case 'r':
                        currentToken.text.append(1, '\r');
                        break;
                    case 't':
                        currentToken.text.append(1, '\t');
                        break;
                    case 'f':
                        currentToken.text.append(1, '\f');
                        break;
                    case 'v':
                        currentToken.text.append(1, '\v');
                        break;
                    case '\\':
                        currentToken.text.append(1, '\\');
                        break;
                    default:
                        std::cout << "Unknow escape sequence: \\" << character << " on line " << currentToken.lineNumber << std::endl;
                        return false;
                }

                currentToken.type = STRING_LITERAL;
                continue;
            }
            else if(currentToken.type == POTENTIAL_COMMENT)
            {
                currentToken.type = COMMENT;
                continue;
            }

            switch(character)
            {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                {
                    if(currentToken.type == WHITESPACE)
                    {
                        currentToken.type = INTEGER_LITERAL;
                        currentToken.text.append(1, character);
                    }
                    else if(currentToken.type == POTENTIAL_FLOATING_POINT)
                    {
                        currentToken.type = FLOATING_POINT_LITERAL;
                        currentToken.text.append(1, character);

                    }
                    else
                    {
                        currentToken.text.append(1, character);
                    }
                    break;
                }
                case '.':
                {
                    if(currentToken.type == WHITESPACE)
                    {
                        currentToken.type = POTENTIAL_FLOATING_POINT;
                        currentToken.text.append(1, character);
                    }
                    else if(currentToken.type == INTEGER_LITERAL)
                    {
                        currentToken.type = FLOATING_POINT_LITERAL;
                    }
                    else if(currentToken.type == STRING_LITERAL)
                    {
                        currentToken.text.append(1, character);
                    }                   
                    else
                    {
                        EndToken(tokens, currentToken);
                        currentToken.type = OPERATOR;
                        currentToken.text.append(1, character);
                        EndToken(tokens, currentToken);
                    }
                    break;
                }
                case ',':
                case ':':
                case '-':
                {
                    if(currentToken.type != STRING_LITERAL)
                    {
                        EndToken(tokens, currentToken);
                        currentToken.type = OPERATOR;
                        currentToken.text.append(1, character);
                        EndToken(tokens, currentToken);
                    }
                    else
                    {
                        currentToken.text.append(1, character);
                    }
                    break;
                }
                case ' ':                    
                case '\t':
                case '\f':
                case '\v':
                {
                    EndToken(tokens, currentToken);
                    break;
                }
                case '\n':
                case '\r':                
                {
                    EndToken(tokens, currentToken);
                    ++currentToken.lineNumber;
                    break;
                }
                case '"':
                {
                    if(currentToken.type != STRING_LITERAL)
                    {
                        EndToken(tokens, currentToken);
                        currentToken.type = STRING_LITERAL;
                        currentToken.text.append(1, character);
                    }
                    else if(currentToken.type == STRING_LITERAL)
                    {
                        EndToken(tokens, currentToken);
                    }
                    break;                    
                }
                case '\\':
                {
                    if(currentToken.type == STRING_LITERAL)
                    {
                        currentToken.type = STRING_ESCAPE_SEQUENCE;
                    }
                    else
                    {
                        EndToken(tokens, currentToken);
                        currentToken.type = OPERATOR;
                        currentToken.text.append(1, character);
                        EndToken(tokens, currentToken);
                    }
                    break;                      
                }                
                case '\'':
                {
                    if(currentToken.type != CHARACTER_LITERAL)
                    {
                        EndToken(tokens, currentToken);
                        currentToken.type = CHARACTER_LITERAL;
                        currentToken.text.append(1, character);
                    }
                    else if(currentToken.type == CHARACTER_LITERAL)
                    {
                        EndToken(tokens, currentToken);
                    }
                    break;                     
                }
                case ';':
                {
                    if(currentToken.type == STRING_LITERAL)
                    {
                        currentToken.text.append(1, character);
                    }
                    else if(currentToken.type == POTENTIAL_COMMENT)
                    {
                        currentToken.type = COMMENT;
                        currentToken.text.erase();
                    }
                    else
                    {
                        currentToken.type = POTENTIAL_COMMENT;
                        currentToken.text.append(1, character);
                    }
                    break;
                }
                default:
                {
                    if( currentToken.type == WHITESPACE ||
                        currentToken.type == INTEGER_LITERAL ||
                        currentToken.type == FLOATING_POINT_LITERAL)
                    {
                        EndToken(tokens, currentToken);
                        currentToken.type = IDENTIFIER;
                        currentToken.text.append(1, character);
                    }
                    else
                    {
                        currentToken.text.append(1, character);
                    }
                    break;
                }
            }
        }

        EndToken(tokens, currentToken);

        return true;
    }

    void Tokenizer::EndToken(TokenList& tokens, Token_& token)
    {
        if(token.type == COMMENT)
        {
            std::cout << "Ignoring comment: " << token.text <<  " on line " << token.lineNumber << std::endl;
        }
        else if(token.type != WHITESPACE)
        {
            tokens.push_back(token);
        }

        if(token.type == POTENTIAL_FLOATING_POINT)
        {
            if(token.text.compare(".") == 0)
            {
                token.type = OPERATOR;
            }
            else
            {
                token.type = FLOATING_POINT_LITERAL;
            }
        }

        token.type = WHITESPACE;
        token.text.erase();
    }
}