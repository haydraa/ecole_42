#ifndef SPAN_HPP
#define SPAN_HPP

#include <numeric>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

class Span 
{
	private:
		unsigned int Size;
		std::vector<int> vec;
	public:
		Span(unsigned int N);
		Span(void);	
		Span(const Span &init);
		Span &operator=(const Span &init);
		~Span(void);

		void	addNumber(int Add);
		void	addNumber(const std::vector<int>::iterator
		&begin, const std::vector<int>::iterator &end);
		unsigned int shortestSpan()const;
		unsigned int longestSpan()const;

		class Full : public std::exception
		{
			public: 
				const char *what() const throw()
				{
					return ("Container Full");
				}
		};
		class Empty : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("container Empty");
				}
		};
};

#endif
