#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap a("Bob"); // Claptrap initialized.
	ScavTrap b("Tim"); // Scavtrap initialized.
	// ScavTrap c(b);
	// ScavTrap d("Jon");
	// ScavTrap e = d;
	// e.attack("Berit");
	a.attack("Berit"); // Claptrap attacks with 0 dmg.
	b.attack("Berit"); // Scavtrap attacks with 20 dmg.
	b.guardGate(); // Scavtrap activates shield.
	b.attack("Berit"); // Scavtrap can't attack with shield.
	b.takeDamage(10); // Scavtrap ignores damage with shield active.
	b.takeDamage(10); // Scavtrap ignores damage with shield active.
	b.takeDamage(10); // Shield gets automatically deactivated. Scavtrap takes 10 dmg.
	b.beRepaired(5); // Scavtrap repairs itself for 5 dmg.
	b.takeDamage(50);
	b.takeDamage(100); // Scavtrap takes 100 damage and gets defeated.
	std::cout << b.getName() << " has " << b.getDmg() << " attack damage, " << b.getHealth() << " health and " << b.getEnergy() << " energy left." << std::endl;
	return (0);
}
