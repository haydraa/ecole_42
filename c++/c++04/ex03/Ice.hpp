#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice(void);
		Ice(const Ice &src);
		~Ice(void);

		Ice		&operator=(const Ice &other);
		virtual AMateria	*Clone(void) const;
		virtual void		Use(ICharacter& target);
}

#endif
