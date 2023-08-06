#include "PhoneBook.hpp"

void	PhoneBook::Start(void)
{
	std::cout << "Hi! Welcome to the awsome Phone Book\n";
	std::cout << "You have 3 command to use, [ADD, SEARCH, EXIT]\n";
	std::cout << "Dont, make explain them pls ;)\n";
	std::cout << "ENJOY!";
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
	std::getline(std::cin, str);
	data->Replace(str, 'f');
	std::cout << "Last_name: ";
	std::getline(std::cin, str);
	data->Replace(str, 'l');
	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	data->Replace(str, 'n');
	std::cout << "Phone_number: ";
	std::getline(std::cin, str);
	CheckNum(str);
	data->Replace(str, 'p');
	std::cout << "Darkest_secret: ";
	std::getline(std::cin, str);
	data->Replace(str, 'd');
	data->index2++;
	if (data->index2 > 7)
		data->index2 = 0;
}
