#pragma once
#include <memory>
#include <optional>
#include <string>

#include "src/dsm/dfa/dfa_state.hpp"
#include "state.hpp"
#include "lexer/token/token.hpp"

class Tokenizer
{
    typedef std::shared_ptr<DFAState<char>> StateMachine;

  protected:
    StateMachine initial_state;

  public:
    virtual std::optional<std::unique_ptr<Token>> try_tokenize(
        std::string::iterator iter, int &chars_read) const = 0;
    ~Tokenizer() {}
};
