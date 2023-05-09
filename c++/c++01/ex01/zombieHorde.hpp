#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP 

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		void annonce(void);
		
		void	ZombieSet(std::string name);	
		Zombie();
		~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
