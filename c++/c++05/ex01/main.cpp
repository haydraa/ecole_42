#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Form f("STD78", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout <<std::endl;
	
	try
	{
		Form f("STD78", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout <<std::endl;
	
	try
	{
		Form f("STD78", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout <<std::endl;	
	
	try
	{
		Form f("STD78", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout <<std::endl;

	try
	{
		Bureaucrat	john = Bureaucrat("John", 1);
		Form		f("STD114", 150, 150);

		std::cout << f << std::endl;
		john.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	joe = Bureaucrat("Joe", 10);
		Form		f("STD115", 1, 1);

		std::cout << f << std::endl;
		joe.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
