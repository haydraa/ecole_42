#ifndef ESAYFIND_HPP
#define ESAYFIND_HPP

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

class NotFound : public std::exception
{
	public:
		const char * what() const throw()
		{
			return ("Element Not Found");
		}
};

template <typename T>
typename T::iterator easyfind(T& Container ,int find)
{
	typename T::iterator it = std::find(Container.begin(),
				Container.end(), find);
	if (it != Container.end())
		return (it);
	else
		throw NotFound();
}



#endif 
