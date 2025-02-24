#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name, 100, 100, 30), HighFive(false)
{
	std::cout << "Fragtrap constructor has been called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &Original) : ClapTrap(Original)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = Original; // Creates a new object that is a copy of the original object.
}

FragTrap &FragTrap::operator=(const FragTrap &Original)
{
	if (this != &Original) // If the current object is not the original (dest instead of src).
	{
		ClapTrap::operator=(Original);
		HighFive = Original.HighFive;
	}
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor has been called." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "Fragtrap ";
	if (HighFive)
		std::cout << getName() << " can't attack cause their hand is in the air, still waiting for that high five..." << std::endl;
	else if (!getHealth())
		std::cout << getName() << " is dead and can't attack." << std::endl;
	else if (!getEnergy())
		std::cout << getName() << " has no energy left, and can't attack." << std::endl;
	else
	{
		std::cout << getName() << " attacks " << target << ", causing " << getDmg() << " points of damage." << std::endl;
		setEnergy(getEnergy() - 1);
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	int	Test;

	Test = amount;
	std::cout << "Fragtrap ";
	if (Test < 0)
	{
		std::cout << getName() << " says: 'Hey, someone tried to help us by passing a negative value! Please pass a value greater than 0." << std::endl;
		return ;
	}
	if (HighFive)
		std::cout << getName() << " got attacked, but luckily their high five reflected the damage away." << std::endl;
	else if (!getHealth())
		std::cout << getName() << " can't take more damage cause they're already dead. Do you have no empathy?" << std::endl;
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

void FragTrap::beRepaired(unsigned int amount)
{
	int	Test;

	Test = amount;
	std::cout << "Fragtrap ";
	if (Test < 0)
		std::cout << getName() << " says: 'Hey, someone sent a negative value! Repair value can only be between 0 and 10." << std::endl;
	else if (HighFive)
		std::cout << getName() << " can't repair themselves, cause their hand is stuck in a high five position." << std::endl;
	else if (!getHealth())
		std::cout << getName() << " can't repair themselves, because they're already dead." << std::endl;
	else if (!getEnergy())
		std::cout << getName() << " can't repair themselves, because they have no energy left." << std::endl;
	else if (amount > 100)
		std::cerr << getName() << " feels too overwhelmed to repair themselves. It's simply too much. Please pass a repair value between 0 and 100." << std::endl;
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "Fragtrap ";
	if (!HighFive)
	{
		HighFive = true;
		std::cout << getName() << " raises their hand up, hopeful for some of their friends to give them a high five..." << std::endl;
	}
	else
	{
		HighFive = false;
		std::cout << getName() << " remembers that they can't interact with the other characters cause this program is shitty, and slowly puts their hand back down..." << std::endl;
	}
}
