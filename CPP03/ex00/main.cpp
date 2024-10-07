#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap claptrap1("A");
    ClapTrap claptrap2("B");

    claptrap1.attack("target");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(1);

    claptrap2.attack("target");
    claptrap2.takeDamage(8);
    claptrap2.beRepaired(3);

    claptrap1.attack("target");
    claptrap1.takeDamage(9);
    claptrap1.beRepaired(3);

    claptrap1.attack("target");
    claptrap1.takeDamage(7);
    claptrap1.beRepaired(3);
    return 0;
}
