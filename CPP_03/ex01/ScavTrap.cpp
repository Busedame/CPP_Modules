#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name, 100, 50, 20), Shield(false), ShieldCount(0)
{
	std::cout << "Scavtrap constructor has been called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &Original) : ClapTrap(Original)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = Original; // Creates a new object that is a copy of the original object.
}

ScavTrap &ScavTrap::operator=(const ScavTrap &Original)
{
	if (this != &Original) // If the current object is not the original (dest instead of src).
	{
		ClapTrap::operator=(Original);
		Shield = Original.Shield;
		ShieldCount = Original.ShieldCount;
	}
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap destructor has been called." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (!Shield)
	{
		std::cout << getName() << "'s shield has been activated. It lasts for 3 rounds." << std::endl;
		Shield = true;
	}
	else if (Shield)
	{
		std::cout << getName() << "'s shield has been deactivated." << std::endl;
		Shield = false;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (Shield && ShieldCount > 2)
	{
		Shield = false;
		ShieldCount = 0;
		std::cout << getName() << "'s shield has been deactivated." << std::endl;
	}
	if (!getHealth())
		std::cout << getName() << " is dead and can't attack." << std::endl;
	else if (Shield)
	{
		ShieldCount++;
		std::cout << getName() << " can't attack cause they are in shield mode." << std::endl;
	}
	else if (!getEnergy())
		std::cout << getName() << " has no energy left, and can't attack." << std::endl;
	else
	{
		std::cout << getName() << " attacks " << target << ", causing " << getDmg() << " points of damage." << std::endl;
		setEnergy(getEnergy() - 1);
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (Shield && ShieldCount > 2)
	{
		Shield = false;
		ShieldCount = 0;
		std::cout << getName() << "'s shield has been deactivated." << std::endl;
	}
	if (!getHealth())
		std::cout << getName() << " can't take more damage cause they're already dead. Do you have no empathy?" << std::endl;
	else if (Shield)
	{
		std::cout << getName() << " blocked " << amount << " damage with their shield." << std::endl;
		ShieldCount++;
	}
	else
	{
		if (amount >= getHealth())
		{
			std::cout << getName() << " takes " << amount << " damage and has been defeated!" << std::endl;
			setHealth(0);
		}
		else
		{
			std::cout << getName() << " takes " << amount << " damage." << std::endl;
			setHealth(getHealth() - amount);
		}
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (Shield && ShieldCount > 2)
	{
		Shield = false;
		ShieldCount = 0;
		std::cout << getName() << "'s shield has been deactivated." << std::endl;
	}
	if (!getHealth())
		std::cout << getName() << " can't repair themselves, because they're already dead." << std::endl;
	else if (Shield)
	{
		std::cout << getName() << " can't repair themselves, because they are in shield mode." << std::endl;
		ShieldCount++;
	}
	else if (!getEnergy())
		std::cout << getName() << " can't repair themselves, because they have no energy left." << std::endl;
	else
	{
		if (getHealth() + amount > 100)
		{
			std::cout << getName() << " repairs themself, and restores " << 100 - getHealth() << " health." << std::endl;
			setHealth(100);
		}
		else
		{
			std::cout << getName() << " repairs themself, and restores " << amount << " health." << std::endl;
			setHealth(getHealth() + amount);
		}
		setEnergy(getEnergy() - 1);
	}
}
