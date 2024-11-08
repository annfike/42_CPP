#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange const &src);

        void convert(std::string const &line);
        
        /*void printData() const
        {
            for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); it++)
                std::cout << it->first << ": " << it->second << std::endl;
        }*/
    private:
        std::map<std::string, double> _data;
};

#endif