#include <iostream>

int main(void)
{
	std::string name = "HI THIS IS BRAIN";
	std::string* stringPTR;
	std::string& stringREF = name;
	
	stringPTR = &name;

	std::cout << "value of string: " << std::endl;
	std::cout << name << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	std::cout << "adress of string: " << std::endl;
	std::cout << &name << std:: endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
}
