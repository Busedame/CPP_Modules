#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &Original);
		Dog &operator=(const Dog &Original);
		~Dog();
	private:
		std::string type;
};

#endif