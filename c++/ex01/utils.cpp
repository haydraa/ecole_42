#include <phone_book.hpp>

void	phone_book::start(void)
{
	cout << "Hi! Welcome to the awsome Phone Book\n";
	cout << "You have 3 command to use, [ADD, SEARCH, EXIT]\n";
	cout << "Dont, make explain them pls ;)\n";
	cout << "ENJOY!";
}

void	phone_book::check_num(string str)
{
	int		v;
	
	v = 0;
	while (str[v])
	{
		if (!(str[v] >= 48 && str[v] <= 57))
		{
			cout << "Phone_number need only nembers.\n";
			cout << "Phone_number: ";
			cin >> str;
			check_num(str);
		}
 		v++;		
	}
}

void phone_book::ft_reaplace(contact *data)
{
	string str;

	cout << "First_name: ";
	cin >> str;
	data->replace(str, 'f');
	cout << "Last_name: ";
	cin >> str;
	data->replace(str, 'l');
	cout << "Nickname: ";
	cin >> str;
	data->replace(str, 'n');
	cout << "Phone_number: ";
	cin >> str;
	check_num(str);
	data->replace(str, 'p');
	cout << "Darkest_secret: ";
	cin >> str;
	data->replace(str, 'd');
}
