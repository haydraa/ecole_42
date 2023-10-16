#include "Serialization.hpp"


Serialize::Serialize(void)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Serialize::Serialize(const Serialize &init)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &init)
		*this = init;
	return ;
}

Serialize::~Serialize(void)
{
	std::cout << "Destructor Called" << std::endl;
}

Serialize &Serialize::operator=(const Serialize &init)
{
	(void)init;
	std::cout << "There is Nothing To Assigne Here" 
			<< std::endl;
	return (*this);
}

uintptr_t Serialize::serialize(t_data *ptr)
{
	uintptr_t value = reinterpret_cast<uintptr_t>(ptr);

	return value;
}

t_data *Serialize::deserialize(uintptr_t raw)
{
	t_data *ptr = reinterpret_cast<t_data *>(raw);
	return ptr;
}
