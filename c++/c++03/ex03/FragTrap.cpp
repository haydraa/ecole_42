#include "FragTrap.hpp"

FragTrap::FragTrap(FragTrap const &init)
{
	(void)init;
	std::cout << "copy FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(void)
{
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "Default constructor called in FragTrap" << std::endl;
	this->Name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 30;
}

FragTrap &FragTrap::operator=(FragTrap const &init)
{
	(void)init;
	std::cout << "Assingement operator called for FragTrap" << std::endl;
//	std::cout << init << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "give me a hight five guys" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "destroyer called for FragTrap" << std::endl;
}

