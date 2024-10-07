#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap 
{
    private:

    public:
        FragTrap(); //Default constructor
        FragTrap(std::string name); //Parameterized constructor
        FragTrap(const FragTrap &arg); //Copy constructor
        ~FragTrap(); //Destructor
        FragTrap &operator=(const FragTrap &arg); //Assignation operator

        void highFivesGuys(void);
 };

#endif