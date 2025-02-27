#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name), Shield(false)
{
	this->setHealth(100);
	this->setEnergy(50);
	this->setDmg(20);
	this->setMaxHealth(100);
	std::cout << "Scavtrap constructor for " << getName() << " has been called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Original) : ClapTrap(Original)
{
	std::cout << "Scavtrap copy constructor called." << std::endl;
	*this = Original; // Creates a new object that is a copy of the original object.
}

ScavTrap &ScavTrap::operator=(const ScavTrap &Original)
{
	if (this != &Original) // If the current object is not the original (dest instead of src).
	{
		ClapTrap::operator=(Original);
		Shield = Original.Shield;
	}
	std::cout << "Scavtrap copy assignment operator called." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap destructor for " << getName() << " has been called." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "Scavtrap ";
	if (!getHealth())
		std::cout << getName() << " can't activate Gate keeper mode, cause they are dead." << std::endl;
	else if (!Shield)
	{
		std::cout << getName() << " is now in Gate keeper mode." << std::endl;
		Shield = true;
	}
	else if (Shield)
	{
		std::cout << getName() << " is no longer in Gate keeper mode." << std::endl;
		Shield = false;
	}
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "Scavtrap ";
	ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "Scavtrap ";
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "Scavtrap ";
	ClapTrap::beRepaired(amount);
}
