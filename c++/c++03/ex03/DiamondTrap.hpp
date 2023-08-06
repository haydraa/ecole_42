#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string Name;
		DiamondTrap(void);
	public :
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &init);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &init);
	
//	using	ClapTrap::takeDamage;
//	using	ClapTrap::beRepaired;	
	using	ScavTrap::attack;
	void	whoAmI(void)const;

};

#endif
