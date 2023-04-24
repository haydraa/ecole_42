#include "phone_book.hpp"

using namespace std;

void	ft_add(contact* data)
{
	string str;
	if (data->index < 8)
	{	
		cout << "First_name: ";
		cin >> str;
		data->put_fn(str, data->index);
		cout << "Last_name: ";
		cin >> str;
		data->put_ln(str, data->index);
		cout << "Nickname: ";
		cin >> str;
		data->put_nkm(str, data->index);
		cout << "Phone_number: ";
		cin >> str;
		check_num(str);
		data->put_phn(str, data->index);
		cout << "Darkest_secret: ";
		cin >> str;
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
		cout << str;
	else 
	{
		while (j < len)
		{
			if (j >= 10)
				cout << '.';
			else
				cout << str[j];
			j++;
		}
	}
	cout << " | ";
}

void	ft_shearch(contact *data)
{
	int i;

	i = 0;
	if (data->index == 0)
	{
		cout << "no contact yet !!\n";
		return;
	}
	while (i < data->index)
	{
		cout << i << " | ";
		data->ft_acces("last_name" ,i);
		data->ft_acces("first_name" ,i);
		data->ft_acces("nickname" ,i);
		cout << '\n';
		i++;
	}
	return;
}

int main()
{
	string cmd;
	contact	data;

	start();
	data.index = 0;
	while (1)
	{
		cout << "Type command: ";
		cin >> cmd;
		if (cmd.compare("ADD") == 0)
			ft_add(&data);
		else if (cmd.compare("SEARCH") == 0)
			ft_shearch(&data);
		else if (cmd.compare("EXIT") == 0)
			exit(0);
		else
			cout << "Try again ! with somme thing i know\n";
	}
}


