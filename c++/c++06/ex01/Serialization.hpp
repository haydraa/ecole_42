#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>

typedef struct m_data
{
	int i;
	std::string str; 
}	t_data;

class Serialize
{
	private:
	
	public:
		Serialize(void);
		Serialize(const Serialize &init);
		Serialize &operator=(const Serialize &init);
		~Serialize(void);

		uintptr_t  serialize(t_data *ptr);
		t_data *deserialize(uintptr_t raw);
};

#endif
