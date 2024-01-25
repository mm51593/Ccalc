#pragma once

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
};