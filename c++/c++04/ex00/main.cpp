#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	
	
	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* Wrong = new WrongCat();
	
	std::cout << Wrong->getType() << " " << std::endl;
	metaWrong->makeSound(); //will output the cat sound!
	Wrong->makeSound(); //will output the cat sound!
	
	delete metaWrong;
	delete Wrong;

return 0;
}
