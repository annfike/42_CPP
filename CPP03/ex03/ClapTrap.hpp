#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    private:
    protected:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;
    public:
        ClapTrap(); //Default constructor
        ClapTrap(std::string name); //Parameterized constructor
        ClapTrap(const ClapTrap &arg); //Copy constructor
        ~ClapTrap(); //Destructor
        ClapTrap &operator=(const ClapTrap &arg); //Assignation operator

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
 };

#endif