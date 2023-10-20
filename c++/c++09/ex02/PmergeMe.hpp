#ifndef PMERGME_HPP
#define PMERGME_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cerrno>
#include <exception>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
	private:
		std::list<int> List;
		std::vector<int> Vector;
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &init);
		PmergeMe &operator=(const PmergeMe &init);
		~PmergeMe(void);

		void	Parssing(int argc, char **argv);
		void	Stack(int argc, char **argv);

		class Erorr : public std::exception
		{
			const char *what() const throw()
			{
				return "";
			}
		};
};


#endif 
