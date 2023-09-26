#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
		std::cout << "Constructor of Dog class called" << std::endl;
}

Dog::Dog(const Dog &init) : Animal(init)
{
	std::cout << "copy constructor of Dog calss called" << std::endl;
	*this = init;
}

Dog::~Dog(void)
{
	std::cout << "Destructor of Dog class called" << std::endl;
}

void	Dog::makeSound(void) const
{
		std::cout << "for u to imagin dog sound :) !" << std::endl;	
}


