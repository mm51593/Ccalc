#include <memory>
#include <optional>
#include <string>

#include "tokenization/token/token.hpp"
#include "tokenization/tokenize/tokenizer.hpp"

class WhitespaceToken : public Token
{
   public:
    WhitespaceToken() : Token(Whitespace) {}
};

class WhitespaceTokenizer : public Tokenizer
{
   public:
    std::optional<std::unique_ptr<Token>> try_tokenize(std::string::iterator iter,
                                        int &chars_read) const override;
};
