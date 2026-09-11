/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:35:24 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/16 11:41:38 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <ostream>
#include <string>
#include <cstdlib>

class AForm;

class Bureaucrat 
{
    private:
       const std::string _name;
        int         _grade;

    public:
    
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &src);
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
        std::string getName() const;
        int getGrade() const;
        void ft_increment_grade() ;
        void ft_decrement_grade() ;
        void signForm(AForm &form);
        void executeForm(AForm const & form) const;
};


std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);
#endif
