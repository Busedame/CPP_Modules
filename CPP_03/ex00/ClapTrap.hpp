#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
# include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(std::string Name); // Default constructor
		ClapTrap(const ClapTrap &Original); // Copy constructor (Makes a new object, as a copy of an existing one)
		ClapTrap &operator=(const ClapTrap &Original); // Assignment operator (Assigns the values of one object to another already-existing object.)
		// The "&operator" is a keyword in C++, used to define or overload operators for user-defined types.
		~ClapTrap(); // Default constructor
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName();
		unsigned int getHealth();
		unsigned int getEnergy();
		unsigned int getDmg();
		unsigned int getMaxHealth();
		void setHealth(unsigned int newHealth);
		void setEnergy(unsigned int newEnergy);
		void setDmg(unsigned int newDmg);
		void setMaxHealth(unsigned int newMax);
	private:
		std::string	Name;
		unsigned int	Health;
		unsigned int	Energy;
		unsigned int	Dmg;
		unsigned int	MaxHealth;
};

#endif