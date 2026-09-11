/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:49:17 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/21 10:41:58 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

bool ft_substr_space(std::string &dest)
{
    std::string space = " ";
    size_t pos;

    for(int i = 9; i < 14; i++ )
        space += i;
    pos = dest.find_first_not_of(space);
    if (pos == std::string::npos)
    {
        std::cout << "Error: bad input => " << dest << std::endl;
        return (true);
    }
    dest = dest.substr(pos);
    pos = dest.find_last_not_of(space);
    dest = dest.substr(0, pos + 1);
    return (false);
}

bool ft_first_line(std::ifstream &fd, std::string &line)
{
    if(!std::getline(fd, line))
    {
        std::cerr << "Error: input file is empty." << std::endl;
        return (true);
    }
    if (line == "date | value")
    {
		if (!std::getline(fd, line))
        {
            std::cerr << "Error: input file is empty." << std::endl;
            return (true);
        }
    }
    return (false);
}

void ft_calcul_line(const std::string &line,const BitcoinExchange &Data)
{
    std::string date;
    std::string temp_nb;
    size_t pos;
    
    pos = line.find('|');
    if(line.empty() || pos == std::string::npos )
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;   
    }
    date = line.substr(0, pos);
    temp_nb = line.substr(pos + 1);
    if(ft_substr_space(date) || ft_substr_space(temp_nb))
        return	;
    Data.ft_print_value(date, temp_nb);
}

int ft_parse(std::ifstream &fd)
{
    std::string line;
    BitcoinExchange *Data = NULL;
    
    try
    {
        Data = new BitcoinExchange();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    if(ft_first_line(fd ,line))
        return (delete Data, 1);
    while(1)
    {
        ft_calcul_line(line, *Data);
        if (!std::getline(fd,line))
            break;
    }
    return (delete Data, 0);
}

int main(int ac, char **av)
{
    std::ifstream fd;
    
    if(ac == 2)
        fd.open(av[1]);
    if (ac != 2 || !fd)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    if (ft_parse(fd))
    {
        fd.close();
        return (1);
    }
    fd.close();
    return (0);
}
