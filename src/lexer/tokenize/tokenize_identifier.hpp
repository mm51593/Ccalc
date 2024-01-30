#include <memory>
#include <optional>

#include "lexer/token/token.hpp"
#include "tokenizer.hpp"

class IdentifierTokenizer : public Tokenizer
{
  public:
    std::optional<std::unique_ptr<Token>> try_tokenize(
        std::string::iterator iter, int &chars_read) const override;
    IdentifierTokenizer();

  private:
    std::string try_parse_identifier(std::string::iterator iter,
                                     int &chars_read) const;
};
