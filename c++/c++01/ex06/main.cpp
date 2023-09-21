#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl comp;

	if (argc < 2 || argc > 2)
	{
		std::cout << "faild argumaent" << std::endl;
		return (1);
	}
	comp.complain(argv[1]);
}
