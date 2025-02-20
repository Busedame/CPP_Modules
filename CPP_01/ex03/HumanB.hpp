#ifndef HUMANB_HPP
#define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name); // The constructor only needs one argument.
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &new_weapon); // Sets a weapon.
	private:
		std::string	name; // The name of the human.
		Weapon		*weapon; // Declared as a pointer, as a reference won't be able to get initialized.
		bool		HasWeapon; // Sets to true once it has a weapon, to protect attack()-function in the case of no weapon.
};

#endif