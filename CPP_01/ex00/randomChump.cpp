#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie zombie(name); // Allocating on the stack.
	zombie.announce();
}