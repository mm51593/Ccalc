#pragma once
#include <memory>
#include <optional>
#include <string>

#include "state.hpp"
#include "tokenization/token/token.hpp"

class Tokenizer
{
    typedef std::shared_ptr<State<char>> StateMachine;

  protected:
    StateMachine initial_state;

  public:
    virtual std::optional<std::unique_ptr<Token>> try_tokenize(
        std::string::iterator iter, int &chars_read) const = 0;
    ~Tokenizer() {}
};
