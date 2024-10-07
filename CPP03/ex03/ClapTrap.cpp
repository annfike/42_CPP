#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
    std::cout << "ClapTrap name: " << name << " has " << this->hit_points << " hitPoints, " << this->energy_points << " energy points and " << this->attack_damage << " attack damage" << std::endl;

}

ClapTrap::ClapTrap(const std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Parameterized constructor called" << std::endl;
    std::cout << "ClapTrap name: " << name << " has " << this->hit_points << " hitPoints, " << this->energy_points << " energy points and " << this->attack_damage << " attack damage" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &arg)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = arg;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &arg)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    name = arg.name;
    hit_points = arg.hit_points;
    energy_points = arg.energy_points;
    attack_damage = arg.attack_damage;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if(hit_points == 0)
    {
        std::cout << "ClapTrap " << name << " is dead and can't attack!" << std::endl;
        return;
    }
    if(energy_points == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy and can't attack!" << std::endl;
        return;
    }
    energy_points --;
    std::cout << "ClapTrap " << name << " attack " << target << ", causing " << attack_damage << " points of damage!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    hit_points -= amount;
    std::cout << "ClapTrap " << name << " take " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(energy_points == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy and can't be repaired!" << std::endl;
        return;
    }
    else
    {
        hit_points += amount;
        energy_points --;
        std::cout << "ClapTrap " << name << " be repaired by " << amount << " points!" << std::endl;
    }
}


