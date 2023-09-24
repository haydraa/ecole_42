#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Default constructor for Ice called" << std::endl;
	return;
}

Ice::Ice(Ice const & src): AMateria("ice")
{
	std::cout << "Copy constructor for Ice called" << std::endl;
	*this = src;
	return;
}

Ice::~Ice(void)
{
	std::cout << "Destructor for Ice called" << std::endl;
	return;
}

Ice	&Ice::operator=(const Ice &other)
{
	this->_Type = other._Type;
	std::cout << "Assignation operator for Ice called" << std::endl;
	return *this;
}

AMateria	*Ice::Clone(void) const
{
	return (new Ice(*this));
}

void		Ice::Use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.GetName() << " *"
		<< std::endl;
}
