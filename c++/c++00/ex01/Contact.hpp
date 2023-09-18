#ifndef CONTACT
#define CONTACT

class Contact
{
	public:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;

		void	Put_fn(std::string str, int i);
		void	Put_ln(std::string str, int i);
		void	Put_nkm(std::string str, int i);
		void	Put_phn(std::string str, int i);
		void	Put_ds(std::string str, int i);	
};

#endif
