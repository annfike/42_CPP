#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB " << name << " destroyed" << std::endl;
}

void HumanB::attack()
{
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
    /*
    или:
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    Ключевое слово this представляет указатель на текущий объект данного класса. 
    Соответственно через this мы можем обращаться внутри класса к любым его членам.
    Другое практическое применение this - с его помощью можно возвращать текущий объект класса

    to check if weapon is NULL:
    if (weapon == NULL)
        std::cout << name << " attacks with hands "<< std::endl;
    else
        std::cout << name << " attacks with his " << weapon->getType() << std::endl;
    */
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}