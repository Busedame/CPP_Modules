#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &Original);
		Animal &operator=(const Animal &Original);
		~Animal();
		void	makeSound(void) const;
		std::string	getType(void) const;
		void	setType(std::string newtype);
	private:
		std::string type;
};

#endif