#ifndef PHONE_BOOK
#define PHONE_BOOK

#include <iostream>
#include <cstdlib>

class contact
{
	private:
		std::string first_name[8];
		std::string last_name[8];
		std::string nickname[8];
		std::string phone_number[8];
		std::string darkest_secret[8];
	public:
		int index;
		void put_fn(std::string str, int i)
		{first_name[i] = str;}
		void put_ln(std::string str, int i)
		{last_name[i] = str;}
		void put_nkm(std::string str, int i)
		{nickname[i] = str;}
		void put_phn(std::string str, int i)
		{phone_number[i] = str;}
		void put_ds(std::string str, int i)
		{darkest_secret[i] = str;}
		//dispalay
		void	ft_display(std::string str);
		void	ft_acces(std::string str, int i)
		{
			if (str.compare("last_name"))
				ft_display(last_name[i]);
			else if(str.compare("first_name"))
				ft_display(first_name[i]);
			else if(str.compare("nickname"))
				ft_display(nickname[i]);
		}
		void	replace(std::string new_data, char index)
		{
			if (index == 'f')
				first_name[7] = new_data;
			else if (index == 'l')
				last_name[7] = new_data;
			else if (index == 'n')
				nickname[7] = new_data;
			else if (index == 'd')
				darkest_secret[7] = new_data;
			else if (index == 'p')
				phone_number[7] = new_data;
		}
};

class phone_book
{
	public:
		contact *data;
		void	ft_reaplace(contact *data);
		void    check_num(std::string str);
		void    start(void);
		void	ft_display(std::string str);
};


#endif