#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	// Fixed a(1);
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	// std::cout << ((a.getRawBits() * 256) / 256) << std::endl;
	std::cout << b.getRawBits() << std::endl;
	// std::cout << (b.getRawBits() / 256) << std::endl;
	std::cout << c.getRawBits() << std::endl;
	// std::cout << (c.getRawBits() / 256) << std::endl;
	return 0;
}
