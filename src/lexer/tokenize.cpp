#include "tokenize.hpp"

#include <exception>
#include <memory>
#include <vector>

#include "lexer/token/token.hpp"

void tokenize_line(std::string &line,
                   std::vector<std::unique_ptr<Token>> &buffer)
{
    auto iter = line.begin();

    int chars_read;
    std::optional<std::unique_ptr<Token>> token_ptr;

    do {
        int loop = 0;
        for (auto it : tokenizers) {
            chars_read = 0;
            token_ptr = it->try_tokenize(iter, chars_read);
            if (token_ptr.has_value()) {
                buffer.push_back(std::move(token_ptr.value()));
                iter += chars_read;
                break;
            }
        }
        if (chars_read == 0) {
            throw std::exception();
        }
    } while (iter != line.end());
}
