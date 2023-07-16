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

int	Fixed::toInt(void) const
{
	return ((int)(value >> fractional_bit));
}

int	Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const 
{
	return((float(value/((double)(1 << fractional_bit)))));
}

//comparison operators

bool	Fixed::operator>(const Fixed& other)const
{
	return (value > other.value);
}

bool	Fixed::operator<(const Fixed& other)const
{
	return (value < other.value);
}

bool	Fixed::operator>=(const Fixed& other)const
{
	return (value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other)const
{
	return (value <= other.value);
}

bool	Fixed::operator==(const Fixed& other)const
{
	return (value == other.value);
}

bool	Fixed::operator!=(const Fixed& other)const
{
	return (value != other.value);
}

//Arithmic operator

Fixed Fixed::operator+(const Fixed& other)const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other)const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& other)const
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& other)const
{
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

//Increament/decreament operators

Fixed& Fixed::operator++()
{
	++value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp(*this);
	++value;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp(*this);
	--value;
	return (temp);
}

//static member funtions

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}
