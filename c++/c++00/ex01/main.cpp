#include "PhoneBook.hpp"

void	FtAdd(Contact* data, PhoneBook *ph)
{
	std::string str;
	if (data->index < 8)
	{	
		std::cout << "First_name: ";
		std::getline(std::cin, str);
		data->Put_fn(str, data->index);
		std::cout << "Last_name: ";
		std::getline(std::cin, str);
		data->Put_ln(str, data->index);
		std::cout << "Nickname: ";
		std::getline(std::cin, str);
		data->Put_nkm(str, data->index);
		std::cout << "Phone_number: ";
		std::getline(std::cin, str);
		ph->CheckNum(str);
		data->Put_phn(str, data->index);	
		std::cout << "Darkest_secret: ";
		std::getline(std::cin, str);
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

	std::cout << "Give an index: ";
	std::getline(std::cin, str);
	if (!(str[0] >= 48 && str[0] <= 56))
	{
		std::cout << "your index is wrong" << std::endl;
		FtSearch2(data);
	}
	else
	{
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
		
}

void Contact::FtDisplay(std::string str)
{
	int j;
	int len;

	len = str.size();
	j = 0;
	if (len < 10)
		std::cout << str;
	else 
	{
		while (j < len)
		{
			if (j >= 10)
				std::cout << '.';
			else
				std::cout << str[j];
			j++;
		}
	}
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



int main()
{
	std::string cmd;
	Contact	data;
	PhoneBook ph;

	ph.Start();
	data.index = 0;
	data.index2 = 0;
	while (1)
	{
		std::cout << "Type command: ";
		if (!std::getline(std::cin, cmd))
			exit(1);
		if (cmd.compare("ADD") == 0)
			FtAdd(&data, &ph);
		else if (cmd.compare("SEARCH") == 0)
			FtShearch(&data);
		else if (cmd.compare("EXIT") == 0)
			exit(0);
		else if (cmd.compare("\n") == 0)
			continue ;
		else
			std::cout << "Try again ! with somme thing i know\n";
	}
}


