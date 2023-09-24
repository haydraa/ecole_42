#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->LearnMateria(new Ice());
	src->LearnMateria(new Cure());
	src->LearnMateria(new Cure());
	src->LearnMateria(new Cure());
	src->LearnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->CreateMateria("ice");
	me->Equip(tmp);
	tmp = src->CreateMateria("cure");
	me->Equip(tmp);
	ICharacter* bob = new Character("bob");
	me->Use(0, *bob);
	me->Use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}
