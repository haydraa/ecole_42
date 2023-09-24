#include "AMateria.hpp"

AMateria::AMateria( const std::string &type ): _Type(type)
{
	std::cout << "String constructor for AMateria called" << std::endl;
	return;
}

AMateria::~AMateria()
{
	std::cout << "Destructor for AMateria" << std::endl;
}

const std::string	&AMateria::GetType( void ) const
{
	return this->_Type;
}
