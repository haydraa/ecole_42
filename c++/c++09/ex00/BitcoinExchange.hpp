#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
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
		int		dataInpute(std::string file);
		void	CheckDate(std::string Date);
		void	CheckValue(std::string Value);
		void	lastCheck(std::map<std::string, double> &Map);
		class ErrorDate: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Error: Incorrect Form Of Year");
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
