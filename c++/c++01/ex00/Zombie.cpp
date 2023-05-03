#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "the beging of the end" << std::endl;
}

Zombie::~Zombi(void)
{
	std::cout << "end of the end" << std::endl;
}

void	Zombie::announce( void )
{
		std::cout << _name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}
