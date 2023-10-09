#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	haydra = Bureaucrat("haydra", -1);
		std::cout << haydra << std::endl;
		haydra.DecrementGrade(1);
		std::cout << haydra << std::endl;
		haydra.IncrementGrade(1);
		std::cout << haydra << std::endl;
		haydra.IncrementGrade(1);
		std::cout << haydra << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout <<std::endl;

	try
	{
		Bureaucrat	bob = Bureaucrat("bob", 150);
		std::cout << bob << std::endl;
		bob.IncrementGrade(1);
		std::cout << bob << std::endl;
		bob.DecrementGrade(1);
		std::cout << bob << std::endl;
		bob.DecrementGrade(1);
		std::cout << bob << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout <<std::endl;
	
	try
	{
		Bureaucrat	joe = Bureaucrat("joe", 1);
		std::cout << joe << std::endl;
		joe.DecrementGrade(1);
		std::cout << joe << std::endl;
		joe.IncrementGrade(1);
		std::cout << joe << std::endl;
		joe.IncrementGrade(1);
		std::cout << joe << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout <<std::endl;
}
