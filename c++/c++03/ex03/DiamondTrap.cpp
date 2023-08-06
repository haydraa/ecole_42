#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
{
	ClapTrap::Name = name + "_clap_name";
	this->Name = name;
	this->HitPoint = FragTrap::HitPoint;
	this->EnergyPoint = ScavTrap::EnergyPoint;
	this->AttackDamage = FragTrap::AttackDamage;
	std::cout << "Name constructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &init)
{
	std::cout << "Copy constructor for DiamondTrap called" << std::endl;
	*this = init;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor for DiamondTrap called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &init2)
{
	(void)init2;
	std::cout << "Assignment operator of DiamondTrap called" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI(void)const
{
	std::cout << "I am " << this->Name << " and ClapTrap name is " << ClapTrap::Name << std::endl;
}

