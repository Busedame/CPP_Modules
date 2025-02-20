#include "Zombie.hpp"

Zombie::Zombie(){} // I have two constructors -> as there can be an indefinite
// amount of constructors, depending on which argument is passed to the constructor.
Zombie::Zombie(std::string name) : name(name){}
Zombie::~Zombie()
{
	std::cout << name << " has been slain!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
