// наследование https://metanit.com/cpp/tutorial/5.10.php

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    private:

    public:
        ScavTrap(); //Default constructor
        ScavTrap(std::string name); //Parameterized constructor
        ScavTrap(const ScavTrap &arg); //Copy constructor
        ~ScavTrap(); //Destructor
        ScavTrap &operator=(const ScavTrap &arg); //Assignation operator

        void guardGate();
        void attack(const std::string& target);
 };

#endif