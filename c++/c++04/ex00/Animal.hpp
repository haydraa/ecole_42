#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

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
};

#endif
