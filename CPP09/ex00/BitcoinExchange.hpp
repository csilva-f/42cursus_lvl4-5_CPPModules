#pragma once

# include <exception>
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_rates;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange	&operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	getMultipliedRates(std::string filename);

class ErrorDataFileException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class ErrorInputFileException : public std::exception
{
	public:
		virtual const char* what() const throw();
};
};
