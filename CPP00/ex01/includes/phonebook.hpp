/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:11:35 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 00:24:54 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact
{
    private :
    
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

    public:

        Contact(void){};
        ~Contact(void){};
        std::string ft_get_first_name(void) const;
        std::string ft_get_last_name(void) const;
        std::string ft_get_nickname(void) const;
        std::string ft_get_phone_number(void) const;
        std::string ft_get_darkest_secret(void) const;
        int ft_set_first_name(std::string ft);
        int ft_set_last_name(std::string ft);
        int ft_set_nickname(std::string ft);
        int ft_set_phone_number(std::string ft);
        int ft_set_darkest_secret(std::string ft);
		void ft_print_contact(void) const ;
};

class Phonebook 
{
    private :
        class Contact _contact[8];
        int           _nb_contact;
		int			  _index_contact;
        
    public:
        
        Phonebook(void)
		: _nb_contact(0) , _index_contact(0)
		{};
        ~Phonebook(void){};
		
        int ft_get_nb_contact(void) const
        {
            return (this->_nb_contact);
        };
		
        void ft_refresh_contact(void)
        {
            if (this->_nb_contact < 8)
				this->_nb_contact++;
			if (this->_index_contact < 7)
            {
                this->_index_contact++;
            }   
            else
            {
                this->_index_contact = 0;
            }
            return ;
        };
		
        void ft_print_contact(int index) const;
        int ft_add_contact(void);
        int ft_search(void);
		void ft_print_all_contact(void) const;
};



#endif