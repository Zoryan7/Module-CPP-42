/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:04:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 12:13:11 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


int main()
{
	Bureaucrat bureaucrat1("Jean de la fontaine", 32);
	Bureaucrat bureaucrat2("Victor Hugo", 1);
	Bureaucrat bureaucrat3("Albert Camus", 23);
	ShrubberyCreationForm form1("forest");
	PresidentialPardonForm form2("Jean Valjean");
	RobotomyRequestForm form3("r2d2");
	
	bureaucrat1.signForm(form1);
	bureaucrat2.signForm(form3);
	bureaucrat3.signForm(form2);
	bureaucrat1.executeForm(form1);
	try 
	{
		form2.execute(bureaucrat3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	form3.execute(bureaucrat1);
	return (0);
}
