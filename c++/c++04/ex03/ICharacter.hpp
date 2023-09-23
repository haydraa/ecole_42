#ifndef ICharacter_HPP
#define ICharacter_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter(){}

		virtual std::string const & GetName() const = 0;
		virtual void Equip(AMateria* m) = 0;
		virtual void Unequip(int idx) = 0;
		virtual void Use(int idx, ICharacter& target) = 0;
		virtual void PrintInventory(void)const = 0;
};

#endif
