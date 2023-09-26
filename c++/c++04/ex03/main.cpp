#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->LearnMateria(new Ice());
	src->LearnMateria(new Cure());
	src->LearnMateria(new Ice());
	src->LearnMateria(new Cure());
	src->LearnMateria(new Ice());
	src->LearnMateria(new Ice());

	
	AMateria* tmp;
	AMateria* tmp2;
	
	tmp = src->CreateMateria("ice");
	tmp2 = src->CreateMateria("cure");

	std::cout << "---------Charecter 1-----------\n";
	
	ICharacter* me = new Character("me");

	me->Equip(tmp);
	me->Equip(tmp2);
	me->Equip(tmp);
	me->Equip(tmp2);
	me->Equip(tmp);
	me->PrintInventory();

	std::cout << "---------Charecter 2-----------\n";

	ICharacter* bob = new Character("bob");
	bob->Equip(tmp2);
	bob->Equip(tmp);
	bob->Equip(tmp2);	
	bob->Equip(tmp);
	bob->Equip(tmp2);
	bob->PrintInventory();
	
	std::cout << "------------USE ch  1 and 2--------\n"; 

	me->Use(0, *me);
	me->Use(1, *bob);
	me->Use(2, *me);
	me->Use(3, *bob);
	me->Use(4, *me);

	bob->Use(0, *me);
	bob->Use(1, *bob);
	bob->Use(2, *me);
	bob->Use(3, *bob);
	bob->Use(4, *me);

	std::cout << "-------------1 Unquip-------\n";
	
	me->Unequip(0);
	me->Unequip(1);
	me->Unequip(2);
	me->Unequip(3);
	me->Unequip(4);
	me->PrintInventory();
	me->Equip(tmp2);
	me->PrintInventory();
	
	std::cout << "-----------2 Unquip---------\n";
	
	bob->Unequip(0);
	bob->Unequip(1);
	bob->Unequip(2);
	bob->Unequip(3);
	bob->Unequip(4);
	bob->PrintInventory();
	bob->Equip(tmp);
	bob->PrintInventory();

	

	delete tmp;
	delete tmp2;
	delete bob;
	delete me;
	delete src;
	return 0;
}
