#include "ScavTrap.hpp"

ScavTrap::ScavTrap(ScavTrap const &init)
{
	(void)init;
	std::cout << "copy ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(void)
{
}
ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "Default constructor called in ScavTrap" << std::endl;
	this->Name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &init)
{
	(void)init;
	std::cout << "Assingement operator called for Scavtrap" << std::endl;
//	std::cout << init << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "destroyer called for ScavTrap" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "<ScavTrap " << this->Name << "is now in Gate keeper mode>" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
		std::cout << "<ScavTrap " << this->Name << " attack " << target << std::endl;
}

