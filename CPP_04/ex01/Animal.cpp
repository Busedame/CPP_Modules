#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string newtype)
{
	type = newtype;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &Original) : type(Original.type)
{
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
	std::cout << "*undefined animal sound*" << std::endl;
}

std::string	Animal::getType (void) const
{
	return (type);
}
