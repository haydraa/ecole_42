#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

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