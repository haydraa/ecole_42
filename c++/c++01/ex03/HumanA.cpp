#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	if (_weapon.getType() != "")
	{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
	}
	else
	{
		std::cout << _name << " doesn't have a weapon to attack " << std::endl;
	}
}
