#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	if (type.empty())
		this->type = "dirty, old sock";
	else
		this->type = type;
}
Weapon::~Weapon(){}

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string new_type)
{
	if (new_type.empty())
	{
		std::cerr << "Error: Tried to remove weapon. Previous weapon remains." << std::endl;
		return ; 
	}
	type = new_type;
}
