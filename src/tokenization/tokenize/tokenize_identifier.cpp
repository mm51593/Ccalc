#include "tokenize_identifier.hpp"
#include "tokenization/token/token_identifier.hpp"

std::optional<std::unique_ptr<Token>> IdentifierTokenizer::try_tokenize(std::string::iterator iter, int &chars_read) const
{
    std::string str = "";
    if (this->try_parse_identifier(iter, chars_read, str)) {
        return std::make_unique<IdentifierToken>(str);
    } else {
        return nullptr;
    }
}

bool IdentifierTokenizer::try_parse_identifier(std::string::iterator iter, int &chars_read, std::string &str) const
{
    enum State {
        Empty,
        UnderscoreStart,
        Other
    };

    enum State state = Empty;
    bool loop = true;
    while (loop) {
        char next = *(iter++);

        switch (state) {
            case Empty:
                if (next == '_') {
                    state = UnderscoreStart;
                }
                else if (isalpha(next)) {
                    state = Other;
                }
                else {
                    return false;
                }
                break;
            case UnderscoreStart:
                if (isalpha(next)) {
                    state = Other;
                }
                else {
                    return false;
                }
                break;
            case Other:
                if (isspace(next) || next == '\0') {
                    return true;
                } else if (!(isalnum(next) || next == '_')) {
                    return false;
                }
                break;
        }
        str.push_back(next);

        chars_read++;
    }

    return true;
}
