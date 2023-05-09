#include "zombieHorde.hpp"
	
Zombie::Zombie()
{
	std::cout << "the zombie is alive in the horde" << std::endl;
}

void Zombie::ZombieSet(std::string name)
{
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "zombie is dead" << std::endl;
}

void	Zombie::annonce( void )
{
	std::cout << _name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}
