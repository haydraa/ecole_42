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
		int		FtReaplace();
		int		CheckNum(std::string str);
		void    Start();
		void	FtDisplay(std::string str);
		void	FtDisplayIndex(int index);
		void	FtAcces(std::string str, int i);
		int		FtAdd();
		void	FtShearch();
		void	FtShearch2();
		int		PutFn(std::string str, int i);
		int		PutLn(std::string str, int i);
		int		PutNkm(std::string str, int i);
		int		PutPhn(std::string str, int i);
		int		PutDs(std::string str, int i);	
};

#endif
