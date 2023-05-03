#ifndef "ZOMBIE_H"
#define "ZOMBIE_H"

#include <iostream>

class Zombie
{
	private:
		std::string _name;
	
	public:
		void announce( void ); 

		Zombie(void);
		~Zombi(void);

		Zombie* newZombie(std::string name);
		void	randomChump(std::string name);
}
