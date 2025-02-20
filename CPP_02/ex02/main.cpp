#include "Fixed.hpp"

// 

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl; // 0, as it was initialized to 0.
	std::cout << ++a << std::endl; // 0.00390625. Pre-incrementing by 1, or actually by 1 / 256. Since we have 8 fractional bits, and radix is now at 2^-8.
	std::cout << a << std::endl; // 0.00390625. Same as previous, as the previous line was PRE-incremented. 
	std::cout << a++ << std::endl; // 0.00390625. Same as previous, because the value hasn't changed yet.
	std::cout << a << std::endl; // 0.0078125. The post-increment in previous line has taken place, and the fixed point value is incremented with an additional 1/256, so 2/256.
	std::cout << b << std::endl; // 10.1016. Was initialized to 5.05(float) * 2(int), which is 10.1016.
	std::cout << Fixed::max( a, b ) << std::endl; // 10.1016. b is greater than a, so 10.1016 is printed.
	return 0;
}
