#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name), HighFive(false)
{
	this->setHealth(100);
	this->setEnergy(100);
	this->setDmg(30);
	this->setMaxHealth(100);
	std::cout << "Fragtrap constructor for " << getName() << " has been called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &Original) : ClapTrap(Original)
{
	std::cout << "Fragtrap copy constructor called." << std::endl;
	*this = Original; // Creates a new object that is a copy of the original object.
}

FragTrap &FragTrap::operator=(const FragTrap &Original)
{
	if (this != &Original) // If the current object is not the original (dest instead of src).
	{
		ClapTrap::operator=(Original);
		HighFive = Original.HighFive;
	}
	std::cout << "Fragtrap copy assignment operator called." << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Fragtrap destructor for " << getName() << " has been called." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "Fragtrap ";
	ClapTrap::attack(target);
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "Fragtrap ";
	ClapTrap::takeDamage(amount);
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "Fragtrap ";
	ClapTrap::beRepaired(amount);
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
