#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap :virtual public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &init);
		~ScavTrap(void);

		ScavTrap &operator=(const ScavTrap &init2);

		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif
