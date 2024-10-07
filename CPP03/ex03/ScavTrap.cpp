#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    name = "ScavTrap";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
    std::cout << "ScavTrap name: " << name << " has " << this->hit_points << " hitPoints, " << this->energy_points << " energy points and " << this->attack_damage << " attack damage" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
    std::cout << "ScavTrap name: " << name << " has " << this->hit_points << " hitPoints, " << this->energy_points << " energy points and " << this->attack_damage << " attack damage" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &arg) : ClapTrap(arg)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = arg;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &arg)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    name = arg.name;
    hit_points = arg.hit_points;
    energy_points = arg.energy_points;
    attack_damage = arg.attack_damage;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(hit_points == 0)
    {
        std::cout << "ScavTrap " << name << " is dead and can't attack!" << std::endl;
        return;
    }
    if(energy_points == 0)
    {
        std::cout << "ScavTrap " << name << " has no energy and can't attack!" << std::endl;
        return;
    }
    energy_points --;
    std::cout << "ScavTrap " << name << " attack " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}


int ScavTrap::getHitPoints()
{
    return 50;
}