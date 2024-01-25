#include "tokenize_numeric.hpp"
#include <optional>
#include "tokenization/token/token_numeric.hpp"

std::optional<std::unique_ptr<Token>> NumericTokenizer::try_tokenize(std::string::iterator iter, int &chars_read) const
{
    int whole = 0;
    int decimal = 0;

    if (!try_parse_numeric(iter, whole, decimal, chars_read))
    {
        return nullptr;
    }

    double value = numeric_parts_to_double(whole, decimal);

    return std::make_unique<NumericToken>(value);
}

bool NumericTokenizer::try_parse_numeric(std::string::iterator iter, int &whole, int &decimal, int &chars_read) const
{
    enum State
    {
        Empty,
        Whole,
        Decimal
    };

    State state = Empty;
    bool loop = true;
    while (loop)
    {
        char next = *(iter++);

        switch (state)
        {
        case Empty:
            if (isdigit(next))
            {
                // add into whole
                whole += next - '0';
                state = Whole;
            }
            else if (next == '.')
            {
                // no whole, e.g. .123
                state = Decimal;
            }
            else
            {
                // not a number, return early
                return false;
            }
            break;

        case Whole:
            if (isdigit(next))
            {
                // add into whole
                whole *= RADIX;
                whole += next - '0';
            }
            else if (next == '.')
            {
                // decimal point, switch to Decimal
                state = Decimal;
            }
            else
            {
                // end reached
                loop = false;
            }
            break;

        case Decimal:
            if (isdigit(next))
            {
                // add into decimal
                decimal *= RADIX;
                decimal += next - '0';
            }
            else if (next == '.')
            {
                // two decimal points, return early
                return false;
            }
            else
            {
                // end reached
                loop = false;
            }
        }

        chars_read++;
    }

    return true;
}

double NumericTokenizer::numeric_parts_to_double(int whole, int decimal) const
{
    double value = 0;

    while (decimal > 0)
    {
        value += decimal % RADIX;
        value *= 1.f / RADIX;
    }

    // add whole
    value += whole;

    return value;
}
