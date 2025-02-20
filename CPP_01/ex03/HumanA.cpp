#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	if (name.empty())
		this->name = "HumanA";
	else
		this->name = name;
}
HumanA::~HumanA(){}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
