#include <memory>
#include <optional>
#include "tokenization/token/token_keyword.hpp"
#include "tokenizer.hpp"

class KeywordTokenizer : public Tokenizer {
    public:
        std::optional<std::unique_ptr<Token>> try_tokenize(std::string::iterator iter, int &chars_read) const override;

    private:
        std::string try_parse_keyword(std::string::iterator iter, int &chars_read) const;
        std::unique_ptr<KeywordToken> resolve_keyword(std::string str) const;
};
