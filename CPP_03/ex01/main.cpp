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
	b.takeDamage(10); // Shield gets automatically deactivated. Scavtrap takes 10 dmg.
	b.beRepaired(2); // Scavtrap repairs itself for 5 dmg.
	b.beRepaired(24122141); // Scavtrap can't deal with this large number.
	b.beRepaired(-1); // Scavtrap doesn't like this negative number.
	b.takeDamage(-1); // Scavtrap appreciates the help, but does not accept negative value.
	b.takeDamage(50); // Scavtrap takes 50 damage.
	b.guardGate(); // Scavtrap activates shield.
	b.takeDamage(100); // Scavtrap takes 100 damage and gets defeated.
	b.guardGate(); // Scavtrap can't activate shield cause they are dead.
	std::cout << b.getName() << " has " << b.getDmg() << " attack damage, " << b.getHealth() << " health and " << b.getEnergy() << " energy left." << std::endl;
	return (0);
}
