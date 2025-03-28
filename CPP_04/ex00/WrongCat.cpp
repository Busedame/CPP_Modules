#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	setType("WrongCat");
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &Original)
{
	*this = Original;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &Original)
{
	if (this != &Original)
		type = Original.type;
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
