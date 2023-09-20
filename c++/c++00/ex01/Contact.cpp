#include "Contact.hpp"

Contact::Contact()
{
	FirstName = "";
	LastName = "";
	Nickname = "";
	PhoneNumber = "";
	DarkestSecret = "";
}

Contact::~Contact()
{

}

std::string	Contact::GetData(char s)
{
	if (s == 'F')
		return (FirstName);
	else if (s == 'L')
		return (LastName);
	else if (s == 'N')
		return (Nickname);
	else if (s == 'P')
		return (PhoneNumber);
	return (DarkestSecret);
}

void	Contact::SetData(char s, std::string str)
{	
	if (s == 'F')
		FirstName = str;
	else if (s == 'L')
		LastName = str;
	else if (s == 'N')
		Nickname = str;
	else if (s == 'P')
		PhoneNumber = str;
	else if (s == 'D')
		DarkestSecret = str;
}
