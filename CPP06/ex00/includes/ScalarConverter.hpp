/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:33:07 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 12:33:36 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <cerrno>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		static int ft_parsing(const std::string &src);
		static void ft_convert_char(const std::string &src);
		static void ft_convert_int(const std::string &src);
		static void ft_convert_float(const std::string &src);
		static void ft_convert_double(const std::string &src);
		static void ft_convert_pseudo(const std::string &src);
		static void ft_convert_error(const std::string &src);
		static bool ft_is_int(const std::string &src);
		static std::string ft_format_d(double value);
		static std::string ft_format_f(float value);
		static void ft_print_char(double value);
		static void ft_print_int(double value);
	public:
		static void convert(const std::string &src);
};

#endif
