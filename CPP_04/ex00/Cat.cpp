#include "Cat.hpp"

Cat::Cat() : Animal()
{
	setType("Cat");
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &Original)
{
	*this = Original;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &Original)
{
	if (this != &Original)
		type = Original.type;
	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
