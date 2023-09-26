#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected :
		std::string type;
	public :
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &init);
		~WrongAnimal(void);

		WrongAnimal &operator=(WrongAnimal const & init2);

		const std::string	&getType(void) const;
		void	makeSound(void)const;
};

#endif
