#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    name = "FragTrap";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &arg) : ClapTrap(arg)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = arg;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &arg)
{
    std::cout << "FragTrap Assignation operator called" << std::endl;
    name = arg.name;
    hit_points = arg.hit_points;
    energy_points = arg.energy_points;
    attack_damage = arg.attack_damage;
    return *this;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " is requesting a high five" << std::endl;
}