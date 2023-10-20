#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc > 1 && argc < 3)
	{
		RPN rpn(argv[1]);
		try
		{
			rpn.ToStack();
			rpn.Print();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else 
		std::cout << "Expeted One Argument" << std::endl;
	return 0;
}
