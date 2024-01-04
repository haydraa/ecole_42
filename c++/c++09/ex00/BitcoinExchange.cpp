#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "Constructor of Default Called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &init)
{
	if (this != &init)
	{
		this->priceMap = init.priceMap;
		this->date = init.date;
		this->value = init.value;
		this->intOrDouble = init.intOrDouble;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &init)
{
	if (this != &init)
		*this = init;
	return ;
}


BitcoinExchange::~BitcoinExchange(void)
{}


int	BitcoinExchange::GetCsvData(void)
{
	std::ifstream file("data.csv");
	std::string  line;

	if (!file.is_open()) {
		std::cerr << "Error: Data_Base File" << std::endl;
		return (-1);
	}
	else {
		std::getline(file, line);
		while (std::getline(file, line)) {
			std::istringstream ss(line);
			std::string date;
			double rate;
			if (std::getline(ss, date, ',') && ss >> rate)
				priceMap[date] = rate;
			else {
				std::cerr << "Error: Getline had a problem" << std::endl;
				return (-1);
			}
		}
	}
	file.close();
	if (priceMap.size() == 0)
	{
		std::cout << "Error: data base empty" << std::endl;
		return (-1);
	}
	return (0);
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 ==0));
}

bool	isInteger(std::string str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i)
   	{
        if (i == 0 && (str[i] == '-' || str[i] == '+')) {
            continue;
    	}
		else if (!std::isdigit(str[i])) {
        	return false;
    	}
	}
	return true;
}

bool	isFloatDouble(std::string str)
{
    bool dotFound = false;
	
	if (str.empty()) {
        return false;
    }
	for (size_t i = 0; i < str.size(); ++i)
   	{
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;
        if (str[i] == '.')
	   	{
            if (dotFound)
                return false;
            dotFound = true;
        }
		else if (!std::isdigit(str[i]) && str[i] != '.') 
            return false;
    }
    return true;
}

void	BitcoinExchange::CheckValue()
{
	int V;
	double VD;

	if (isInteger(this->value))
	{
		std::istringstream ss(this->value);
		if (!(ss >> V))
			throw ErrorValue();
		if (V < 0)
			throw ErrorValue();
		this->intOrDouble = true;
	}
	else if (isFloatDouble(this->value))
	{
		std::istringstream ss(this->value);
		if (!(ss >> VD))
			throw ErrorValue();
		if (VD < 0)
			throw ErrorValue();
		this->intOrDouble = false;
	}
	else
		throw ErrorValue();
}

bool Regex(std::string Date)
{
	 if (Date.length() != 10)
        return false;
    for (int i = 0; i < 10; ++i)
   	{
        if (i == 4 || i == 7)
	   	{
            if (Date[i] != '-')
                return false;
        }
	   	else 
			if (!std::isdigit(Date[i]))
                return false;
   	}
    return true;
}

void	BitcoinExchange::CheckDate(void)
{
	if (Regex(this->date))
	{
		std::istringstream Ds(this->date);
		int year, month, day;
		char separator;

		Ds >> year >> separator >> month >> separator >> day;
		if (year > 2023 || year < 2009 || month < 1 
						|| month > 12 || day < 1 || day > 31)
			throw ErrorDate();
		if (year == 2009)
		{
			if (month > 1 && day < 3)
					throw ErrorDate();
		}

		if (month == 2)
		{
			if (day > 29)
				throw ErrorDate();
			else if (!isLeapYear(year) && day == 29)
				throw ErrorDate();
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			throw ErrorDate();
	}
	else
		throw ErrorDate();
}

void	BitcoinExchange::SplitDateValue(std::string line)
{
	std::istringstream ss(line);

	if (line.find('|') == std::string::npos || line.size() < 12)
		throw Error();
	if (std::getline(ss, this->date, '|') 
			&& std::getline(ss, this->value))
	{	
		this->date.erase(this->date.find_last_not_of(" \t") + 1);
        this->date.erase(0, this->date.find_first_not_of(" \t"));
        this->value.erase(this->value.find_last_not_of(" \t") + 1);
       this->value.erase(0, this->value.find_first_not_of(" \t"));
	}
}

void	BitcoinExchange::lastCheck(void)
{
	int i;
	double j;
	double value;

	std::map<std::string, double>::iterator it = this->priceMap.find(this->date);

	if (it != this->priceMap.end())
	{
		double value = this->priceMap.at(this->date);
		std::istringstream ss(this->value);
		if (intOrDouble)
		{
			ss >> i;
			i = i * value;
			std::cout << this->date << " " << "=> " 
		<< i << std::endl;
		}
		else	
		{
			ss >> j;
			j = j * value;
			std::cout << this->date << " " << "=> " 
		<< j << std::endl;
		}
	}
	else
	{
		std::map<std::string, double>::iterator closesIt = this->priceMap.begin();
		for (std::map<std::string, double>::iterator it = this->priceMap.begin(); it != this->priceMap.end(); ++it) 
		{
     	   if (it->first <= this->date) 
        	    closesIt = it;
        	else 
            	break; 
		}
		value = closesIt->second;
		std::stringstream ss(this->value);
		if (intOrDouble)
		{
			ss >> i;
			i = i * value;
			std::cout << closesIt->first << " " << "=> " 
				<< i << std::endl;
		}
		else	
		{
			ss >> j;
			j = j * value;
			std::cout << closesIt->first << " " << "=> " 
			<< j << std::endl;
		}
	}
}
