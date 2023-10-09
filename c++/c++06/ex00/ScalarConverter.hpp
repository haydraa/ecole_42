#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostram>
#include <cstring>

class ScalarConverter
{
	private:
		int	SelectedType;
		float Float;
		double Double;
		int	Int;
		char Char;
		
	public:
		ScalarConverter(void);
		ScalarConverter(std::string str);
		ScalarConverter(const ScalarConverter &init);
		~ScalarConverter(void);
		ScalcarConverter &operator=(const ScalarConverter &niti);
		void	getFLoat(void) const;
		void	getDouble(void) const;
		void	getInt(void) const;
		void	getChar(void) const;
		
		class EmptyInput: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Please enter an input to be analysed by the converter";
				}
		};
		class CannotAnalyse: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The input is not a valid char, int, float or double";
				}
		};

		
}


#endif
