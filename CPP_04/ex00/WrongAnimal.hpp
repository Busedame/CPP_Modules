#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal 
{
	public:
		WrongAnimal();
		WrongAnimal(std::string newtype);
		WrongAnimal(const WrongAnimal &Original);
		WrongAnimal &operator=(const WrongAnimal &Original);
		virtual ~WrongAnimal();
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
	protected:
		std::string type;
};

#endif