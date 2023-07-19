#include "ClapTrap.hpp"

ClapTrap::ClapTrap(ClapTrap const &init)
{
	std::cout << "copy constructor called" <<  std::endl;
	*this = init;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor called" << std::endl;
	this->Name = name;
	this->HitPoint = 10;
	this->EnergyPoint = 10;
	this->AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destroyer called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &init)
{
	this->SetName(init.GetName());
	this->SetHitPoint(init.GetHitPoint());
	this->SetEnergyPoint(init.GetEnergyPoint());
	this->SetAttackDamage(init.GetAttackDamage());

	return (*this);
}

const std::string&	ClapTrap::GetName()const
{
	return (this->Name);
}

unsigned int	ClapTrap::GetHitPoint()const
{
	return (this->HitPoint);
}

unsigned int	ClapTrap::GetAttackDamage()const
{
	return (this->AttackDamage);
}

unsigned int	ClapTrap::GetEnergyPoint()const
{
	return (this->EnergyPoint);
}

void	ClapTrap::SetName(const std::string& name)
{
	this->Name = name;
}
 
void	ClapTrap::SetHitPoint(unsigned int Nhp)
{
	//Nhp = new hit point
	this->HitPoint = Nhp;
}

void	ClapTrap::SetEnergyPoint(unsigned int Nep)
{
	//Nep = new energy point 
	this->EnergyPoint = Nep;
}

void	ClapTrap::SetAttackDamage(unsigned int Nad)
{
	//Nad = new attack damage
	this->AttackDamage = Nad;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoint < 1)
	{
		std::cout << "<ClapTrap " << this->Name << "does not have any enregy to attack>" << std::endl;
		std::cout << "EnergyPoint left: " << this->EnergyPoint << std::endl; 
	}
	else
	{
		this->EnergyPoint -= 1;
		std::cout << "<CLapTrap " << this->Name << " attack " << target << ">" << std::endl;
		std::cout << "EnergyPoint left: " << this->EnergyPoint << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->HitPoint)
	{
		std::cout << "<ClapTrap " << this->Name << " got " << amount << " point of damage! a lot ?>" << std::endl;
		std::cout << "HitPoint: " << this->HitPoint << " : after Damage" << std::endl;
		this->HitPoint = 0;
	}
	else
	{
		this->HitPoint -= amount;
		std::cout << "<ClapTrap " << this->Name << " got " << amount << " point of damage! >" << std::endl;
		std::cout << "HitPoint: " << this->HitPoint << " : after Damage>" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned  int amount)
{
	this->EnergyPoint -= 1;
	this->HitPoint += amount;
	std::cout << "<ClapTrap " << this->Name << " repaired" << std::endl;
	std::cout << "HitPoint: " << this->HitPoint << std::endl;
}



