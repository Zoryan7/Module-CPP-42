/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:42:43 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 12:14:37 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 45) , _target(target)
{
	// std::cout << "RobotomyRequestForm name constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
AForm(src), _target(src._target)
{
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	// std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static bool	random_is_seeded = false;
	
	if (!this->ft_get_is_signed())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->ft_get_grade_execute())
		throw AForm::GradeTooLowException();
	if (!random_is_seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		random_is_seeded = true;
	}
	std::cout << "bzzzzz bz bz bzzzz... " << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}
