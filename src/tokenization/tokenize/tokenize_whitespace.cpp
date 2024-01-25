#include "tokenize_whitespace.hpp"
#include <optional>

std::optional<std::unique_ptr<Token>> WhitespaceTokenizer::try_tokenize(std::string::iterator iter, int &chars_read) const
{
    int loops = 0;
    while (isspace(*(iter++))) {
        chars_read++;
        loops++;
    }

    if (loops) {
        return std::make_unique<WhitespaceToken>();
    } else {
        return nullptr;
    }
}
