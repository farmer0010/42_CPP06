#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string literal)
{
    double  val = 0.0;
    bool    is_Char = false;
    bool    is_Impossible = false;

    if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
    {
        val = static_cast<double>(literal[0]);
        is_Char = true;
    }
    else
    {
        char* endPtr;
        val = std::strtod(literal.c_str(), &endPtr);
        if (*endPtr != '\0' && std::string(endPtr) != "f")
        {
            val = std::numeric_limits<double>::quiet_NaN();
        }
    }

    if (std::isnan(val) || std::isinf(val))
        is_Impossible = true;

    std::cout << "char: ";
    if (is_Impossible || val < 0 || val > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

    std::cout << "int: ";
    if (is_Impossible
        || val < std::numeric_limits<int>::min()
        || val > std::numeric_limits<int>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
        std::cout << static_cast<int>(val) << std::endl;

    std::cout << "float: ";
    float fVal = static_cast<float>(val);

    if (std::isnan(fVal))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(fVal))
        std::cout << (fVal > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        std::cout << fVal;
        if (fVal - static_cast<int>(fVal) == 0)
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }

    std::cout << "double: ";
    if (std::isnan(val))
        std::cout << "nan" << std::endl;
    else if (std::isinf(val))
        std::cout << (val > 0 ? "+inf" : "-inf") << std::endl;
    else
    {
        std::cout << val;
        if (val - static_cast<int>(val) == 0)
            std::cout << ".0" << std::endl;
        else
            std::cout << std::endl;
    }
}
