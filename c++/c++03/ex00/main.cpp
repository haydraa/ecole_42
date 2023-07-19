#include "ClapTrap.hpp"

int main(void)
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
