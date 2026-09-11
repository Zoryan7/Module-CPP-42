/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:13:29 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 04:04:42 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"


Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug( void )const
{
    std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void ) const
{
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ) const
{
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void ) const
{
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

 void Harl::complain(std::string level ) const
 {
    int i;
    std::string level_name[4] = {"DEBUG","INFO","WARNING","ERROR"};
    
    i = 0;
    while (i < 4)
    {
        if(level == level_name[i])
        {
            switch (i)
            {
                case 0:
                    this->debug();
					break ;
                case 1:
                    this->info();
					break ;
                case 2:
                    this->warning();
					break ;
                case 3:
                    this->error();
					break ;
            }
            return ;
        }
        i++;
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
 }