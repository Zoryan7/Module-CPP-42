/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:59:35 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/21 14:07:27 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"


const char *BitcoinExchange::invalid_file_format::what() const throw()
{
	return ("Error: invalid file format.");
}

const char *BitcoinExchange::file_not_exist::what() const throw()
{
	return ("Error: source file does not exist.");
}

BitcoinExchange::BitcoinExchange()
{
	std::string date;
	std::string line;
	float price;
	std::ifstream in("data.csv");
	
	if(!in)
		throw BitcoinExchange::file_not_exist();
	std::getline(in, line);
	if (line != "date,exchange_rate")
		throw BitcoinExchange::invalid_file_format();
	while(std::getline(in, line))
	{
		date = line.substr(0, line.find(','));
		price = std::strtod(line.c_str() + line.find(',') + 1, NULL);
		_data[date] = price;
	}
	in.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		_data = src._data;
	}
	return *this;
}

bool BitcoinExchange::ft_valid_day(const int &year, const int &month, const int &day) const
{
	int leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	
	if (month == 2)
		return (day > 28 + leap_year);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day > 30);
	else
		return (day > 31);
}

bool BitcoinExchange::ft_verif_date_validity(const std::string &date) const
{
	int year = std::strtol(date.c_str(), NULL,  10);
	int month = std::strtol(date.c_str() + 5, NULL,  10);
	int day  = std::strtol(date.c_str() + 8, NULL, 10);
	
	if (year < 1 || month < 1 || month > 12 || day < 1 || ft_valid_day(year, month, day)) 
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return (true);
	}
    return (false); 
}
        
bool BitcoinExchange::ft_verif_nb_validity(float &nb, const std::string &nb_temp) const
{
	char *end;
    
	nb = std::strtod(nb_temp.c_str(), &end);
    if(end == nb_temp.c_str() || *end != '\0')
    {
    	std::cout << "Error: bad input => " << nb_temp << std::endl;
    	return (true);
    }
	if(nb < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (true);
	}
	if (nb > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (true);
	}
    return (false);
}

bool BitcoinExchange::ft_verif_date(const std::string &date) const
{
    int i = 0;
    
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (true);
    }
    while (i < 10)
    {
        if (i == 4 || i == 7)
            i++;
        if (!isdigit(date[i]))
        {
            std::cout << "Error: bad input => " << date << std::endl;
			return (true);
        }
        i++;
    }
	if (this->ft_verif_date_validity(date))
		return (true);
    return (false); 
}

void BitcoinExchange::ft_print_value(const std::string &t_date, const std::string &temp_nb) const
{
	std::string date = t_date;
	float nb;
	
	if(ft_verif_date(date) || ft_verif_nb_validity(nb , temp_nb))
		return ;
	std::map<std::string, float>::const_iterator it = _data.upper_bound(date);
	if(it == _data.begin())
	{
		std::cout << "Error : too old date => " << date << std::endl;
		return ;
	}
	it--;
	std::cout << date << " => " << nb << " = " << nb * it->second << std::endl;
}