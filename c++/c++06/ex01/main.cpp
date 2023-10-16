#include "Serialization.hpp"

int main(void)
{
	t_data *ptr = new t_data;
	t_data *temp;
	uintptr_t raw;
	Serialize Ser;

	ptr->i = 4;
	ptr->str = "lol";
	raw = Ser.serialize(ptr);
	std::cout << raw << std::endl;
	temp = Ser.deserialize(raw);
	std::cout << temp->i << " " << temp->str << std::endl;
	delete temp;
}
