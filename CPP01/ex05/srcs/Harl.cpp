/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:13:29 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/02 16:43:04 by ymoumene         ###   ########.fr       */
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
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) const
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

 void Harl::complain(std::string level ) const
 {
    int i;
    std::string level_name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fn[4])() const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    i = 0;
    while (i < 4)
    {
        if(level == level_name[i])
        {
            (this->*fn[i])();
            return ;
        }
        i++;
    }
    std::cout << "not a valid complain!!" << std::endl;
 }