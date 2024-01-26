#pragma once

#include <string>
enum TokenType
{
    Whitespace,
    Numeric,
    Identifier,
    Keyword,
    Operator
};

class Token
{
protected:
    TokenType type;
    Token(TokenType type) : type(type) {}

public:
    TokenType get_type()
    {
        return this->type;
    }

    std::string to_string() {
        std::string type;
        switch (this->type) {   
            case Whitespace:
                type = "TokenWhitespace";
                break;
            case Numeric:
                type = "TokenNumeric";
                break;
            case Identifier:
                type = "TokenIdentifier";
                break;
            case Keyword:
                type = "TokenKeyword";
                break;
            case Operator:
                type = "TokenOperator";
                break;
            default:
                type = "TokenUnknown";
        }

        return type;
    }
};
