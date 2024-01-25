#pragma once
#include "token.hpp"

class NumericToken : public Token {
    private:
    double value;

    public:
    NumericToken(double value) : Token(Numeric), value(value) {}

    double get_value() {
        return this->value;
    }
};