#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    ClapTrap claptrap1("A");
    ScavTrap scavtrap("B");
    FragTrap fragtrap("F");

    claptrap1.attack("target");
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(1);

    scavtrap.attack("target");
    scavtrap.takeDamage(8);
    scavtrap.beRepaired(3);
    scavtrap.guardGate();
    
    fragtrap.attack("target");
    fragtrap.takeDamage(9);
    fragtrap.beRepaired(4);
    fragtrap.highFivesGuys();


    return 0;
}
