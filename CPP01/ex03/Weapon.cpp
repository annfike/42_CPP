#include "Weapon.hpp"

Weapon::Weapon(std::string s) 
{
    type = s;
    std::cout << "Weapon " << type << " created" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon " << type << " destroyed" << std::endl;
}

const std::string Weapon::getType() const
{
    return (type);
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}

