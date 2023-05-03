#include "phone_book.hpp"

void	phone_book::start(void)
{
	std::cout << "Hi! Welcome to the awsome Phone Book\n";
	std::cout << "You have 3 command to use, [ADD, SEARCH, EXIT]\n";
	std::cout << "Dont, make explain them pls ;)\n";
	std::cout << "ENJOY!";
}

void	phone_book::check_num(std::string str)
{
	int		v;
	
	v = 0;
	while (str[v])
	{
		if (!(str[v] >= 48 && str[v] <= 57))
		{
			std::cout << "Phone_number need only nembers.\n";
			std::cout << "Phone_number: ";
			std::cin >> str;
			check_num(str);
		}
 		v++;		
	}
}

void phone_book::ft_reaplace(contact *data)
{
	std::string str;

	std::cout << "First_name: ";
	std::cin >> str;
	data->replace(str, 'f');
	std::cout << "Last_name: ";
	std::cin >> str;
	data->replace(str, 'l');
	std::cout << "Nickname: ";
	std::cin >> str;
	data->replace(str, 'n');
	std::cout << "Phone_number: ";
	std::cin >> str;
	check_num(str);
	data->replace(str, 'p');
	std::cout << "Darkest_secret: ";
	std::cin >> str;
	data->replace(str, 'd');
}
