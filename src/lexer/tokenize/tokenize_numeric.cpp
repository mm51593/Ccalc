#include "tokenize_numeric.hpp"

#include <cctype>
#include <iostream>
#include <memory>
#include <optional>

#include "machine.hpp"
#include "state.hpp"
#include "lexer/token/token_numeric.hpp"

NumericTokenizer::NumericTokenizer()
{
    auto whole = std::make_shared<State<char>>();
    auto decimal = std::make_shared<State<char>>();

    whole->add_transition([](char t) { return isdigit(t); }, whole);
    whole->add_transition([](char t) { return t == '.'; }, decimal);

    decimal->add_transition([](char t) { return isdigit(t); }, decimal);

    this->initial_state = whole;
}

std::optional<std::unique_ptr<Token>> NumericTokenizer::try_tokenize(
    std::string::iterator iter, int &chars_read) const
{
    int whole = 0;
    int decimal = 0;

    if (!try_parse_numeric(iter, whole, decimal, chars_read)) {
        return std::nullopt;
    }

    double value = numeric_parts_to_double(whole, decimal);

    return std::make_unique<NumericToken>(value);
}

bool NumericTokenizer::try_parse_numeric(std::string::iterator iter, int &whole,
                                         int &decimal, int &chars_read) const
{
    DFA<char> machine(this->initial_state);
    int &write_to = whole;

    bool loops = false;
    
    do {
        char next = *iter++;
        machine.step(next);

        if (machine.is_valid()) {
            if (next == '.') {
                write_to = decimal;
            } else {
                write_to *= 10;
                write_to += next - '0';
            }

            chars_read++;
            loops = true;
        }
    } while (machine.is_valid()); 

    return loops;
}

double NumericTokenizer::numeric_parts_to_double(int whole, int decimal) const
{
    double value = 0;

    while (decimal > 0) {
        value += decimal % RADIX;
        value *= 1.f / RADIX;
    }

    // add whole
    value += whole;

    return value;
}
