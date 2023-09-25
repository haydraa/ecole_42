#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
		std::cout << "Constructor of Dog class called" << std::endl;
}

Dog::Dog(const Dog &init)
{
	std::cout << "copy constructor of Dog calss called" << std::endl;
	*this = init;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Destructor of Dog class called" << std::endl;
}

Dog		&Dog::operator=(Dog const & init2)
{
	std::cout << "Assignement operator of Dog called" << std::endl;
	this->type = init2.getType();
	*(this->brain) = *(init2.getBrain());
	return *this;
}

Animal	&Dog::operator=(Animal const &init3)
{
	std::cout << "Animal Assignement operator for Dog called" << std::endl;
	this->type = init3.getType();
	*(this->brain) = *(init3.getBrain());
	return *this;
}

void	Dog::makeSound(void) const
{
		std::cout << "for u to imagin dog sound :) !" << std::endl;	
}

Brain	*Dog::getBrain( void ) const
{
	return (this->brain);
}
