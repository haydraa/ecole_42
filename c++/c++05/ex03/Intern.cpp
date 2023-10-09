#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Constructor For Intern Called" << std::endl;
}

Intern::Intern(const Intern &init)
{
	std::cout << "Copy Constructor Called For Intern" << std::endl;
	if (this != &init)
		*this = init;
	return;
}

Intern::~Intern(void)
{
	std::cout << "Destructor For Intern Called" << std::endl;
}

Intern &Intern::operator=(const Intern &init)
{
	std::cout << "Assignment Constructor Called For Intern" << std::endl;
	(void)init;
	return (*this);
}

AForm	*Intern::makeForm(std::string Form, std::string target)const
{
	int index;
	AForm *Result = NULL;
	std::string	Forms[4] = {"ShrubberyCreationForm",
						"RobotomyRequestForm",
						"PresidentialPardonForm"};
	index = 3;
	for (int i = 0; i < 3; i++)
	{
		if (Forms[i] == Form)
			index = i;
	};
	switch(index)
	{
		case 0:
			Result = new ShrubberyCreationForm(target);
			break;
		case 1:
			Result =  new RobotomyRequestForm(target);
			break;
		case 2:
			Result = new PresidentialPardonForm(target);
			break;
		case 3:
			Result = NULL;
			break;
	}
	if (Result == NULL)
		std::cout << "Intern Has a trouble Finding The Form" << std::endl;
	else
		std::cout << "Intern Creates" << Form << std::endl;
	return  (Result);
}



