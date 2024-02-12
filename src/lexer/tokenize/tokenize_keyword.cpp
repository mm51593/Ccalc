#include "tokenize_keyword.hpp"

#include <cctype>
#include <memory>
#include <optional>

#include "machine.hpp"
#include "src/dsm/dfa/dfa_state.hpp"

KeywordTokenizer::KeywordTokenizer()
{
    auto initial = std::make_shared<DFAState<char>>();

    initial->add_transition([](char t) { return isalpha(t); }, initial);

    this->initial_state = initial;
}

std::optional<std::unique_ptr<Token>> KeywordTokenizer::try_tokenize(
    std::string::iterator iter, int &chars_read) const
{
    std::string str = this->try_parse_keyword(iter, chars_read);
    return this->resolve_keyword(str);
}

std::string KeywordTokenizer::try_parse_keyword(std::string::iterator iter,
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

std::optional<std::unique_ptr<KeywordToken>> KeywordTokenizer::resolve_keyword(
    std::string str) const
{
    KeywordToken::KeywordType kw = KeywordToken::from(str);

    if (kw == KeywordToken::Unknown) {
        return std::nullopt;
    } else {
        return std::make_unique<KeywordToken>(kw);
    }
}
