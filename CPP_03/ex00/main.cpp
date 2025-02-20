#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap a("Bob");

	a.attack("Solfrid");
	a.takeDamage(5);
	a.takeDamage(1);
	a.takeDamage(3);
	a.attack("Solfrid");
	a.beRepaired(10);
	a.beRepaired(10);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(10);
	a.attack("Solfrid");
	return 0;
}
