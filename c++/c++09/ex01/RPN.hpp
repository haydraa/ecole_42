#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

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

		class Error: public std::execption
		{
			const char* what() : const throw()
			{
				return ("Error Argument");
			}
		};
};

#endif
