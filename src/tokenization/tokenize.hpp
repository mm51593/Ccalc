#pragma once

#include <string>
#include <vector>

#include "tokenize/tokenize_whitespace.hpp"
#include "tokenize/tokenize_numeric.hpp"
#include "tokenize/tokenize_operator.hpp"
#include "tokenize/tokenize_keyword.hpp"
#include "tokenize/tokenize_identifier.hpp"

Tokenizer *const wsTokenizer = new WhitespaceTokenizer();
Tokenizer *const numTokenizer = new NumericTokenizer();
Tokenizer *const opTokenizer = new OperatorTokenizer();
Tokenizer *const kwTokenizer = new KeywordTokenizer();
Tokenizer *const idTokenizer = new IdentifierTokenizer();

const Tokenizer *const tokenizers[] = {opTokenizer, numTokenizer, opTokenizer, kwTokenizer, idTokenizer};

void tokenize_line(std::string &line, std::vector<Token*> &buffer);
