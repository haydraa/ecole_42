#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact data;
		void	FtReaplace(Contact *data);
		void    CheckNum(std::string str);
		void    Start(PhoneBook *ph);
		void	FtDisplay(std::string str);
};

#endif
