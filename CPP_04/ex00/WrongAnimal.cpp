#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &Original)
{
	*this = Original;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &Original)
{
	if (this != &Original)
		type = Original.type;
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	if (type == "WrongCat")
		std::cout << "The " << type << " says 'bark'." << std::endl;
	else if (type == "WrongDog")
		std::cout << "The " << type << " says 'meow'." << std::endl;
	else
		std::cout << "The Animal says 'wikiwako'." << std::endl;
}

void	WrongAnimal::setType(std::string newtype)
{
	type = newtype;
}

std::string	WrongAnimal::getType (void) const
{
	return (type);
}
