/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:31:45 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 12:15:44 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

Intern::Intern()
{
	// std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	// std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	// std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	// std::cout << "Intern assignment operator called" << std::endl;
	if (this != &src)
	{
	}
	return *this;
}

AForm *Intern::ft_create_president(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::ft_create_shrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::ft_create_robot(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

const char *Intern::FormDoesNotExistException::what(void) const throw()
{
	return("this type of Form doesnt exist!");
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
	int i;
	AForm *(Intern::*methodform[3])(const std::string &) = { &Intern::ft_create_president, &Intern::ft_create_shrubbery, &Intern::ft_create_robot };
	std::string type[3] = { "presidential pardon", "shrubbery creation", "robotomy request" };

	i = 0;
	while(i < 3)
	{
		if (type[i] == form)
		{
			AForm	*new_form = (this->*methodform[i])(target);

			std::cout << "Intern creates " << new_form->ft_get_name() << std::endl;
			return (new_form);
		}
		i++;
	}
	throw Intern::FormDoesNotExistException();
}
