#pragma once
#include <string>

#include "token.hpp"

class IdentifierToken : public Token
{
  private:
    std::string name;

  public:
    IdentifierToken(std::string name) : Token(Identifier), name(name) {}

    std::string *get_name() { return &this->name; }
};
