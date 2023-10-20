#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &init)
{
	this->List = init.List;
	this->Vector = init.Vector;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &init)
{
	if (this != &init)
		*this = init;
	return *this;
}

PmergeMe::~PmergeMe()
{}

bool	isInteger(char *str)
{
	char *endptr;
	strtol(str, &endptr, 10);
	if (*endptr != '\0')
	{
		std::cout << "Argument has a non intger value"<< std::endl;
		return false;
	}
	if (errno == ERANGE)
	{
		std::cout << "OverFlow Occured" << std::endl;
		return false;
	}
	return true;
}

void	PmergeMe::Parssing(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!isInteger(argv[i]))
			throw Erorr();
	}
}

void	PmergeMe::Stack(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::istringstream ss(argv[i]);
		int ret;
		ss >> ret;
		this->List.push_back(ret);
		this->Vector.push_back(ret);
	}
}


