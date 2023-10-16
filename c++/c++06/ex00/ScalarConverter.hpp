#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <stdexcept>
#include <cmath>

class ScalarConverter
{
	private:
		int	ScalarType;
		float Float;
		double Double;
		int	Int;
		char Char;
		
	public:
		ScalarConverter(void);
		ScalarConverter(char *input);
		ScalarConverter(const ScalarConverter &init);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &init);
		void	getFLoat(void) const;
		void	getDouble(void) const;
		void	getInt(void) const;
		void	getChar(void) const;
		void	Analyse(char *input);
		void	printType(void);
		void	SetVaribale(char *input);
		bool	getType(char *input);
		int		HandelNum(char *input);
		int		HandelTheFunCases(char *input);
		void	printChar(void);
		bool	canConvertToInt(double Number);
		bool	canConvertToFloat(double Nunber);
		bool	canConvertToChar(double Number);
		void	printInt(void);
		void	printFloat(void);
		void	printDouble(void);
		bool	ft_isdigits(char c);
		const char	*printDotZero(double Number);

		
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
};


#endif
