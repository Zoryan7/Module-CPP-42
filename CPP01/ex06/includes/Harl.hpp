/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:06:13 by ymoumene          #+#    #+#             */
/*   Updated: 2026/05/09 09:40:37 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    private:
    
        void debug( void ) const;
        void info( void ) const;
        void warning( void ) const;
        void error( void ) const;
    
    public:

        Harl(void);
        ~Harl(void);
        void complain(std::string level ) const;    
};

#endif