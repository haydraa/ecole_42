#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"
#include <iostream>

class Dog : public AAnimal
{
	private :
		Brain *brain;
	
	public :
		Dog(void);
		Dog(const Dog &init);
		~Dog(void);
		Dog				&operator=(Dog const & init2);
		virtual AAnimal	&operator=(const AAnimal &init3);
		virtual void	makeSound(void) const;
		virtual Brain	*getBrain(void) const;
};


#endif