#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap haydra1("haydra1");

		haydra1.attack("Handsome Jack");
		haydra1.takeDamage(6);
		haydra1.beRepaired(4);
		haydra1.takeDamage(3);
		haydra1.guardGate();
		haydra1.beRepaired(8);
		haydra1.takeDamage(17);
	}
}
