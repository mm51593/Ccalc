#pragma once
#include "token.hpp"
#include <string>

class IdentifierToken : public Token
{
    private:
    std::string name;

    public:
    IdentifierToken(std::string name) : Token(Identifier), name(name)
    {
    }

    std::string *get_name()
    {
        return &this->name;
    }
};