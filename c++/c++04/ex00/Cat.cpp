#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat &init) : Animal(init)
{
	std::cout << "copy constructor for Cat called" << std::endl;
	*this = init;
}

Cat::~Cat(void)
{
	std::cout << "Destructor for Cat Called" << std::endl;
}

void	Cat::makeSound(void)const
{
	std::cout << "for u to imagine the sound of a cat :) !" << std::endl;
}
