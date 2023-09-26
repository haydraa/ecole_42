#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "Default constructor for WrongCat Called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &init) : WrongAnimal(init)
{
	std::cout << "copy constructot for WrongCat Called" << std::endl;
	*this = init;
}

WrongCat::~WrongCat(void)
{
	std::cout << "destructor for WrongCat Called" << std::endl;	
}

void	WrongCat::makeSound(void)const
{
	std::cout << "you know the sound of the cat imagin it !" << std::endl;
}
