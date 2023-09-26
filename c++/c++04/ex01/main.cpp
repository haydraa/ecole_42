#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::cout << "----------------test1--------------------------------" << std::endl;
	{
			Animal	*animals[8];
		Brain	*brain;

		for (int i = 0; i < 8; i++)
		{
			if (i < 8 / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			std::cout << animals[i]->getType() << std::endl;
		}

		brain = animals[7]->getBrain();
		brain->ideas[0] = "I'm hungry";
		brain->ideas[1] = "That's a strange idea I'm having";
		brain->ideas[2] = "Ball!!!!!";
		brain->ideas[3] = "Squirrel!!!!!";
		std::cout << animals[7]->getBrain()->ideas[0] << std::endl;
	
		*(animals[5]) = *(animals[7]);
		std::cout << animals[5]->getBrain()->ideas[2] << std::endl;

		for (int i = 0; i < 8; i++)
			delete animals[i];
	}
	std::cout << "----------------test2--------------------------------" << std::endl;
	
	{
			const Animal* j = new Dog();
 	 	const Animal* i = new Cat();
		
		delete j;//should not create a leak	
		delete i;


    	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    	for ( int i = 0; i < 4; i++ ) {
    	    delete animals[i];
    	}
	}
    return 0;	
}
