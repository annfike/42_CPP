#include "Zombie.hpp"

Zombie::Zombie(std::string s) 
{
    name = s;
    std::cout << "Zombie " << name << " created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
