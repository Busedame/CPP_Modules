#ifndef HUMANA_HPP
#define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon); // Storing a reference to the Weapon object ensures that HumanA uses the same Weapon instance that's modified later.
		~HumanA();
		void	attack(void);
	private:
		std::string	name;
		Weapon 		&weapon; // Without a reference, HumanA would have its own copy of the Weapon, and changes to the original Weapon wouldn't affect HumanA's copy.
};

#endif