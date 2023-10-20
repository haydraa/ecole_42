#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		clock_t start, end;
		double endV, endL;
		PmergeMe PM;

		PM.Parssing(argc, argv);
		PM.Stack(argc, argv);
		start = clock();
		PM.mergeAndSortVictor();
		end = clock();
		endV = double(end - start);
		start = clock();
		PM.mergeAndSortVictor();
		end = clock();
		endL = double(end - start);
		PM.Print(endV, endL);1


	}
	catch (std::exception &e)
	{}
}
