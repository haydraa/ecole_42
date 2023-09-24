#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	/* this->type = "cure"; */
	std::cout << "Default constructor for Cure called" << std::endl;
	return;
}

Cure::Cure(Cure const & src) : AMateria("cure")
{
	std::cout << "Copy constructor for Cure called" << std::endl;
	*this = src;
	return;
}

Cure::~Cure(void)
{
	std::cout << "Destructor for Cure called" << std::endl;
	return;
}

Cure	&Cure::operator=( const Cure &other )
{
	this->_Type = other._Type;
	std::cout << "Assignation operator for Cure called" << std::endl;
	return *this;
}

AMateria	*Cure::Clone(void) const
{
	return (new Cure(*this));
}

void		Cure::Use(ICharacter& target)
{
	std::cout << "* heals " << target.GetName() << " wounds *" << std::endl;
}
