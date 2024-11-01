#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return 1;
    }
    std::string arg = av[1];
    ScalarConverter::convert(arg);
    return 0;
}