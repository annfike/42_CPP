#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    //std::cout << "BitcoinExchange constructor" << std::endl;
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos) //Если pos равно npos, это означает, что операция поиска не удалась.
        {
            std::cerr << "Error: invalid file" << std::endl;
            return;
        }
        std::string key = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);
        double value = std::atof(valueStr.c_str());
        _data[key] = value;
    }
    file.close();

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    //std::cout << "BitcoinExchange copy constructor" << std::endl;
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
    //std::cout << "BitcoinExchange destructor" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    //std::cout << "BitcoinExchange assignation operator" << std::endl;
    (void)src;
    return *this;
}

static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(const std::string& date) {
    int year, month, day;
    char dash1, dash2;

    std::istringstream dateStream(date);
    dateStream >> year >> dash1 >> month >> dash2 >> day;
    // Проверка формата
    if (date.size() != 10 || dash1 != '-' || dash2 != '-' || dateStream.fail())
        return false;
    // Проверка диапазонов
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    // Проверка количества дней в месяце
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2) {
        if (isLeapYear(year)) {
            if (day > 29) return false;
        } else {
            if (day > 28) return false;
        }
    }
    return true;
}

static void removeSpaces(std::string& str) {

    for (std::string::iterator it = str.begin(); it != str.end();) {
        if (*it == ' ') {
            it = str.erase(it);
        } else {
            ++it;
        }
    }
}

void BitcoinExchange::convert(std::string const &line)
{
    size_t pos = line.find('|');
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input =>" << line << std::endl;
        return;
    }
    std::string key = line.substr(0, pos);
    removeSpaces(key);
    if (key == "date")
        return;
    std::string valueStr = line.substr(pos + 1);
    double value = std::atof(valueStr.c_str());
    if (!isValidDate(key)) {
        std::cerr << "Error: invalid date =>" << key << std::endl;
        return;
    }
    if (value <= 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (value >= 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    //std::cout << "Converting " << value << " " << key << " to BTC:" ;
    std::map<std::string, double>::iterator it = _data.upper_bound(key); // ищет первый элемент, который больше key
    if (it != _data.begin()) {    
        --it;  // Отступаем на один элемент назад, чтобы получить элемент, который не больше найденного
        //std::cout << "ближайшая предыдущая дата: " << it->first << " => " << it->second << std::endl;
        double result = value * it->second;
        std::cout << key << " => " << value << " = " << result <<  std::endl;
    } else {
        std::cout << "Нет данных за эту дату: " << key << "\n";
    }
    
}
