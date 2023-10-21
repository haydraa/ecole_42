#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		try
		{
			clock_t start, end;
			double endV, endL;
			PmergeMe PM;

			PM.Parssing(argc, argv);
			PM.Stack(argc, argv);

			start = clock();
			PM.BeginV();
			end = clock();
			endV = static_cast<double>(end - start);
			endV = endV / 1000000.0;

			start = clock();
			PM.BeginL();
			end = clock();
			endL = static_cast<double>(end - start);
			endL = endL / 1000000.0;

			PM.Print(argc, argv, endV, endL);
		}
		catch (std::exception &e)
		{}
	}
	else
		std::cout << "No Argument To Parsse" << std::endl;
}
