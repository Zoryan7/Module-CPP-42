/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:04:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/23 14:19:32 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() 
{
    Bureaucrat bureaucrat1("Jean de la fontaine", 32);
    Form form1("Formulaire de demande d'achats de balle anti-stress", 33, 50);
    Form form2("Formulaire de demande d'achats de spatule", 22, 35);
    std::cout << bureaucrat1 << std::endl;
    try 
    {   
        bureaucrat1.ft_increment_grade();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.signForm(form1);
        form1.beSigned(bureaucrat1);
        form2.beSigned(bureaucrat1);
    } 
    catch (const std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
