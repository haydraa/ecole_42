#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):type("")
{
	std::cout << "default constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &init)
{
	std::cout << "copy constructor for WrongAnimal Called" << std::endl;
	*this = init;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &init2)
{
		std::cout << "Assignement operator for WrongAnimal Called" << std::endl;
		this->type = init2.getType();
		return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor for WrongAnimal Called" << std::endl;
}

const std::string	&WrongAnimal::getType(void)const
{
	return (this->type);
}

void WrongAnimal::makeSound(void)const
{
	std::cout << "i have no type ! u will see no sound !" << std::endl;
}

