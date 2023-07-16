#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked");
		HumanA bob("Bob", club);
		HumanB jim("Jim");
		bob.attack();
		jim.attack();
		club.setType("chain");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("saw");
		jim.attack();
	}
	return 0;
}
