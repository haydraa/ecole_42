#include "Animal.hpp"

AAnimal::~AAnimal(void)
{
	std::cout << "Destrctor for animal is called" << std::endl;
}

const std::string	&AAnimal::getType(void)const
{
	return (this->type);
}
