#include <optional>
#include <string>
#include <memory>
#include "tokenizer.hpp"
#include "constants.hpp"

class NumericTokenizer : public Tokenizer
{
public:
   std::optional<std::unique_ptr<Token>> try_tokenize(std::string::iterator iter, int &chars_read) const override;

private:
    bool try_parse_numeric(std::string::iterator iter, int &whole, int &decimal, int &chars_read) const;
    double numeric_parts_to_double(int whole, int decimal) const;
};
