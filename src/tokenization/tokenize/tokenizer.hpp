#pragma once
#include <memory>
#include <optional>
#include <string>
#include "tokenization/token/token.hpp"

class Tokenizer {
    public:
        virtual std::optional<std::unique_ptr<Token>> try_tokenize(std::string::iterator iter, int &chars_read) const = 0;
        ~Tokenizer() {}
};
