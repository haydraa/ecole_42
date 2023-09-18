#include "PhoneBook.hpp"

int	PhoneBook::PutFn(std::string str, int i)
{
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "First_name: ";
			if (!std::getline(std::cin, str))
				return (1);
		}
	}
	data[i].FirstName = str;
	return (0);
}
		 
int  PhoneBook::PutLn(std::string str, int i)
{		
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "Last_name: ";
			if (!std::getline(std::cin, str))
				return (1);
		}
	}
	data[i].LastName = str;
	return (0);
}
		
int	 PhoneBook::PutNkm(std::string str, int i)
{
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "Nickname: ";
			if (!std::getline(std::cin, str))
				return (1);
		}
	}
	data[i].Nickname = str;
	return (0);
}

int	 PhoneBook::PutPhn(std::string str, int i)
{
	data[i].PhoneNumber = str;
	return (0);
}  

int	 PhoneBook::PutDs(std::string str, int i)
{
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "Darkest_secret: ";
			if (!std::getline(std::cin, str))
				return (1);
		}
	}
	data[i].DarkestSecret = str;
	return (0);
}  


int	PhoneBook::CheckNum(std::string str)
{
	int		v;
	
	v = 0;
	while (str[v])
	{
		if (!(str[v] >= 48 && str[v] <= 57))
		{
			std::cout << "Phone_number need only numbers.\n";
			std::cout << "Phone_number: ";
			if (!std::getline(std::cin, str))
				return (1);
			CheckNum(str);
		}
 		v++;
	}
	return (0);
}

int PhoneBook::FtReaplace()
{
	std::string str;

	std::cout << "First_name: ";
	if (!std::getline(std::cin, str))
		return (1);
	if (PutFn(str, index2) == 1)
		return (1);
	std::cout << "Last_name: ";
	if (!std::getline(std::cin, str))
		return (1);
	if (PutLn(str, index2) == 1)
		return (1);
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, str))
		return (1);
	if (PutNkm(str, index2))
		return (1);
	std::cout << "Phone_number: ";
	if (!std::getline(std::cin, str))
		return (1);
	if (CheckNum(str) == 1)
		return (1);
	if (PutPhn(str, index2) == 1)	
		return (1);
	std::cout << "Darkest_secret: ";
	if (!std::getline(std::cin, str))
		return (1);
	if (PutDs(str, index2) == 1)
		return (1);
	index2++;
	if (index2 > 7)
		index2 = 0;
	return (0);
}

void	PhoneBook::FtAcces(std::string str, int i)
{
	if (str.compare("last_name"))
		FtDisplay(data[i].LastName);
	else if(str.compare("first_name"))
		FtDisplay(data[i].FirstName);
	else if(str.compare("nickname"))
		FtDisplay(data[i].Nickname);
}

