#include "iter.hpp"

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    iter(tab, 5, print);

    std::string tab2[] = {"Hello", "World", "!"};
    iter(tab2, 3, print);

    
    return 0;
}