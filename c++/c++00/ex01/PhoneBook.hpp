#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <cstdlib>
#include <string>

class Contact
{
	private:
		std::string FirstName[8];
		std::string LastName[8];
		std::string Nickname[8];
		std::string PhoneNumber[8];
		std::string DarkestSecret[8];
	public:
		int index;
		int	index2;
		void Put_fn(std::string str, int i)
		{FirstName[i] = str;}
		void Put_ln(std::string str, int i)
		{LastName[i] = str;}
		void Put_nkm(std::string str, int i)
		{Nickname[i] = str;}
		void Put_phn(std::string str, int i)
		{PhoneNumber[i] = str;}
		void Put_ds(std::string str, int i)
		{DarkestSecret[i] = str;}
		void	FtDisplayIndex(int index);
		void	FtDisplay(std::string str);
		void	FtAcces(std::string str, int i)
		{
			if (str.compare("last_name"))
				FtDisplay(LastName[i]);
			else if(str.compare("first_name"))
				FtDisplay(FirstName[i]);
			else if(str.compare("nickname"))
				FtDisplay(Nickname[i]);
		}
		void	Replace(std::string new_data, char index)
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
};

class PhoneBook
{
	public:
		Contact *data;
		void	FtReaplace(Contact *data);
		void    CheckNum(std::string str);
		void    Start(void);
		void	FtDisplay(std::string str);
};


#endif
