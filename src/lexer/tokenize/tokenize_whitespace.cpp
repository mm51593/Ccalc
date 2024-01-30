#include "tokenize_whitespace.hpp"

#include <cctype>
#include <memory>
#include <optional>

#include "machine.hpp"
#include "state.hpp"

WhitespaceTokenizer::WhitespaceTokenizer()
{
    auto initial = std::make_shared<State<char>>();

    initial->add_transition([](char t) { return isspace(t); }, initial);

    this->initial_state = initial;
}

std::optional<std::unique_ptr<Token>> WhitespaceTokenizer::try_tokenize(
    std::string::iterator iter, int &chars_read) const
{
    DFA<char> machine(this->initial_state);
    int loops = 0;

    do {
        machine.step(*iter++);

        if (machine.is_valid()) {
            chars_read++;
            loops++;
        }
    } while(machine.is_valid());

    if (loops) {
        return std::make_unique<WhitespaceToken>();
    } else {
        return std::nullopt;
    }
}
