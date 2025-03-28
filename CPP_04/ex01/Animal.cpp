#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &Original)
{
	*this = Original;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &Original)
{
	if (this != &Original)
		type = Original.type;
	std::cout << "Animal copy assignment operator called." << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	if (type == "Cat")
		std::cout << "The " << type << " says 'meow'." << std::endl;
	else if (type == "Dog")
		std::cout << "The " << type << " says 'bark'." << std::endl;
	else
		std::cout << "The Animal says 'wikiwako'." << std::endl;
}

void	Animal::setType(std::string newtype)
{
	type = newtype;
}

std::string	Animal::getType (void) const
{
	return (type);
}
