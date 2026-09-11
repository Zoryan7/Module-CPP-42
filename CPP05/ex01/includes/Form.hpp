/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:14:53 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 00:22:14 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <ostream>
#include <string>


class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_sign;
		const int _grade_execute;
		
	public:
		Form();
		Form(const Form &src);
		Form(const std::string &name, int grade_sign, int grade_execute);
		~Form();
		class GradeTooHighException : public std::exception
        {
            public:
            const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char *what(void) const throw();
        };
		Form &operator=(const Form &src);

		std::string ft_get_name() const;
		bool ft_get_is_signed() const;
		int ft_get_grade_sign() const;
		int ft_get_grade_execute() const;
		void beSigned(Bureaucrat &Bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif
