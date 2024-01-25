#include <iostream>
#include <string>
#include <vector>

#include "tokenization/tokenize.hpp"

int main(void)
{
    int num;
    std::string line;

    std::getline(std::cin, line);

    std::vector<Token*> vec;

    tokenize_line(line, vec);
    return 0;
}
