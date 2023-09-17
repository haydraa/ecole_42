#ifndef CONTACT
#define CONTACT

class Contact
{
	private:
		std::string FirstName[8];
		std::string LastName[8];
		std::string Nickname[8];
		std::string PhoneNumber[8];
		std::string DarkestSecret[8];
	public:
		int		index;
		int		index2;
		void	Put_fn(std::string str, int i);
		void	Put_ln(std::string str, int i);
		void	Put_nkm(std::string str, int i);
		void	Put_phn(std::string str, int i);
		void	Put_ds(std::string str, int i);
		void	FtDisplayIndex(int index);
		void	FtDisplay(std::string str);
		void	FtAcces(std::string str, int i);
		void	Replace(std::string new_data, char index);
};

#endif
