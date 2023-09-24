#ifndef IMateriaSource_HPP
#define IMateriaSource_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void LearnMateria(AMateria*) = 0;
		virtual AMateria* CreateMateria(std::string const & type) = 0;
};


#endif
