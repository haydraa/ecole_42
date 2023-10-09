#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

int main(void)
{
		AForm	*Form;
		Bureaucrat Sezar("Cesar", 42);
		Bureaucrat jhon("Jhon", 150);
		Bureaucrat haydra("haydra",1);
	
	try
	{
		Form = new RobotomyRequestForm("28F");
		Form->beSigned(haydra);
		Form->execute(haydra);
		delete(Form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form = new PresidentialPardonForm("28F");
		Form->beSigned(haydra);
		Form->execute(haydra);
		delete(Form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form = new ShrubberyCreationForm("28F");
		Form->beSigned(haydra);
		Form->execute(haydra);
		delete(Form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
