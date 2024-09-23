#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << "HumanA " << name << " created" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << name << " destroyed" << std::endl;
}

void HumanA::attack()
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;   
}