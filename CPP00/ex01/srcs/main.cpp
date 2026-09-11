/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:11:11 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 00:28:41 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include <string>

int Phonebook::ft_add_contact(void)
{
    std::string message;
    
	while(1)
    {
        std::cout << "enter the contact first name: ";
        std::getline(std::cin , message);
		if (std::cin.eof())
		{
            return (1);
		}
		if (message.empty())
		{
			std::cout << "a field can't be empty" << std::endl;
			continue ;
        }
        this->_contact[_index_contact].ft_set_first_name(message);
		break;
	}
	while (1)
	{
    	std::cout << "enter the contact last name: ";
    	std::getline(std::cin , message);
		
    	if (std::cin.eof())
        {
			return (1);
		}
		if (message.empty())
		{
			std::cout << "a field can't be empty" << std::endl;
			continue ;
        }
    	this->_contact[_index_contact].ft_set_last_name(message);
		break;
	}
	while (1)
	{
    	std::cout << "enter the contact nickname: ";
    	std::getline(std::cin , message);
		if (std::cin.eof())
		{
			return (1);
		}
		if (message.empty())
		{
			std::cout << "a field can't be empty" << std::endl;
			continue ;
        }
    	this->_contact[_index_contact].ft_set_nickname(message);
		break;
	}
	while (1)
    {
    	std::cout << "enter the contact phone number: ";
    	std::getline(std::cin , message);
		if (std::cin.eof())
		{
			return (1);
		}
		if (message.empty())
		{
			std::cout << "a field can't be empty" << std::endl;
			continue ;
        }
    	this->_contact[_index_contact].ft_set_phone_number(message);
		break;
	}
	while (1)
	{
    	std::cout << "enter the contact darkest secret: ";
    	std::getline(std::cin , message);
		if (std::cin.eof())
		{
			return (1);
		}
		if (message.empty())
		{
			std::cout << "a field can't be empty" << std::endl;
			continue ;
        }
    	this->_contact[_index_contact].ft_set_darkest_secret(message);
		break;
	}
    this->ft_refresh_contact();   
    return (0); 
}

void Phonebook::ft_print_all_contact(void) const
{
	int i;
	
	i = 0;
	std::cout << std::setw(10) << "index" << "|"
	<< std::setw(10) <<	"first name"  << "|"
	<< std::setw(10) << "last name" << "|"
	<< std::setw(10) << "nickname" << std::endl;
	while(i < this->_nb_contact)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		if (this->_contact[i].ft_get_first_name().length() < 10)
			std::cout << std::setw(10) << this->_contact[i].ft_get_first_name() << "|";
		else
			std::cout <<this->_contact[i].ft_get_first_name().substr(0, 9) << ".|";
		if(this->_contact[i].ft_get_last_name().length() < 10)
			std::cout << std::setw(10) << this->_contact[i].ft_get_last_name() << "|";
		else
			std::cout << this->_contact[i].ft_get_last_name().substr(0, 9) << ".|";
		if(this->_contact[i].ft_get_nickname().length() < 10)
			std::cout << std::setw(10) << this->_contact[i].ft_get_nickname() << std::endl;
		else
			std::cout << this->_contact[i].ft_get_nickname().substr(0, 9) << ".|" << std::endl;
		i++;
	}
}

int Phonebook::ft_search(void)
{
    std::string message;
	int index;
	
	this->ft_print_all_contact(); 
	while(1)
	{
		std::cout << "enter the contact index you want to see (type QUIT to exit)" << std::endl;
		std::getline(std::cin , message);
		if(std::cin.eof())
			return (1);
		if (message == "QUIT")
			break;
		if(message.length() == 1 && std::isdigit(message[0]))
		{
			index = std::atoi(message.c_str());
			if(index < this->_nb_contact + 1 && index > 0)
				this->_contact[index - 1].ft_print_contact();
			else
				std::cout << "index doesn't exist" << std::endl;
		}
		else
				std::cout << "index doesn't exist" << std::endl;
	}
	return (0);
}

int main(void)
{
    Phonebook phonebook;
    std::string message;

    while (1)
    {
		std::cout << "enter a command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin , message);
        if(std::cin.eof())
            return (1);
        if (message == "EXIT")
            return (0);
		else if(message != "SEARCH" && message != "ADD")
        {
			std::cout << "wrong entry, try again" << std::endl;
			continue ;
		}
        else  if (message == "ADD" && phonebook.ft_add_contact())
            return (1);
        else if(message == "SEARCH" && phonebook.ft_search())
            return(1);

    }
    return (0);
}
