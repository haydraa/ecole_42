#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
 	public :
 		FragTrap(void);
 		FragTrap(const std::string name);
		FragTrap(const FragTrap &init);
		~FragTrap(void);

	FragTrap &operator=(const FragTrap &init2);
	void	highFivesGuys(void);
}; 
#endif
