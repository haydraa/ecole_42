#include "AMateria.hpp"

AMateria::AMateria( const std::string &type ): _Type(type)
{
	std::cout << "String constructor for AMateria called" << std::endl;
	return;
}

const std::string	&AMateria::GetType( void ) const
{
	return this->_Type;
}
