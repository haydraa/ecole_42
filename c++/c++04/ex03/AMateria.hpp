# ifndef AMATERIA
# define AMATERIA

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
			std::string	_Type;

	public:
		AMateria(const std::string &type);
		virtual ~AMateria();
		
		const std::string  &GetType(void) const;
		virtual AMateria* Clone(void) const = 0;
		virtual void Use(ICharacter& target) = 0;
};

#endif
