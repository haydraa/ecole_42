#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	protected :
		std::string type;

	public :
		virtual ~AAnimal(void);
		virtual	AAnimal	&operator=(const AAnimal &init2) = 0;
		virtual void	makeSound(void) const = 0;
		const std::string &getType(void)const;
		virtual Brain		*getBrain(void) const = 0;
};

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

class Cat : public AAnimal
{
	private :
		Brain *brain;
	
	public :
		Cat(void);
		Cat(const Cat &init);
		~Cat();
		Cat				&operator=(Cat const & init2);
		virtual AAnimal	&operator=(const AAnimal &init3);
		virtual void	makeSound(void) const;
		virtual Brain	*getBrain(void) const;
	
};

#endif
