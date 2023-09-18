#include "PhoneBook.hpp"

void	Contact::Put_fn(std::string str, int i)
{
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "First_name: ";
			if (!std::getline(std::cin, str))
				break;
		}
	}
	data[i].FirstName = str;
}
		 
void	 Contact::Put_ln(std::string str, int i)
{		
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "Last_name: ";
			if (!std::getlx = 0;
      |           x = 0;
      |           ine(std::cin, str))
				break;
		}
	}
	data[i].LastName = str;
}
		
void	 Contact::Put_nkm(std::string str, int i)
{
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "Nickname: ";
			if (!std::getline(std::cin, str))
				break;
		}
	}
	data[i].Nickname = str;
}

void	 Contact::Put_phn(std::string str, int i)
{
	data[i].PhoneNumber = str;
}  

void	 Contact::Put_ds(std::string str, int i)
{
	if (str.length() == 0)
	{
		while (str.length() == 0)
		{	
			std::cout << "this block can't be empty...\n";
			std::cout << "Darkest_secret: ";
			if (!std::getline(std::cin, str))
				break;
		}
	}
	data[i].DarkestSecret = str;
}  


void	PhoneBook::CheckNum(std::string str)
{
	int		v;
	
	v = 0;
	while (str[v])
	{
		if (!(str[v] >= 48 && str[v] <= 57))
		{
			std::cout << "Phone_number need only numbers.\n";
			std::cout << "Phone_number: ";
			std::getline(std::cin, str);
			CheckNum(str);
		}
 		v++;		
	}
}

void PhoneBook::FtReaplace(Contact *data)
{
	std::string str;

	std::cout << "First_name: ";
	if (!std::getline(std::cin, str))
		exit(1);
	data->Put_fn(str, data->index2);
	std::cout << "Last_name: ";
	if (!std::getline(std::cin, str))
		exit(1);
	data->Put_ln(str, data->index2);
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, str))
		exit(1);
	data->Put_nkm(str, data->index2);
	std::cout << "Phone_number: ";
	if (!std::getline(std::cin, str))
		exit(1);
	CheckNum(str);
	data->Put_phn(str, data->index2);	
	std::cout << "Darkest_secret: ";
	if (!std::getline(std::cin, str))
		exit(1);
	data->Put_ds(str, data->index2);
	data->index2++;
	if (data->index2 > 7)
		data->index2 = 0;
}

void	PhoneBook::FtAcces(std::string str, int i)
{
	if (str.compare("last_name"))
		FtDisplay(data[i].LastName);
	else if(str.compare("first_name"))
		FtDisplay(data[i].FirstName[i]);
	else if(str.compare("nickname"))
		FtDisplay(data[i].Nickname[i]);
}

