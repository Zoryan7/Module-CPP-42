/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:04:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/16 14:02:11 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"


int main() 
{
    Bureaucrat bureaucrat1("Jean de la fontaine", 1);
    std::cout << bureaucrat1 << std::endl;
    try 
    {   
        bureaucrat1.ft_increment_grade();
         std::cout << bureaucrat1 << std::endl;
 
    } 
    catch (const std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
