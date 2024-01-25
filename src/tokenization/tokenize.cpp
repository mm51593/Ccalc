#include <iostream>
#include "tokenize.hpp"

void tokenize_line(std::string &line, std::vector<Token*> &buffer) {
    auto iter = line.begin();

    int chars_read;
    std::optional<std::unique_ptr<Token>> token_ptr;
    for (auto it : tokenizers) {
        chars_read = 0;
        token_ptr = it->try_tokenize(iter, chars_read);
        if (token_ptr.has_value()) {
            std::cout << "success" << " " << static_cast<int>(token_ptr.value()->get_type()) << std::endl;
            break;
        }
    }
    std::cout << chars_read << std::endl;
}
