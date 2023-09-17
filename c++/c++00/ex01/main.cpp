#include "PhoneBook.hpp"

void	FtAdd(Contact* data, PhoneBook *ph)
{
	std::string str;
	if (data->index < 8)
	{	
		std::cout << "First_name: ";
		if (!std::getline(std::cin, str))
			exit(1);
		data->Put_fn(str, data->index);
		std::cout << "Last_name: ";
		if (!std::getline(std::cin, str))
			exit(1);
		data->Put_ln(str, data->index);
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, str))
			exit(1);
		data->Put_nkm(str, data->index);
		std::cout << "Phone_number: ";
		if (!std::getline(std::cin, str))
			exit(1);
		ph->CheckNum(str);
		data->Put_phn(str, data->index);	
		std::cout << "Darkest_secret: ";
		if (!std::getline(std::cin, str))
			exit(1);
		data->Put_ds(str, data->index);
		data->index++;
	}
	else
		ph->FtReaplace(data);
}

void	Contact::FtDisplayIndex(int index)
{
	std::cout << "First_name: ";
	std::cout << FirstName[index] << std::endl;
	std::cout << "Last_name: ";
	std::cout << LastName[index] << std::endl;
	std::cout << "Nickname: ";
	std::cout << Nickname[index] << std::endl;
	std::cout << "Phone_number: ";
	std::cout << PhoneNumber[index] << std::endl;
	std::cout << "Darkest_secret: ";
	std::cout << DarkestSecret[index] << std::endl;
	return ;
}

void	FtSearch2(Contact *data)
{
	int	index;
	std::string	str;
	int i;

	i = 0;
	std::cout << "Give an index: ";
	if(!std::getline(std::cin, str))
		exit(0);
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
	index = std::atoi(str.c_str());
	if (index > data->index - 1)
	{
		std::cout << "index empty!!!" << std::endl;
		FtSearch2(data);
	}
	else 
	{
		data->FtDisplayIndex(index);
		return;
	}	
}

void Contact::FtDisplay(std::string str)
{
	int len;

	len = str.length();
	if (len >= 10)
		std::cout << std:: setw(9) << std::right << str.substr(0,9) << ".";	
	else 
		std::cout << std::setw(10) << std::right << str;
	std::cout << " | ";
}

void	FtShearch(Contact *data)
{
	int i;
	std::string	str;

	i = 0;
	if (data->index == 0)
	{
		std::cout << "no contact yet !!\n";
		return;
	}
	while (i < data->index)
	{
		std::cout << i << " | ";
		data->FtAcces("last_name" ,i);
		data->FtAcces("first_name" ,i);
		data->FtAcces("nickname" ,i);
		std::cout << '\n';
		i++;
	}
	FtSearch2(data);
}

void    PhoneBook::Start(PhoneBook *ph)
{
	std::string cmd;
	
	std::cout << "Hi! Welcome to the awsome Phone Book\n";
	std::cout << "You have 3 command to use, [ADD, SEARCH, EXIT]\n";
	std::cout << "ENJOY!";
	ph->data.index = 0;
	ph->data.index2 = 0;
	while (1)
	{
		std::cout << "Type command: ";
		if (!std::getline(std::cin, cmd))
			exit(1);
		if (cmd.compare("ADD") == 0)
			FtAdd(&ph->data, ph);
		else if (cmd.compare("SEARCH") == 0)
			FtShearch(&ph->data);
		else if (cmd.compare("EXIT") == 0)
			exit(0);
		else if (cmd.compare("\n") == 0)
			continue ;
		else
			std::cout << "Try again ! with somme thing i know\n";
	}
}

int main()
{
	PhoneBook ph;

	ph.Start(&ph);
}


