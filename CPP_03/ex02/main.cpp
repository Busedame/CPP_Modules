#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap a("Bob"); // Claptrap initialized.
	ScavTrap b("Tim"); // Scavtrap initialized.
	FragTrap c("Odd");
	std::cout << a.getName() << " has " << a.getDmg() << " attack damage, " << a.getHealth() << " health and " << a.getEnergy() << " energy left." << std::endl;
	std::cout << b.getName() << " has " << b.getDmg() << " attack damage, " << b.getHealth() << " health and " << b.getEnergy() << " energy left." << std::endl;
	std::cout << c.getName() << " has " << c.getDmg() << " attack damage, " << c.getHealth() << " health and " << c.getEnergy() << " energy left." << std::endl;
	c.highFivesGuys();
	c.attack("Berit");
	c.beRepaired(10);
	c.takeDamage(10);
	c.highFivesGuys();
	c.attack("Berit");
	c.beRepaired(-1);
	c.beRepaired(1000000000);
	c.takeDamage(1000000);
	return (0);
}
