#include "Zombie.hpp"

int	main(void)
{	
	std::string name_1 = "Malloc";
	std::string name_2 = "Random";
	Zombie *p;

	//std::cout << "malloc on stack::give me a name : ";
//	std::cin >> name_1;
	randomChump( name_1 );
//	std::cout << "malloc on heap::give me a name : ";
//	std::cin >> name_2;
	p = newZombie(name_2);
	p->announce();
	delete(p);
}
