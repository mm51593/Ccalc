#pragma once
#include <map>
#include <string>
#include "token.hpp"

class KeywordToken : public Token
{
public:
    enum KeywordType
    {
        If,
        Else,
        Begin,
        End,
        For,
        While,
        Unknown
    };

    static const std::map<std::string, KeywordType> kw_mapping;

private:
    KeywordType kw;

public:
    KeywordToken(KeywordType kw) : Token(Keyword), kw(kw)
    {
    }

    KeywordType get_kw()
    {
        return this->kw;
    }

    static KeywordType from(std::string str)
    {
        KeywordType kw;
        try
        {
            kw = KeywordToken::kw_mapping.at(str);
        }
        catch(const std::exception& e)
        {
            kw = Unknown;
        }
        

        return kw;
    }
};