#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc > 1)
		{		
			ScalarConverter Scalar(argv[1]);
		//	Scalar.Analyse(argv[1]);
			Scalar.printType();
	//		std::cout << std::endl;
		}
		else
			throw (ScalarConverter::EmptyInput());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
