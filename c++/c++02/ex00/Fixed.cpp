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

Fixed& Fixed::operator=(const Fixed& init2)
{
	std::cout << "Assignation operateur called" << std::endl;
	if (this != &init2)
		value = init2.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fuction called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}


