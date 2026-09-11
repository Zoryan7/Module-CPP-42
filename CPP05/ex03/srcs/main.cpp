/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:04:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/23 17:27:24 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

static void	test_form(Intern &intern, Bureaucrat &boss,
	const std::string &name, const std::string &target)
{
	AForm	*form;

	form = NULL;
	try
	{
		form = intern.makeForm(name, target);
		boss.signForm(*form);
		boss.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	delete form;
}

int	main(void)
{
	Intern		intern;
	Bureaucrat	boss("Boss", 1);

	test_form(intern, boss, "shrubbery creation", "home");
	test_form(intern, boss, "robotomy request", "Bender");
	test_form(intern, boss, "presidential pardon", "Arthur");
	test_form(intern, boss, "coffee request", "Marvin");
	return (0);
}
