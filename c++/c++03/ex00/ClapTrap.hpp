#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
	private :
		std::string		Name;
		unsigned int	HitPoint;
		unsigned int	EnergyPoint;
		unsigned int	AttackDamage;
	public :
		ClapTrap(std::string name);
		ClapTrap(void);
		ClapTrap(ClapTrap const& init);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& init);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const	std::string& GetName()const;
		unsigned int	GetHitPoint()const;
		unsigned int	GetEnergyPoint()const;
		unsigned int	GetAttackDamage()const;
		void	SetName(const std::string& name);
		void	SetHitPoint(unsigned int Nhp);
		void	SetEnergyPoint(unsigned int Nep);
		void	SetAttackDamage(unsigned int Nad);
};


#endif
