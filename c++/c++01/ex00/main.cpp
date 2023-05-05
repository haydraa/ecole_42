#include "Zombie.h"



int	main(void)
{
	std::string name_1;
	int *p;

	std::cout << "malloc on stack::give me a name : ";
	std::cin >> _name;
	randomChump( _name ) ;
	std::cout << "malloc on heap::give me a name : ";
	std::cin >> name_1;
	p = newZombie(name_1);
}
