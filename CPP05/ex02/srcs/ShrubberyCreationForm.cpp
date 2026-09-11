/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:37:29 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 11:43:36 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	// std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
AForm(src), _target(src._target)
{
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm name constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
	
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	// std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string file = this->_target + "_shrubbery";
	if (!this->ft_get_is_signed())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->ft_get_grade_execute())
		throw AForm::GradeTooLowException();
	std::ofstream out(file.c_str());
	if(!out)
		throw std::runtime_error("Cannot open shrubbery output file.");
	out << "       /\\\n";
    out << "      /  \\\n";
    out << "     /____\\\n";
    out << "       ||\n";
    out << "       ||\n";
    out << "\n";
    out << "        &&\n";
    out << "       &&&\n";
    out << "      &&&&&\n";
    out << "     &&&&&&&\n";
    out << "        ||\n";
    out << "        ||\n";
	out << "\n";
    out << "        &&\n";
    out << "       &&&\n";
    out << "      &&&&&\n";
    out << "     &&&&&&&\n";
    out << "        ||\n";
    out << "        ||\n";
}
