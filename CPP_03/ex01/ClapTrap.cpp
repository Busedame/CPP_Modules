#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name) : Name(Name), Health(10), Energy(10), Dmg(0), MaxHealth(10)
{
	std::cout << "Claptrap constructor for " << Name << " has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &Original)
{
	std::cout << "Claptrap copy constructor called." << std::endl;
	*this = Original; // Creates a new object that is a copy of the original object.
}

ClapTrap &ClapTrap::operator=(const ClapTrap &Original)
{
	if (this != &Original) // If the current object is not the original (dest instead of src).
	{
		Name = Original.Name; // Gives dest the values of src.
		Health = Original.Health;
		Energy = Original.Energy;
		Dmg = Original.Dmg;
		MaxHealth = Original.MaxHealth;
	}
	std::cout << "Claptrap copy assignment operator called." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap destructor for " << Name << " has been called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!Health)
		std::cout << Name << " is dead and can't attack." << std::endl;
	else if (!Energy)
		std::cout << Name << " has no energy left, and can't attack." << std::endl;
	else
	{
		std::cout << Name << " attacks " << target << ", causing " << Dmg << " points of damage." << std::endl;
		Energy -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int	Test;

	Test = amount;
	if (Test < 0)
	{
		std::cout << getName() << " says: 'Please attack me with a positive value.'" << std::endl;
		return ;
	}
	if (!Health)
		std::cout << Name << " can't take more damage cause they're already dead. Do you have no empathy?" << std::endl;
	else
	{
		if (amount >= Health)
		{
			std::cout << Name << " takes " << amount << " damage and has been defeated!" << std::endl;
			Health = 0;
		}
		else
		{
			std::cout << Name << " takes " << amount << " damage." << std::endl;
			Health -= amount;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int	Test;

	Test = amount;
	if (Test < 0)
		std::cout << Name << " says: 'Hey, someone sent a negative value! Repair value must be positive." << std::endl;
	else if (!Health)
		std::cout << Name << " can't repair themselves, because they're already dead." << std::endl;
	else if (!Energy)
		std::cout << Name << " can't repair themselves, because they have no energy left." << std::endl;
	else
	{
		if (amount + Health > MaxHealth)
		{
			std::cout << Name << " repairs itself, and restores " << MaxHealth - Health << " health." << std::endl;
			Health = MaxHealth;
		}
		else
		{
			std::cout << Name << " repairs itself, and restores " << amount << " health." << std::endl;
			Health += amount;
		}
		Energy -= 1;
	}
}

std::string ClapTrap::getName(void)
{
	return (Name);
}
unsigned int ClapTrap::getHealth(void)
{
	return (Health);
}

unsigned int ClapTrap::getEnergy(void)
{
	return (Energy);
}

unsigned int ClapTrap::getDmg(void)
{
	return (Dmg);
}

unsigned int ClapTrap::getMaxHealth(void)
{
	return (MaxHealth);
}

void ClapTrap::setHealth(unsigned int newHealth)
{
	Health = newHealth;
}

void ClapTrap::setEnergy(unsigned int newEnergy)
{
	Energy = newEnergy;
}

void ClapTrap::setDmg(unsigned int newDmg)
{
	Dmg = newDmg;
}

void ClapTrap::setMaxHealth(unsigned int newMax)
{
	MaxHealth = newMax;
}
