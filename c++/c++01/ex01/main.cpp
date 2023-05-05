#include "zombieHorde.hpp"

int main(void)
{
	int N = 5;
	std::string name = "foo";
	Zombie *groups = zombieHorde(N, name);
	for (int i = 0; i < N; i++){
		groups[i].annonce();
	}
	delete[] groups;
	return 0;
}
