#ifndef CURE_HPP
#define CURE_HPP


#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &src);
		~Cure(void);
		
		Cure &operator=(const Cure &other);

		virtual	AMateria	*Clone(void)const;

		virtual void	Use(ICharacter& target);
	private:
}

#endif
