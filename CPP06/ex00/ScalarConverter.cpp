#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &arg)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = arg;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &arg)
{
    std::cout << "ScalarConverter assignation operator called" << std::endl;
    if (this != &arg){
        return *this;
    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

//--------------------------------------------------------------------

static bool isInteger(std::string str) {
    char* end;
    long value = strtol(str.c_str(), &end, 10); // Преобразование строки в длинное целое число с помощью функции strtol. Функция принимает строку, указатель на end и основание системы счисления (10 для десятичной системы).
    return end != str.c_str() && *end == '\0' && value >= INT_MIN && value <= INT_MAX; //Возвращает true, если:end не указывает на начало строки (то есть было преобразовано хотя бы одно число),*end равен нулевому символу (строка полностью преобразована),значение находится в пределах допустимого диапазона для int.
}

static bool isFloat(std::string str) {
    if (str[str.size()-1] != 'f')
        return false;
    if (std::isnan(std::atof(str.c_str())) || std::isinf(std::atof(str.c_str())))
        return true;
    str.erase(str.size() - 1);
    std::stringstream ss(str);
    float f;
    ss >> f;
    return ss.eof() && !ss.fail();
}

static bool isDouble(std::string& str) {
    char *end;
    size_t position = str.find('.');
    double i = strtod(str.c_str(), &end);
    if (((position == std::string::npos) || *end != '\0') && (!(std::isnan(i) || std::isinf(i))))
        return false;
    return true;
}

static std::string getType(std::string input)
{
    if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) return ("char");
    if (isInteger(input)) return ("int");    
    if (isFloat(input)) return ("float");
    if (isDouble(input)) return ("double");
    return ("Invalid");
} 

static void printInt(std::string input)
{
    //std::cout << "original type -> int: " << input << std::endl;
    //int i = std::stoi(input); c11
    int i = std::atoi(input.c_str());
    std::cout << "char: ";
    if (i >= 32 && i <= 126)
        std::cout << static_cast<char>(i) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max()) //if (i >= INT_MIN && i <= INT_MAX)
        std::cout << static_cast<int>(i) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void printFloat(std::string input)
{
    //std::cout << "original type -> float: " << input << std::endl;
    float f = std::atof(input.c_str());
    std::cout << "char: ";
    if (!isascii(static_cast<int>(f)))
        std::cout << "impossible" << std::endl;
    else if (f >= 32 && f <= 126)
        std::cout << static_cast<char>(f) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max()) //if (i >= INT_MIN && i <= INT_MAX)
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: " << "impossible" << std::endl;
    if (f - static_cast<int>(f) == 0 && !std::isnan(f) && !std::isinf(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
		std::cout << "float: " << f << "f" << std::endl;
    if (f - static_cast<int>(f) == 0 && !std::isnan(f) && !std::isinf(f))
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    else    
        std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void printChar(std::string input)
{
    //std::cout << "original type -> char: " << input[0] << std::endl;
    char c = input[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printDouble(std::string input)
{
    //std::cout << "original type -> double: " << input << std::endl;
    double d = std::atof(input.c_str());
    std::cout << "char: ";
    if (!isascii(static_cast<int>(d)))
        std::cout << "impossible" << std::endl;
    else if (d >= 32 && d <= 126)
        std::cout << static_cast<char>(d) << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (d - static_cast<int>(d) == 0 && !std::isnan(d) && !std::isinf(d))
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
    else
        std::cout << "float: "<< static_cast<float>(d) << "f" << std::endl;
    if (d - static_cast<int>(d) == 0 && !std::isnan(d) && !std::isinf(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    std::string type = getType(input);
    if (type == "int")
        printInt(input);
    else if (type == "float")
        printFloat(input);
    else if (type == "char")
        printChar(input);
    else if (type == "double")
        printDouble(input);
    else
        std::cout << "Error: Invalid type" << std::endl;
}
