#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP 

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		void annonce(void);
		
		Zombie(std::string name);
		~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
