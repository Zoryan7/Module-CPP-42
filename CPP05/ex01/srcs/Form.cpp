/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:14:53 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 00:29:21 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"


Form::Form():
_name("Default"), _is_signed(false), _grade_sign(150), _grade_execute(150)
{
	// std::cout << "Form default constructor called" << std::endl;
}
Form::Form(const std::string &name, int grade_sign, int grade_execute) : _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	// std::cout << "Form name constructor called" << std::endl;
	if (this->_grade_sign < 1 || this->_grade_execute < 1)
		throw Form::GradeTooHighException();
	else if (this->_grade_sign > 150 || this->_grade_execute > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const Form &src):
_name(src._name), _is_signed(src._is_signed), _grade_sign(src._grade_sign), _grade_execute(src._grade_execute)
{
	// std::cout << "Form copy constructor called" << std::endl;
	if (this->_grade_sign < 1 || this->_grade_execute < 1)
		throw Form::GradeTooHighException();
	else if (this->_grade_sign > 150 || this->_grade_execute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	// std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	// std::cout << "Form assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_is_signed = src._is_signed;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
std::string Form::ft_get_name() const
{
	return (this->_name);
}

bool Form::ft_get_is_signed() const
{
	return (this->_is_signed);
}

int Form::ft_get_grade_sign() const
{
	return (this->_grade_sign);
}

int Form::ft_get_grade_execute() const
{
	return (this->_grade_execute);
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->_grade_sign)
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << "Form name: " << src.ft_get_name() << ", is signed: " << (src.ft_get_is_signed() ? "true" : "false") << ", grade required to sign: " << src.ft_get_grade_sign() << ", grade required to execute: " << src.ft_get_grade_execute();
	return out;
}
