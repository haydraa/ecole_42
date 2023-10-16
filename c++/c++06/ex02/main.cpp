#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int Rand = std::rand() % 3;
		std::cout << Rand  << std::endl;
	switch (Rand)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base &ptr)
{
	try 
	{
		if (dynamic_cast<A *>(&ptr))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<C *>(&ptr))
			std::cout << "C" << std::endl;
		if (dynamic_cast<B *>(&ptr))
			std::cout << "B" << std::endl;
	}
	catch(std::exception &e)
	{
			std::cerr << e.what() << std::endl;
	}
}

void	identify(Base *ptr)
{
	A *a;
	if ((a = dynamic_cast<A *>(ptr)))
		std::cout << "A" << std::endl;
	B *b;
	if ((b = dynamic_cast<B *>(ptr)))
		std::cout << "B" << std::endl;
	C *c;
	if ((c = dynamic_cast<C *>(ptr)))
		std::cout << "C" << std::endl;
}

int main(void)
{
	Base	*base;

	std::cout << "Identifying with pointers" << std::endl;
	base = generate();
	identify(base);
	delete base;
	std::cout << "Identifying with refrence" << std::endl;
	base = generate();
	Base&	ref = *base;
	identify(ref);
	delete base;
}
