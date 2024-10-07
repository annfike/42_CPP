#include "ScavTrap.hpp"

int main( void ) {
    ClapTrap claptrap1("A");
    ScavTrap scavtrap("B");

    claptrap1.attack("target");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(1);

    scavtrap.attack("target");
    scavtrap.takeDamage(8);
    scavtrap.beRepaired(3);


    return 0;
}
