#ifndef FIXED_HPP
#define FIXED_HPP
# include <iostream>

class	Fixed
{
	public:
		Fixed(); // Default constructor 1
		Fixed(int NumberValue); // Default constructor 2
		Fixed(const Fixed &Original); // Copy constructor (Makes a new object, as a copy of an existing one)
		Fixed &operator=(const Fixed &Original); // Assignment operator (Assigns the value of one object to another already-existing object.  )
		// The "&operator" is a keyword in C++, used to define or overload operators for user-defined types.
		~Fixed(); // Destructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					NumberValue;
		static const int	FractBits = 8; // Setting value here cause it's const.
};

#endif