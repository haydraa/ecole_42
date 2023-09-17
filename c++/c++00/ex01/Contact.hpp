#ifndef CONTACT
#define CONTACT

class Contact
{
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
	public:
		int		index;
		int		index2;
		void	Put_fn(std::string str, int i);
		void	Put_ln(std::string str, int i);
		void	Put_nkm(std::string str, int i);
		void	Put_phn(std::string str, int i);
		void	Put_ds(std::string str, int i);	
};

#endif
