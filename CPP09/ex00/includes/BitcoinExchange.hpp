/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:59:35 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/21 14:07:39 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
        std::map<std::string , float> _data;
        bool ft_verif_date_validity(const std::string &date) const;
		bool ft_verif_date(const std::string &date) const;
        bool ft_verif_nb_validity( float &nb, const std::string &nb_temp) const;
        bool ft_valid_day(const int &year, const int &month, const int &day) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &src);
        class file_not_exist : public std::exception
        {
            public:
                        const char * what() const throw();
       
        };
        class invalid_file_format : public std::exception
        {
            public:
                        const char * what() const throw();
        };
        void ft_print_value(const std::string &t_date, const std::string &temp_nb) const;
};

#endif
