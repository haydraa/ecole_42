#include "Character.hpp"

Character::Character(void): _Name(""), _NumberEquipped(0)
{
	for (int i = 0; i < Character::_InventorySize; i++)
		this->_Inventory[i] = NULL;
	std::cout << "Default constructor for Character called" << std::endl;
	return;
}

Character::Character(const std::string &name): _Name(name), _NumberEquipped(0)
{
	for (int i = 0; i < Character::_InventorySize; i++)
		this->_Inventory[i] = NULL;
	std::cout << "Name constructor for Character called" << std::endl;
	return;
}

Character::Character(Character const & src)
{
	std::cout << "Copy constructor for Character called" << std::endl;
	*this = src;
	return;
}

Character::~Character( void )
{
	std::cout << "Destructor for Character called" << std::endl;
	return;
}

Character &	Character::operator=(Character const & rhs)
{
	this->_NumberEquipped = 0;
	for (int i = 0; i < Character::_InventorySize; i++)
	{
		if (this->_Inventory[i])
			delete this->_Inventory[i];
		this->_Inventory[i] = rhs._Inventory[i];
		if (rhs._Inventory[i])
			this->_NumberEquipped++;
	}
	this->_Name = rhs.GetName();
	std::cout << "Assignement operator for Character called" << std::endl;
	return *this;
}

std::string const	&Character::GetName() const
{
	return (this->_Name);
}

void	Character::Equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Materia does not exist"<< std::endl;
		return ;
	}
	if (this->_NumberEquipped < Character::_InventorySize)
	{
		this->_Inventory[this->_NumberEquipped] = m;
		this->_NumberEquipped++;
		std::cout << "Equiped a " << m->GetType() << std::endl;
	}
	else
		std::cout << "Couldn't equip a " << m->GetType() << ", no more space"
			<< std::endl;
}

void	Character::Unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "there is nothing to unequip here" << std::endl;
		return ;
	}
	else
	{
		this->_Inventory[idx] = NULL;
		this->_NumberEquipped--;
	}
}

void	Character::Use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Nothing to use here" << std::endl;
		return ;
	}
	else
	{
		if (!_Inventory[idx])
		{
			std::cout << "Index empty" << std::endl;
			return;
		}
		this->_Inventory[idx]->Use(target);
	}
}

void	Character::PrintInventory( void ) const
{
	for (int i = 0; i < Character::_InventorySize; i++)
	{
		if (this->_Inventory[i])
			std::cout << i << ": " << this->_Inventory[i]->GetType() << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}
}


