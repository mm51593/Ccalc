#pragma once

#include <memory>
#include <string>
#include <vector>

#include "tokenization/token/token.hpp"
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

const Tokenizer *const tokenizers[] = {wsTokenizer, numTokenizer, opTokenizer, kwTokenizer, idTokenizer};

void tokenize_line(std::string &line, std::vector<std::unique_ptr<Token>> &buffer);
