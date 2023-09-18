#include "PhoneBook.hpp"

int	PhoneBook::FtAdd()
{
	std::string str;
	if (index < 8)
	{	
		std::cout << "First_name: ";
		if (!std::getline(std::cin, str))
			return(1);
		if (PutFn(str, index) == 1)
			return(1);
		std::cout << "Last_name: ";
		if (!std::getline(std::cin, str))
			return(1);
		if (PutLn(str, index) == 1)
			return (1);
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, str))
			return(1);
		if (PutNkm(str, index) == 1)
			return (1);
		std::cout << "Phone_number: ";
		if (!std::getline(std::cin, str))
			return(1);
		if (CheckNum(str) == 1)
			return (1);
		if (PutPhn(str, index) == 1)
			return (1);	
		std::cout << "Darkest_secret: ";
		if (!std::getline(std::cin, str))
			return(1);
		if (PutDs(str, index) == 1)
			return (1);
		index++;
	}
	else
		if (FtReaplace() == 1)
			return (1);
	return (0);
}

void	PhoneBook::FtDisplayIndex(int index)
{
	std::cout << "First_name: ";
	std::cout << data[index].FirstName << std::endl;
	std::cout << "Last_name: ";
	std::cout << data[index].LastName << std::endl;
	std::cout << "Nickname: ";
	std::cout << data[index].Nickname << std::endl;
	std::cout << "Phone_number: ";
	std::cout << data[index].PhoneNumber << std::endl;
	std::cout << "Darkest_secret: ";
	std::cout << data[index].DarkestSecret << std::endl;
	return ;
}

void	PhoneBook::FtShearch2()
{
	int	in;
	std::string	str;
	int i;

	i = 0;
	std::cout << "Give an index: ";
	if(!std::getline(std::cin, str))
		return;
	if (str[i] == '\0')
	{
		std::cout << "your index is wrong" << std::endl;
		return ;
	}
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 56))  
		{
			std::cout << "your index is wrong" << std::endl;
			return;
		}
		i++;
	}
	in = std::atoi(str.c_str());
	if (in > index - 1)
	{
		std::cout << "index empty!!!" << std::endl;
		return;
	}
	else 
	{
		FtDisplayIndex(in);
		return;
	}	
}

void PhoneBook::FtDisplay(std::string str)
{
	int len;

	len = str.length();
	if (len >= 10)
		std::cout << std:: setw(9) << std::right << str.substr(0,9) << ".";	
	else
		std::cout << std::setw(10) << std::right << str;
	std::cout << " | ";
}

void	PhoneBook::FtShearch()
{
	int i;
	std::string	str;

	i = 0;
	if (index == 0)
	{
		std::cout << "no contact yet !!\n";
		return;
	}
	while (i < index)
	{
		std::cout << i << " | ";
		FtAcces("last_name" ,i);
		FtAcces("first_name" ,i);
		FtAcces("nickname" ,i);
		std::cout << '\n';
		i++;
	}
	FtShearch2();
}

void    PhoneBook::Start()
{
	std::string cmd;
	
	std::cout << "Hi! Welcome to the awsome Phone Book\n";
	std::cout << "You have 3 command to use, [ADD, SEARCH, EXIT]\n";
	std::cout << "ENJOY!";
	index = 0;
	index2 = 0;
	while (1)
	{
		std::cout << "Type command: ";
		if (!std::getline(std::cin, cmd))
			return ;
		if (cmd.compare("ADD") == 0)
		{
			if (FtAdd() == 1)
				return ;
		}
		else if (cmd.compare("SEARCH") == 0)
			FtShearch();
		else if (cmd.compare("EXIT") == 0)
			return ;
		else if (cmd.compare("\n") == 0)
			continue ;
		else
			std::cout << "Try again ! with somme thing i know\n";
	}
}

int main()
{
	PhoneBook ph;

	ph.Start();
}


