#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected :
		std::string type;

	public :
		Animal(void);
		Animal(const Animal &init);
		virtual ~Animal(void);

		Animal	&operator=(const Animal &init2);
		virtual void	makeSound(void) const;
		const std::string &getType(void)const;
	virtual Brain		*getBrain( void ) const = 0;
};

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

class Cat : public Animal
{
	private :
		Brain *brain;
	
	public :
		Cat(void);
		Cat(const Cat &init);
		~Cat();
		Cat				&operator=(Cat const & init2);
		virtual Animal	&operator=(const Animal &init3);
		virtual void	makeSound(void) const;
		virtual Brain	*getBrain(void) const;
	
};

#endif
