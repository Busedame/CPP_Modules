#include "Fixed.hpp"

int main( void )
{
	Fixed a; // FPValue is 0.
	Fixed const b( 10 ); // FPValue converted from int is 2560 since: IntValue << FractBits == 10 << 8 == 10 * 256.
	Fixed const c( 42.42f ); // FPValue converted from float is 10859 since: roundf(Floatvalue * (1 << FractBits)) == roundf(42.42 * 256). 
	Fixed const d( b ); //FPValue is the same as for b, so 2560.

	a = Fixed( 1234.4321f ); // FPValue is roundf(1234.4321 * 256) = 316215.

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
