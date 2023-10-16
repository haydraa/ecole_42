#include "easyfind.hpp"

int main(void)
{
	std::vector<int>  vec;
	int find = 3;
	
	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	try{
		std::vector<int>::iterator it = easyfind(vec, find);
		std::cout << "Element Found: " << *it << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	find = 100;

	try	{
		std::vector<int>::iterator it = easyfind(vec, find);
		std::cout << "Element Found: " << *it << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
