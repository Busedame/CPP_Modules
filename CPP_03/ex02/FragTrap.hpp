#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string Name); // Default constructor (Derived from ClapTrap)
		FragTrap(const FragTrap &Original); // Copy constructor (Makes a new object, as a copy of an existing one)
		FragTrap &operator=(const FragTrap &Original); // Assignment operator (Assigns the values of one object to another already-existing object.)
		// The "&operator" is a keyword in C++, used to define or overload operators for user-defined types.
		~FragTrap(); // Default destructor (Derived from ClapTrap)
		void	highFivesGuys(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private:
		bool	HighFive;
};

#endif