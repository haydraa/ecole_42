#include "zombieHorde.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	for(int i = 0; i < N; i++){
		horde[i].ZombieSet(name);
	}
	return (horde);
}
