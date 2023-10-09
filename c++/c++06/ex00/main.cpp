#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter Scalar;
	try
	{
		if (argc < 1)
		{
			Scalar.Analyse(argv[1]);
			scalat.printTypes();
	//		std::cout << std::endl;
		}
		else
			throw (ScalarConverter::EmptyInput());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
