#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string newtype);
		Animal(const Animal &Original);
		Animal &operator=(const Animal &Original);
		virtual ~Animal();
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
	protected:
		std::string type;
};

#endif