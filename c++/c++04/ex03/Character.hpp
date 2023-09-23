#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(const std::string &name);
		Character(const Character &src);
		~Character(void);

		Character &operator=(const Character &other);

		virtual std::string const	&GetName() const ;
		virtual void				Equip(AMateria* m);
		virtual void				Unequip(int idx);
		virtual void				Use(int idx, ICharacter& target);

		virtual void				PrintInventory(void) const ;

	private:

		Character(void);

		static const int	_InventorySize = 4;
		std::string			_Name;
		AMateria			*_Inventory[Character::_InventorySize];
		int					_NumberEquipped;
};

#endif
