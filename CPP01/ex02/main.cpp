#include <iostream>

int	main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    std::string str1 = "HI THIS IS NOT BRAIN";
    stringPTR = &str1;
    // forbidden &stringREF = str1;
    std::cout << "Memory address of the string variable: " << &str1 << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << "Value of the string variable: " << str1 << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl; 
    
	return (0);
}

/*
ссылки и указатели
Принципиальных отличий два:

ссылка, в отличии от указателя, не может быть неинициализированной;
ссылка не может быть изменена после инициализации.
Отсюда и получаем плюсы и минусы использования того и другого:

ссылки лучше использовать когда нежелательно или не планируется изменение связи ссылка → объект;
указатель лучше использовать, когда возможны следующие моменты в течении жизни ссылки:
ссылка не указывает ни на какой объект;
ссылка указаывает на разные объекты в течении своего времени жизни.
*/