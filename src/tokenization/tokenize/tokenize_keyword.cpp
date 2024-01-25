#include "tokenize_keyword.hpp"

std::optional<std::unique_ptr<Token>> KeywordTokenizer::try_tokenize(std::string::iterator iter, int &chars_read) const
{
    std::string str = this->try_parse_keyword(iter, chars_read);
    return this->resolve_keyword(str);
}

std::string KeywordTokenizer::try_parse_keyword(std::string::iterator iter, int &chars_read) const
{
    std::string str = "";

    bool loop = true;
    while (loop) {
        char next = *(iter++);

        if (!isalpha(next)) {
            loop = false;
        } else {
            str.push_back(next);
            chars_read++;
        }
    }

    return str;
}

std::unique_ptr<KeywordToken> KeywordTokenizer::resolve_keyword(std::string str) const
{
    KeywordToken::KeywordType kw = KeywordToken::from(str);

    if (kw == KeywordToken::Unknown) {
        return nullptr;
    } else {
        return std::make_unique<KeywordToken>(kw);
    }
}
