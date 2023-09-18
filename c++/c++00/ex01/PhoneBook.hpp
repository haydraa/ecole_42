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

		int		index;
		int		index2;
		void	FtReaplace(Contact *data);
		void    CheckNum(std::string str);
		void    Start();
		void	FtDisplay(std::string str);
		void	FtDisplayIndex(int index);
		void	FtAcces(std::string str, int i);
		void	FtAdd();
		void	FtShearch();
		void	FtShearch2();
};

#endif
