#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", 72,45), Name("")
{
//	std::cout << "Contrucor Of Default Called For RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name):
	AForm("RobotomyRequestForm", 72, 45), Name(name)
{
//	std::cout << "Constructor For RobotomyRequestForm Called"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &init):
	AForm("RobotomyRequestForm", 72, 45), Name(init.GetName())
{
//	std::cout << "Copy Constructor For RobotomyRequestForm Called" << std::endl;
	if (this != &init)
		*this = init;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
//	std::cout << "Destructor Called For RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &init)
{
//	std::cout << "Name is const u Can't have a copy" << std::endl;
	(void)init;
	return (*this);
}

const std::string	RobotomyRequestForm::GetName(void) const
{
	return (Name);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << "* Unbearable Drilling Noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->Name << "Has Been Sucessfully Robotomized" << std::endl;
	else
		std::cout << "The Robotomization" << this->Name << "Failed" << std::endl;
}
