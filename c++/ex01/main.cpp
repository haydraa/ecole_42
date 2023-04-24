#include "phone_book.hpp"

using namespace std;

void	ft_add(contact* data)
{
	std::string str;
	if (data->index < 8)
	{	
		std::cout << "First_name: ";
		std::cin >> str;
		data->put_fn(str, data->index);
		std::cout << "Last_name: ";
		std::cin >> str;
		data->put_ln(str, data->index);
		std::cout << "Nickname: ";
		std::cin >> str;
		data->put_nkm(str, data->index);
		std::cout << "Phone_number: ";
		std::cin >> str;
		check_num(str);
		data->put_phn(str, data->index);
		std::cout << "Darkest_secret: ";
		std::cin >> str;
		data->put_ds(str, data->index);
		data->index++;
	}
	else
		ft_reaplace(data);
}


void phone_book::ft_display(string str)
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

void	ft_shearch(contact *data)
{
	int i;

	i = 0;
	if (data->index == 0)
	{
		std::cout << "no contact yet !!\n";
		return;
	}
	while (i < data->index)
	{
		std::cout << i << " | ";
		data->ft_acces("last_name" ,i);
		data->ft_acces("first_name" ,i);
		data->ft_acces("nickname" ,i);
		std::cout << '\n';
		i++;
	}
	return;
}

int main()
{
	std::string cmd;
	contact	data;

	start();
	data.index = 0;
	while (1)
	{
		std::cout << "Type command: ";
		cin >> cmd;
		if (cmd.compare("ADD") == 0)
			ft_add(&data);
		else if (cmd.compare("SEARCH") == 0)
			ft_shearch(&data);
		else if (cmd.compare("EXIT") == 0)
			exit(0);
		else
			std::cout << "Try again ! with somme thing i know\n";
	}
}


