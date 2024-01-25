#include <memory>
#include <optional>
#include "tokenization/token/token_operator.hpp"
#include "tokenizer.hpp"

class OperatorTokenizer : public Tokenizer {
    public:
        std::optional<std::unique_ptr<Token>> try_tokenize(std::string::iterator iter, int &chars_read) const override;

    private:
        std::string try_parse_operator(std::string::iterator iter, int &chars_read) const;
        std::unique_ptr<OperatorToken> resolve_operator(std::string str) const;
};
