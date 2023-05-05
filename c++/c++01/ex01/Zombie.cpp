#include "zombieHorde.hpp"
	
Zombie::Zombie(std::string name)
{
	std::cout << "the zombie is alive in the horde" << std::endl;
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "zombie is dead" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}
