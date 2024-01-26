#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "tokenization/token/token.hpp"
#include "tokenization/tokenize.hpp"

int main(void)
{
    int num;
    std::string line;

    std::getline(std::cin, line);

    std::vector<std::unique_ptr<Token>> vec;

    tokenize_line(line, vec);

    for (auto& tk : vec)
    {
        std::cout << tk->to_string() << " ";
    }
    std::cout << "\n";
    return 0;
}
