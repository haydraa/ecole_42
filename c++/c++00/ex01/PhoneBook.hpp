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
		Contact data[8];
		void	FtReaplace(Contact *data);
		void    CheckNum(std::string str);
		void    Start(PhoneBook *ph);
		void	FtDisplay(std::string str);
		void	FtDisplayIndex(int index);
		void	FtDisplay(std::string str);
		void	FtAcces(std::string str, int i);
};

#endif
