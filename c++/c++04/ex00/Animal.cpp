#include "Animal.hpp"

Animal::Animal(void):type("")
{
	std::cout << "Default constructor for animal called" << std::endl;

}

Animal::Animal(Animal const &init)
{
	std::cout << "copy constructor for animal called" << std::endl;
	*this = init;
}

Animal::~Animal(void)
{
	std::cout << "Destrctor for animal is called" << std::endl;
}

Animal &Animal::operator=(Animal const &init2)
{
	std::cout << "Assignement operator dor animal called" << std::endl;
	this->type = init2.getType();
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "i dont have a type yet to make a sound" << std::endl;
}

const std::string	&Animal::getType(void)const
{
	return (this->type);
}
