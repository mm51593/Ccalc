#include "tokenize_identifier.hpp"

#include <cctype>
#include <memory>
#include <optional>
#include <string>

#include "machine.hpp"
#include "state.hpp"
#include "lexer/token/token_identifier.hpp"

IdentifierTokenizer::IdentifierTokenizer()
{
    auto empty = std::make_shared<State<char>>();
    auto underscore_start = std::make_shared<State<char>>();
    auto other = std::make_shared<State<char>>();

    empty->add_transition([](char t) { return isalpha(t); }, other);
    empty->add_transition([](char t) { return t == '_'; }, underscore_start);

    other->add_transition([](char t) { return isalnum(t) || t == '_'; }, other);

    this->initial_state = empty;
}

std::optional<std::unique_ptr<Token>> IdentifierTokenizer::try_tokenize(
    std::string::iterator iter, int &chars_read) const
{
    std::string str = this->try_parse_identifier(iter, chars_read);
    if (str.length() == 0) {
        return std::nullopt;
    } else {
        return std::make_unique<IdentifierToken>(str);
    }
}

std::string IdentifierTokenizer::try_parse_identifier(
    std::string::iterator iter, int &chars_read) const
{
    std::string str = "";
    DFA<char> machine(this->initial_state);

    do {
        char next = *iter++;
        machine.step(next);

        if (machine.is_valid()) {
            str.push_back(next);
            chars_read++;
        }
    } while(machine.is_valid());


    return str;
}
