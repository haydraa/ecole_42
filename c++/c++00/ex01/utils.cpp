#include "PhoneBook.hpp"

void	Contact::Put_fn(std::string str, int i)
{
	FirstName[i] = str;
}
		 
void	 Contact::Put_ln(std::string str, int i)
{		
	LastName[i] = str;
}
		
void	 Contact::Put_nkm(std::string str, int i)
{
	Nickname[i] = str;
}
void	 Contact::Put_phn(std::string str, int i)
{
	 PhoneNumber[i] = str;
}  

void	 Contact::Put_ds(std::string str, int i)
{
	DarkestSecret[i] = str;
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

void	Contact::FtAcces(std::string str, int i)
{
	if (str.compare("last_name"))
		FtDisplay(LastName[i]);
	else if(str.compare("first_name"))
		FtDisplay(FirstName[i]);
	else if(str.compare("nickname"))
		FtDisplay(Nickname[i]);
}

void    Contact::Replace(std::string new_data, char index)	
{
	if (index == 'f')
		FirstName[index2] = new_data;
 	else if (index == 'l')
	 	LastName[index2] = new_data;
	else if (index == 'n')
		 Nickname[index2] = new_data;
	else if (index == 'd')
		DarkestSecret[index2] = new_data;
	else if (index == 'p')
		 PhoneNumber[index2] = new_data;

}
