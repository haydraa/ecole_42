#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;
	
	public:
		Contact();
		~Contact();
		std::string	GetData(char s);
		void	SetData(char s, std::string str);
		
};

#endif
