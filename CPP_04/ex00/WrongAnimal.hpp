#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &Original);
		WrongAnimal &operator=(const WrongAnimal &Original);
		~WrongAnimal();
		void	makeSound(void) const;
		std::string	getType(void) const;
		void	setType(std::string newtype);
	protected:
		std::string type;
};

#endif