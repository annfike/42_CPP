#include "BitcoinExchange.hpp"



int main(int argc, char **argv)
{
    if (argc != 2)
        {
            std::cerr << "usage: ./btc input.txt" << std::endl;
            return 1;
        }
    else
    {
        std::ifstream file(argv[1]);
        if (!file.is_open())
        {
            std::cerr << "Error: could not open file" << std::endl;
            return 1;
        }
        BitcoinExchange exchange;
        //exchange.printData();
        std::string line;
        while (std::getline(file, line))
            exchange.convert(line);
    }   
    return 0;
}