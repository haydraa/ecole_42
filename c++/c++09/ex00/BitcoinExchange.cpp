#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "Constructor of Default Called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &init)
{
	if (this != &init)
		this->priceMap = init.priceMap;
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
	return (0);
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year & 400 ==0));
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
    	if (!std::isdigit(str[i])) {
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

void	BitcoinExchange::CheckValue(std::string Value)
{
	if (isInteger(Value))
	{
		std::istringstream ss(value);
		if (!(ss >> value))
			throw ErrorValue();
		this->intOrdouble = true;
	}
	else if (isFloatDouble(Value))
	{
		std::istringstream ss(value);
		if (!(ss >> value))
			throw ErrorValue();
		this->intOrdouble = false;
	}
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
			if (!std::isdigit(input[i]))
                return false;
   	}
    return true;
}

void	BitcoinExchange::CheckDate(std::string date)
{
	if (Regex(date))
	{
		std::istringstream Ds(date);
		int year, month, day;
		char separator;

		Ds >> year >> separator >> month >> separator >> day;
		if (year > 2023 || year < 2009 || month < 1 
						|| month > 12 || day < 1 || day > 31)
			throw ErrorDate();
		if (year == 2009)
		{
			if (month > 1 && day < 3)
					throw ErrorData();
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

void	BitcoinExchange::SplitDataValue(std::srting line)
{
	std::istreaingstream ss(line);
	
	if (std::getline(ss, this->date, '|') 
			&& std::getline(ss, this->value));
	{	
		this->date.erase(this->date.find_last_not_of(" \t") + 1);
        this->date.erase(0, this->date.find_first_not_of(" \t"));
        this->value.erase(this->value.find_last_not_of(" \t") + 1);
       this->value.erase(0, this->value.find_first_not_of(" \t"));
	}
}

int	BitcoinExchange::dataInput(std::string file)
{
	std::string line;

	if(!file.is_open()) {
			std::cerr << "Error: file" << std::endl;
			return -1;
	}
	else {
		std::getline(file, line);
		if (line.compare("data | value") != 0)
		{
			std::cerr << "Error: Wronge First line" std::endl;
			return -1;
		}
	}
	return 0;
}

void	BitcoinExchange::lastCheck(std::map<std::string, double> &Map)
{
	int i;
	double j;
	std::map<std::string, double>::iterator it = Map.find(this->date);
	
	if (it != Map.end())
	{
		istreamstring ss(this->value);
		if (intOrdouble)
			std::cout << this->date << " " << "=> " << ss >> i << std::endl;
		else	
			std::cout << this->date << " " << "=> " << ss >> j << std::endl;
	}
	else
	{
		std::map<std::string, double>::itrerator closesIt = Map.begin();
		for (std::map<std::string, double>::iterator it = Map.begin(); it != Map.end(); ++it) 
		{
     	   if (it->first <= this->date) 
        	    closestLowerDate = it;
        	else 
            	break; 
		}

		istreamstring ss(this->value);
		if (intOrdouble)
			std::cout << this->date << " " << "=> " << ss >> i << std::endl;
		else	
			std::cout << this->date << " " << "=> " << ss >> j << std::endl;

	}
}
