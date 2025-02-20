#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType(void);
		void				setType(std::string new_type);
	private:
		std::string type; // The type of the weapon.
};

#endif