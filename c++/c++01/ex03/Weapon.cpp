#include "Weapon.hpp"

Weapon::Weapon(std::string _name)
{
		Weapon::type = _name;
}

Weapon::~Weapon()
{
	std::cout << "end of attack :)" << std::endl;
}

const std::string&	Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string Nt)
{
	Weapon::type = Nt;
}


