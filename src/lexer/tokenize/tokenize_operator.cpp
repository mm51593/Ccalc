#include "tokenize_operator.hpp"

#include <cctype>
#include <memory>
#include <optional>

#include "machine.hpp"
#include "state.hpp"

OperatorTokenizer::OperatorTokenizer()
{
    auto initial = std::make_shared<State<char>>();

    initial->add_transition([](char t) { return !(isspace(t) || t == '\0'); }, initial);

    this->initial_state = initial;
}

std::optional<std::unique_ptr<Token>> OperatorTokenizer::try_tokenize(
    std::string::iterator iter, int &chars_read) const
{
    std::string str = this->try_parse_operator(iter, chars_read);
    return this->resolve_operator(str);
}

std::string OperatorTokenizer::try_parse_operator(std::string::iterator iter,
                                                  int &chars_read) const
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
    } while (machine.is_valid());

    return str;
}

std::optional<std::unique_ptr<OperatorToken>> OperatorTokenizer::resolve_operator(
    std::string str) const
{
    OperatorToken::OperatorType op = OperatorToken::from(str);

    if (op == OperatorToken::Unknown) {
        return std::nullopt;
    } else {
        return std::make_unique<OperatorToken>(op);
    }
}
