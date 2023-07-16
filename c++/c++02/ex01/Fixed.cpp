#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& init)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = init;
}

Fixed::Fixed(const int intger):value(intger<<fractional_bit)
{
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float Float):value((int)roundf(Float * (1 << fractional_bit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& init2)
{
	std::cout << "Assignation operateur called" << std::endl;
	if (this != &init2)
		value = init2.value;
	return (*this);
}

std::ostream& operator<<(std::ostream& out ,const Fixed& in)
{
	if (in.getRawBits() & (0b11111111))
		out << in.toFloat();
	else
		out << in.toInt();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const 
{
	return((float(value/((double)(1 << fractional_bit)))));
}

int	Fixed::toInt(void) const
{
	return ((int)(value >> fractional_bit));
}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}


