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
	{
		ClapTrap	haydra("haydra");
		ClapTrap	x("x");

		haydra.SetAttackDamage(7);
		haydra.attack("death");
		haydra.takeDamage(3);
	//	haydra.attack("1");
	//	haydra.attack("2");
	//	haydra.attack("3");
	//haydra.takeDamage(30);

		haydra.beRepaired(2);
	//	haydra.attack("4");
	//	haydra.attack("5");
	//	haydra.attack("6");
		haydra.attack("7");

		haydra.attack("8");
		haydra.attack("9");
	}
}
