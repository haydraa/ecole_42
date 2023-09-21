# ifndef AMATERIA
# define AMATERIA

#include <iostream>
#include <string>

class AMateria
{
	protected:
		//
	public:
		AMateria(std::string const & type);
		//	[...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
