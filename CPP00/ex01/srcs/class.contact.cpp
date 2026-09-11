/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:08:58 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/28 12:00:26 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

void Contact::ft_print_contact(void) const
{
	std::cout << "first name : " << this->_first_name << std::endl;
	std::cout << "last name : " << this->_last_name << std::endl;
	std::cout << "nickname : " << this->_nickname << std::endl;
	std::cout << "phone number : " << this->_phone_number << std::endl;
	std::cout << "darkest secret : " << this->_darkest_secret << std::endl;
}

std::string Contact::ft_get_first_name(void) const
{
	return(this->_first_name);
}

std::string Contact::ft_get_last_name(void) const
{
	return(this->_last_name);
}

std::string Contact::ft_get_nickname(void) const
{
	return(this->_nickname);
}

std::string Contact::ft_get_phone_number(void) const
{
	return(this->_phone_number);
}

std::string Contact::ft_get_darkest_secret(void) const
{  
    return(this->_darkest_secret);
}

int Contact::ft_set_first_name(std::string ft)
{ 
	this->_first_name = ft;
	return 0;
}

int Contact::ft_set_last_name(std::string ft)
{ 
	this->_last_name = ft;
	return 0;
}

int Contact::ft_set_nickname(std::string ft)
{
	this->_nickname = ft;
	return 0;
}

int Contact::ft_set_phone_number(std::string ft)
{ 
	this->_phone_number = ft;
	return 0;
}

int Contact::ft_set_darkest_secret(std::string ft)
{ 
	this->_darkest_secret = ft; 
	return 0;
}