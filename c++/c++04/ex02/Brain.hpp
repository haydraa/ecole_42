#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public :
		Brain(void);
		Brain(const Brain &init);
		~Brain(void);

		Brain	&operator=(const Brain &init2);
		std::string ideas[100];
};

#endif
