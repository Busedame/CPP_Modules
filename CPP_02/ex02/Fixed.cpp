#include "Fixed.hpp"

// CONSTRUCTORS

Fixed::Fixed() : FPValue(0), IntValue(0), FloatValue(0)
{
	// This constructor is getting called if an object is getting declared without
	// arguments.
}

Fixed::Fixed(const int IntValue) : FPValue(0), IntValue(IntValue), FloatValue(0)
{
	// This constructor is getting called if an object is getting declared
	// with an int argument. It also stores the int in a fixed point value-variable.
	FPValue = IntValue << FractBits; // IntValue << 8 == IntValue * 256.
}

Fixed::Fixed(const float FloatValue) : FPValue(0), IntValue(0), FloatValue(FloatValue)
{
	// This constructor is getting called if an object is getting declared
	// with a float argument. It also stores the float in a fixed point value-variable.
	FPValue = roundf(FloatValue *(1 << FractBits)); // Roundf is getting used to round to the nearest integer.
	// This is basically equivalent to doing FloatValue * 256, or shifting bits 8 spots to the left (but multiplication 
	// is used to ensure proper caluclation with roundf).
}

Fixed::Fixed(const Fixed &Original) : FPValue(Original.FPValue){}

// DESTRUCTOR
Fixed::~Fixed(){}

// ASSIGNMENT OPERATOR
Fixed &Fixed::operator=(const Fixed &Original)
{
	if (this != &Original) // If the current object is not the original (dest instead of src).
	{
		FPValue = Original.getRawBits(); // Setting the FPValue of the current value to the same as original.
		FloatValue = Original.toFloat(); // And the same with FloatValue.
		IntValue = Original.toInt(); // And IntValue.
	}
	return (*this); // Returns a reference to the current object.
}

// COMPARISON OPERATORS

bool Fixed::operator==(const Fixed &other) const
{
	return this->FPValue == other.FPValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->FPValue != other.FPValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->FPValue >= other.FPValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->FPValue <= other.FPValue;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->FPValue > other.FPValue;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->FPValue < other.FPValue;
}

// ARITMETHIC OPERATORS

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}	

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// PRE-INCREMENT AND PRE-DECREMENT

Fixed& Fixed::operator++()
{
	FPValue += 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	FPValue -= 1;
	return (*this);
}

// POST-INCREMENT AND POST-DECREMENT

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	FPValue += 1;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	FPValue -= 1;
	return (temp);
}

// MIN AND MAX

Fixed& Fixed::min(Fixed& FP1, Fixed& FP2)
{
	if (FP1 > FP2)
		return (FP2);
	else
		return (FP1);
}
const Fixed& Fixed::min(const Fixed& FP1, const Fixed& FP2)
{
	if (FP1 > FP2)
		return (FP2);
	else
		return (FP1);
}

Fixed& Fixed::max(Fixed& FP1, Fixed& FP2)
{
	if (FP1 < FP2)
		return (FP2);
	else
		return (FP1);
}

const Fixed& Fixed::max(const Fixed& FP1, const Fixed& FP2)
{
	if (FP1 < FP2)
		return (FP2);
	else
		return (FP1);
}

// GETTER AND SETTER

int	Fixed::getRawBits(void) const
{
	return (FPValue);
}

void	Fixed::setRawBits(int const raw)
{
	FPValue = raw;
}

// CONVERSION FROM FIXED POINT VALUE TO FLOAT OR INT

float	Fixed::toFloat(void) const
{
	return static_cast<float>(FPValue) / (1 << FractBits);
	// Static_cast<float> typecasts to float. It is important that FPValue
	// is int brackets BEFORE the '/'-sign, in that way it is getting
	// typecasted BEFORE the rest of the conversion.
	// FPValue / (1 << FractBits) == FPValue / 256.
}

int		Fixed::toInt(void) const
{
	return (getRawBits() >> FractBits); // FPValue >> 8 == FPValue / 256.
}

// OUTSIDE OF CLASS, OVERLOAD FOR THE INSERTION "<<"-OPERATOR
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	// When the whole object 'Fixed' is passed to the outstream (STDOUT), 
	// it converts the Fixed Point Value to a float, and targets the float 
	// to be printed. This makes it possible to "print" a whole class instance,
	// which would normally not be possible. It is targeting the float number,
	// instead of the whole class -> basically saying "if you want to print an
	// object, print the float value of fixed point value is what will be printed".
	out << fixed.toFloat();
	return out;
}
