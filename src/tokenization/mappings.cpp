#include "tokenization/token/token_keyword.hpp"
#include "tokenization/token/token_operator.hpp"

const std::map<std::string, KeywordToken::KeywordType> KeywordToken::kw_mapping = {
    {"if", If},
    {"else", Else},
    {"begin", Begin},
    {"end", End},
    {"for", For},
    {"while", While},
};

const std::map<std::string, OperatorToken::OperatorType> OperatorToken::op_mapping = {
    {"+", Add},
    {"-", Subtract},
    {"*", Multiply},
    {"/", Divide},
    {"(", LParen},
    {")", RParen},
    {"==", Equal},
    {"!=", NotEqual},
    {"<", LessThan},
    {"<=", LessThanEqual},
    {">", GreaterThan},
    {">=", GreaterThanEqual}};
