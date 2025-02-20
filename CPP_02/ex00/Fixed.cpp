#include "Fixed.hpp"

Fixed::Fixed() : NumberValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int NumberValue) : NumberValue(NumberValue)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Original) : NumberValue(Original.NumberValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &Original)
{
	if (this != &Original) // If the current object is not the original (dest instead of src).
		NumberValue = Original.getRawBits(); // Setting the NumberValue of the current value to the same as original.
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (NumberValue);
}

void	Fixed::setRawBits(int const raw)
{
	NumberValue = raw;
}
