#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->name = "Default";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::getHitPoints();
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap name: " << name << " has " << this->hit_points << " hitPoints, " << this->energy_points << " energy points and " << this->attack_damage << " attack damage" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
    this->name = name;
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::getHitPoints();
    this->attack_damage = FragTrap::attack_damage;
    std::cout << "DiamondTrap name: " << name << " has " << this->hit_points << " hitPoints, " << this->energy_points << " energy points and " << this->attack_damage << " attack damage" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &arg) : ClapTrap(arg), ScavTrap(arg), FragTrap(arg)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = arg;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &arg)
{
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    this->name = arg.name;
    this->hit_points = arg.hit_points;
    this->energy_points = arg.energy_points;
    this->attack_damage = arg.attack_damage;
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

