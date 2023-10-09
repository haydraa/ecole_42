#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

int main(void)
{
	AForm		*form;
	try 
	{
		Intern		usefulIdiot;
		Bureaucrat	paul("Paul", 150);

		form = usefulIdiot.makeForm("this one doesn't exist", "Justin");
		if (form)
			delete form;
		form = usefulIdiot.makeForm("PresidentialPardonForm", "Maynard");
		if (form)
			delete form;
		form = usefulIdiot.makeForm("RobotomyRequestForm", "Danny");
		if (form)
			delete form;
		form = usefulIdiot.makeForm("ShrubberyCreationForm", "Adam");
		form->beSigned(paul);
		form->execute(paul);
		if (form)
			delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}
}
