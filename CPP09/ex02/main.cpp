#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "usage: ./PmergeMe 3 4 5 1 "<< std::endl;
        return 1;
    }
    else
    {
        PmergeMe pmergeme;
        pmergeme.mergeMe(argc, argv);
    }

    return 0;
}