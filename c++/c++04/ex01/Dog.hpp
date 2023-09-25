#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	private :
		Brain *brain;
	
	public :
		Dog(void);
		Dog(const Dog &init);
		~Dog(void);
		Dog				&operator=(Dog const & init2);
		virtual Animal	&operator=(const Animal &init3);
		virtual void	makeSound(void) const;
		virtual Brain	*getBrain(void) const;
};


#endif