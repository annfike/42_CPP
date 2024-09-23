#include "Zombie.hpp"

int	main()
{
    Zombie zombie = Zombie("Zombie_single"); 
	zombie.announce();
    
	Zombie *zombiez = zombieHorde(5, "Zombie_hord"); 
    for (int i = 0; i < 5; i++)
        zombiez[i].announce();

    delete[] zombiez;

    
	return (0);
}
