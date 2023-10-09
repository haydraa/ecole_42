#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string name): 
	AForm("PresidentialPardonForm", 25 ,5), Name(name)
{
	std::cout << "Constructor Called For PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(void): 
	AForm("PresidentialPardonForm", 25, 5), Name("")
{
	std::cout << "Constructor For PresidentialPardonForm Of Default Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &init):
	AForm("PresidentialPardonForm", 25 ,5), Name(init.GetName())
{
	std::cout << "Copy Constructo For PresidentialPardonForm Called" << std::endl;
	if (this != &init)
		*this = init;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &init)
{
	std::cout << "Assignment Called For PresidentialPardonForm and Can't do Anything" << std::endl;
	(void)init;
	return (*this);
}

const std::string	&PresidentialPardonForm::GetName(void) const
{
	return Name;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << this->Name << "has been pardoned by zafod Beeblebrow" << std::endl;
}
