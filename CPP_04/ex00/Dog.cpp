#include "Dog.hpp"

Dog::Dog() : Animal()
{
	setType("Dog");
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &Original)
{
	*this = Original;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &Original)
{
	if (this != &Original)
		type = Original.type;
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
