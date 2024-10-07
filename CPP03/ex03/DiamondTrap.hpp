#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;

    public:
        DiamondTrap(); //Default constructor
        DiamondTrap(std::string name); //Parameterized constructor
        DiamondTrap(const DiamondTrap &arg); //Copy constructor
        ~DiamondTrap(); //Destructor
        DiamondTrap &operator=(const DiamondTrap &arg); //Assignation operator

        void whoAmI();
        void attack(const std::string& target);
};

#endif

/*
https://stackoverflow.com/questions/69033631/inheritance-from-parents-with-same-members

В C++ виртуальное наследование используется для решения проблемы ромбовидного наследования, 
когда один и тот же базовый класс наследуется несколькими дочерними классами, 
и затем создается еще один класс, который наследуется от этих дочерних. 
Это может привести к неопределенности, так как может существовать несколько копий базового класса.

-Wshadow — это предупреждение компилятора в C++, которое сообщает о возможных конфликтах имён, 
когда локальная переменная или параметр функции имеют такое же имя, как и переменная, 
находящаяся в более широкой области видимости (например, в родительском классе или глобальной области).

*/