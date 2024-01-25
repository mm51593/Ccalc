#include <memory>
#include <optional>
#include "tokenization/token/token.hpp"
#include "tokenizer.hpp"

class IdentifierTokenizer : public Tokenizer {
    public:
        std::optional<std::unique_ptr<Token>> try_tokenize(std::string::iterator iter, int &chars_read) const override;

    private:
        bool try_parse_identifier(std::string::iterator iter, int &chars_read, std::string &str) const;

};
