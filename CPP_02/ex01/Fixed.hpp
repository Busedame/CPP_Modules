#ifndef FIXED_HPP
#define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(); // Default constructor
		Fixed(const int IntValue); // Const int constructor
		Fixed(const float FloatValue); // Const float constructor
		Fixed(const Fixed &Original); // Copy constructor (Makes a new object, as a copy of an existing one)
		Fixed &operator=(const Fixed &Original); // Assignment operator (Assigns the value of one object to another already-existing object.  )
		// The "&operator" is a keyword in C++, used to define or overload operators for user-defined types.
		~Fixed(); // Destructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					FPValue;
		int					IntValue;
		float				FloatValue;
		static const int	FractBits = 8; // Setting value here cause it's const.
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // Overload of the insertion ('<<')-operator.


#endif