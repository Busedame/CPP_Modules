#include "Zombie.hpp"

int	main()
{
	Zombie *zombie = newZombie("Roy");
	zombie->announce();
	delete zombie;
	randomChump("Olga");
}