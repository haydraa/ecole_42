#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->HitPoint = 10;
	this->Energypoint = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& init)
{
	std::cout << "copy constructor called" <<  std::endl;
	*this = init;
}

ClapTrap::(std::string name)
{
	this->name = name;
	this->HitPoint = 10;
	this->Energypoint = 10;
	this->AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destroyer called" << std::endl;
}

ClapTrap	ClapTrap::operator=(const ClapTrap& init2)
{
	this->setName(init2.getName());
	this->setHitePoint(init2.getHitPoint());
	this->setEnergyPoint(init2.getEnergyPoint());
	this->setAttackDamage(init2.getAttackDamage());

	return (*this);
}

const std::string&	Claptrap::GetName()const
{
	return (this->name);
}

unsigned int	ClapTrap::GetHitPoint()const
{
	return (this->HitPoint)
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
	this->name = name;
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

void	ClapTrap::attack(const std::string target)
{
	if (this->EnergyPoint < 1)
	{
		std::cout << "<ClapTrap " << this->name << "does not have any enregy to attack>" << std::endl;
		std::cout << "EnergyPoint left: " << this->EnergyPoint << std::endl; 
	}
	else
	{
		this->energypoint -= 1;
		std::cout << "<CLapTrap " << this->name << "attack " << target << ">" << std::endl;
		std::cout << "EnergyPoint left: " << this->Energypoint << std::endl;
	}
}

void	ClapTrap::takeDamge(unsigned int amount)
{
	if (amount > this->HitPoint)
		this->HitPoint = 0;
	else
	{
		this->HitPoint -= amount;
		std::cout << "<ClapTrap " << this->name << " got " << amount << "point of damage! >"
		std::cout << "HitPoint: " << this->HitPoint << ": after Damage" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned  int amount)
{
	this->EnergyPoint -= 1;
	this->hitPoint += amount;
	std::cout << "<ClapTrap " << this->name << " repaired" << std::endl;
	std::cout << "HitPoint: " << this->hitPoint << std::endl;
}



