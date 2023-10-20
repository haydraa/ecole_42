#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> priceMap;
	   	std::string date;
		std::string value;
		bool intOrDouble ;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &init);
		BitcoinExchange &operator=(const BitcoinExchange &init);
		~BitcoinExchange(void);

		int		GetCsvData(void);
		void	SplitDateValue(std::string value);
		void	CheckDate(void);
		void	CheckValue(void);
		void	lastCheck(void);
	
		class ErrorDate: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: Incorrect Form Of Year");
				}
		};
		
		class Error: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: The string is Wrong");
				}
		};
		class ErrorValue: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: Incorrect Value");
				}
		};

};

#endif
