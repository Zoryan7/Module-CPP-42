/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:31:45 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/23 18:58:38 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <exception>

class Intern
{
	private:
		AForm *ft_create_president(const std::string &target);
		AForm *ft_create_shrubbery(const std::string &target);
		AForm *ft_create_robot(const std::string &target);

	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);
		class FormDoesNotExistException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};		
		AForm *makeForm(const std::string &form, const std::string &target);
};

#endif
