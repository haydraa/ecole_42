#include "Animal.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &init)
{
	std::cout << "copy constructor for Cat called" << std::endl;
	*this = init;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Destructor for Cat Called" << std::endl;
}

void	Cat::makeSound(void)const
{
	std::cout << "for u to imagine the sound of a cat :) !" << std::endl;
}

Cat		&Cat::operator=(Cat const &init2)
{
	std::cout << "Assignement operator for Cat called" << std::endl;
	this->type = init2.getType();
	*(this->brain) = *(init2.getBrain());
	return *this;
}

Animal	&Cat::operator=( Animal const &init3 )
{
	std::cout << "Animal Assignement operator for Cat called" << std::endl;
	this->type = init3.getType();
	*(this->brain) = *(init3.getBrain());
	return *this;
}

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}
