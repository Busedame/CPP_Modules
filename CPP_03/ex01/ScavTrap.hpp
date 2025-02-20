#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

/**
ScavTrap is derived from the class ClapTrap, and inherits the constructors
and destructor from ClapTrap.
This essentially means it has the same methods and variables as ClapTrap, but
with different initialized values, and also a special capacity.
You could see it like this:
In a video game -- ClapTrap is a normal character, ScavTrap is a special character.
They are both characters, but ScavTrap has special attributes that ClapTrap doesn't have.
*/
class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string Name); // Default constructor (Derived from ClapTrap)
		ScavTrap(const ScavTrap &Original); // Copy constructor (Makes a new object, as a copy of an existing one)
		ScavTrap &operator=(const ScavTrap &Original); // Assignment operator (Assigns the values of one object to another already-existing object.)
		// The "&operator" is a keyword in C++, used to define or overload operators for user-defined types.
		~ScavTrap(); // Default destructor (Derived from ClapTrap)
		void	guardGate();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		bool	Shield;
		int		ShieldCount;
};

#endif