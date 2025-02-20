#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), HasWeapon(false) // The constructor only needs one argument (name), but
// will also initialize weapon and HasWeapon as this is necessary. Like in a struct, every attribute must be initialized.
{
	if (name.empty())
		this->name = "HumanB";
	else
		this->name = name;
}

HumanB::~HumanB(){}

void	HumanB::attack(void)
{
	if (HasWeapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " died cause he had no weapon to defend himself..." << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon) // Passes a reference to new_weapon. Essentially creating an alias for the new_weapon from a different scope.
{
	weapon = &new_weapon; // This makes weapon point to new_weapon.
	HasWeapon = true; // HasWeapon gets set to true.
}