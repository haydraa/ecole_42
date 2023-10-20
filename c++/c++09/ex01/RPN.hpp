#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <exception>
#include <algorithm>

class RPN
{
	private:
		std::stack<int> Stack;
		std::string Input;
	
	public:
		RPN(void);
		RPN(std::string Input);
		RPN(const RPN &init);
		RPN &operator=(const RPN &init);
		~RPN();
		
		void	ToStack();
		void	Print();

		class ErorrCalcul : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("You Have A Problem Inside The Argment");
				}
		};

		class Erorr : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error Argument");
				}
		};

};

int	Math(char c, std::stack<int> &Stack);

#endif
