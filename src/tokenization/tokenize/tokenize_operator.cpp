#include "tokenize_operator.hpp"

std::optional<std::unique_ptr<Token>> OperatorTokenizer::try_tokenize(std::string::iterator iter, int &chars_read) const
{
    std::string str = this->try_parse_operator(iter, chars_read);
    return this->resolve_operator(str);
}

std::string OperatorTokenizer::try_parse_operator(std::string::iterator iter, int &chars_read) const
{
    std::string str = "";

    bool loop = true;
    while (loop) {
        char next = *(iter++);

        if (isspace(next) || next == '\0') {
            loop = false;
        }
        else {
            str.push_back(next);
            chars_read++;
        }
    }

    return str;
}

std::unique_ptr<OperatorToken> OperatorTokenizer::resolve_operator(std::string str) const
{
    OperatorToken::OperatorType op = OperatorToken::from(str);
    
    if (op == OperatorToken::Unknown) {
        return nullptr;
    }
    else {
        return std::make_unique<OperatorToken>(op);
    }
}
