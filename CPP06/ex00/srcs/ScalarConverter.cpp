/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:33:07 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 12:44:35 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src)
	{
	}
	return *this;
}

std::string ScalarConverter::ft_format_d(double value)
{
	std::ostringstream dest;

	if (value == std::floor(value))
		dest << std::fixed << std::setprecision(1) << value;
	else
		dest << std::setprecision(std::numeric_limits<double>::digits10) << value;
	return (dest.str());
}

std::string ScalarConverter::ft_format_f(float value)
{
	std::ostringstream dest;

	if (value == std::floor(value))
		dest << std::fixed << std::setprecision(1) << value;
	else
		dest << std::setprecision(std::numeric_limits<float>::digits10) << value;
	return (dest.str());
}

void ScalarConverter::ft_print_char(double value)
{
	double truncated;

	if (value < 0)
		truncated = std::ceil(value);
	else
		truncated = std::floor(value);
	if (truncated < std::numeric_limits<char>::min()
		|| truncated > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c_dest = static_cast<char>(truncated);
	if (std::isprint(static_cast<unsigned char>(c_dest)))
		std::cout << "char: '" << c_dest << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::ft_convert_char(const std::string &src)
{
	std::cout << "char: '" << src[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(src[0]) << std::endl;
	std::cout << "float: " << ScalarConverter::ft_format_f(static_cast<float>(src[0]))
		<< "f" << std::endl;
	std::cout << "double: " << ScalarConverter::ft_format_d(static_cast<double>(src[0])) << std::endl;
}

void ScalarConverter::ft_convert_int(const std::string &src)
{
	int i_dest = static_cast<int>(std::strtol(src.c_str(), NULL, 10));

	if (i_dest < std::numeric_limits<char>::min()
		|| i_dest > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i_dest))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i_dest) << "'" << std::endl;

	std::cout << "int: " << i_dest << std::endl;
	std::cout << "float: " << ScalarConverter::ft_format_f(static_cast<float>(i_dest))
		<< "f" << std::endl;
	std::cout << "double: " << ScalarConverter::ft_format_d(static_cast<double>(i_dest)) << std::endl;
}

void ScalarConverter::ft_convert_float(const std::string &src)
{
	errno = 0;
	float f_dest = std::strtod(src.c_str(), NULL);
	
	if (f_dest < std::numeric_limits<char>::min()
		|| f_dest > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(f_dest))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f_dest) << "'" << std::endl;
	if (f_dest < std::numeric_limits<int>::min()
		|| f_dest > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f_dest) << std::endl;
	std::cout << "float: " << ScalarConverter::ft_format_f(f_dest)
		<< "f" << std::endl;
	std::cout << "double: " << ScalarConverter::ft_format_d(static_cast<double>(f_dest)) << std::endl;
}

void ScalarConverter::ft_convert_double(const std::string &src)
{
	errno = 0;
	double d_dest = std::strtod(src.c_str(), NULL);
	if (errno == ERANGE)
	{
		ScalarConverter::ft_convert_error(src);
		return ;
	}
	if (d_dest < std::numeric_limits<char>::min()
		|| d_dest > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(d_dest))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d_dest) << "'" << std::endl;
	if (d_dest < std::numeric_limits<int>::min()
		|| d_dest > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d_dest) << std::endl;
	if (d_dest < -std::numeric_limits<float>::max()
		|| d_dest > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		float f_dest = static_cast<float>(d_dest);
		std::cout << "float: " << ScalarConverter::ft_format_f(f_dest)
			<< "f" << std::endl;
	}
	std::cout << "double: " << ScalarConverter::ft_format_d(d_dest) << std::endl;
}

void ScalarConverter::ft_convert_pseudo(const std::string &src)
{
	float f_dest;
	double d_dest;
	
	if (src == "nan" || src == "nanf")
	{
		f_dest = std::numeric_limits<float>::quiet_NaN();
		d_dest = std::numeric_limits<double>::quiet_NaN();
	}
	else if (src == "+inf" || src == "+inff")
	{
		f_dest = std::numeric_limits<float>::infinity();
		d_dest = std::numeric_limits<double>::infinity();
	}
	else if (src == "-inf" || src == "-inff")
	{
		f_dest = -std::numeric_limits<float>::infinity();
		d_dest = -std::numeric_limits<double>::infinity();
	}
	else
	{
		std::cout << "Invalid pseudo-literal" << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f_dest << "f" << std::endl;
	std::cout << "double: " << d_dest << std::endl;
}

void ScalarConverter::ft_convert_error(const std::string &src)
{
	(void)src;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool ScalarConverter::ft_is_int(const std::string &src)
{
	char *end;

	errno = 0;
	long temp = std::strtol(src.c_str(), &end, 10);
	if (end == src.c_str() || end[0] != '\0' || errno == ERANGE)
		return (false);
	if (temp < std::numeric_limits<int>::min()
		|| temp > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

int ScalarConverter::ft_parsing(const std::string &src)
{
	char *end;
	double d_dest;

	if (src.empty())
		return (5);
	if (src == "nan" || src == "nanf" || src == "+inf" || src == "-inf" || src == "+inff" || src == "-inff")
		return (0);
	if (src.length() == 1
		&& !std::isdigit(static_cast<unsigned char>(src[0])))
		return (1);
	if (ScalarConverter::ft_is_int(src))
		return (2);
	errno = 0;
	d_dest = std::strtod(src.c_str(), &end);
	if (end == src.c_str() || errno == ERANGE || d_dest != d_dest
		|| d_dest < -std::numeric_limits<double>::max()
		|| d_dest > std::numeric_limits<double>::max())
		return (5);
	if (end[0] == 'f' && end[1] == '\0')
	{
		if (d_dest < -std::numeric_limits<float>::max()
			|| d_dest > std::numeric_limits<float>::max())
			return (5);
		return (3);
	}
	else if (end[0] == '\0')
		return (4);
	else
	 	return (5);
}

void ScalarConverter::convert(const std::string &src)
{	
	int i;
    void (*ft_convert[6])(const std::string &src) = {&ScalarConverter::ft_convert_pseudo, &ScalarConverter::ft_convert_char, &ScalarConverter::ft_convert_int, &ScalarConverter::ft_convert_float, &ScalarConverter::ft_convert_double, &ScalarConverter::ft_convert_error};

	i = ScalarConverter::ft_parsing(src);
    (*ft_convert[i])(src);
	
}
