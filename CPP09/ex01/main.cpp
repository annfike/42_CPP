#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "usage: ./RPN \"3 4 5 * +\"" << std::endl;
        return 1;
    }
    else
    {
        RPN rpn;
        rpn.calculate(argv[1]);
    }

    return 0;
}