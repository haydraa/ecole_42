#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor Called for Barin" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Default Destructor Called for Brain" << std::endl;
}

Brain::Brain(const Brain &init)
{
	std::cout << "copy Constructor Called for Brain" << std::endl;
	*this = init;
}

Brain	&Brain::operator=(Brain const &init2)
{
	std::cout << "Assignement operator called for Brain " << std::endl;
	for (int  i = 0; i < 100; i++)
		this->ideas[i] = init2.ideas[i];
	return (*this);
}

