#ifndef FIXED_HPP
#define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed
{
	public:
	// Constructors
		Fixed(); // Default constructor
		Fixed(const int IntValue); // Const int constructor
		Fixed(const float FloatValue); // Const float constructor
		Fixed(const Fixed &Original); // Copy constructor (Makes a new object, as a copy of an existing one)
	
	// Assignment operator
		Fixed &operator=(const Fixed &Original); // Assignment operator (Assigns the value of one object to another already-existing object.  )
		// The "&operator" is a keyword in C++, used to define or overload operators for user-defined types.

	// Destructor
		~Fixed();

	// Comparison operators
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;

	// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
	
	// Pre-increment and pre-decrement
		Fixed& operator++();
		Fixed& operator--();
	// Post-increment and post-decrement
		Fixed operator++(int);
		Fixed operator--(int);
	
	// Getter and setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	// Conversion from fixed point value to float or int
		float	toFloat(void) const;
		int		toInt(void) const;

	// Min and max
		static Fixed& min(Fixed& FP1, Fixed& FP2);
		static const Fixed& min(const Fixed& FP1, const Fixed& FP2);
		static Fixed& max(Fixed& FP1, Fixed& FP2);
		static const Fixed& max(const Fixed& FP1, const Fixed& FP2);

	private:
		int					FPValue; // Fixed point value
		int					IntValue; // Integer value
		float				FloatValue; // Float value
		static const int	FractBits = 8; // Setting value here cause it's const.
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // Overload of the insertion ('<<')-operator.

#endif