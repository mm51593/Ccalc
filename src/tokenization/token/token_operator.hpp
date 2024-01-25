#pragma once
#include <map>
#include <string>
#include "token.hpp"

class OperatorToken : public Token
{
public:
    enum OperatorType
    {
        Add,
        Subtract,
        Multiply,
        Divide,
        LParen,
        RParen,
        Equal,
        NotEqual,
        LessThan,
        LessThanEqual,
        GreaterThan,
        GreaterThanEqual,
        Unknown
    };

    static const std::map<std::string, OperatorType> op_mapping;

private:
    OperatorType op;

public:
    OperatorToken(OperatorType op) : Token(Operator), op(op)
    {
    }

    OperatorType get_op()
    {
        return this->op;
    }

    static OperatorType from(std::string str)
    {
        OperatorType op;
        try
        {
            op = OperatorToken::op_mapping.at(str);
        }
        catch (...)
        {
            op = Unknown;
        }

        return op;
    }
};