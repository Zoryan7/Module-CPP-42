/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:24:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 03:47:15 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include<iostream>

class Weapon
{
    private :
    
        std::string _type;

    public :
        
        Weapon(std::string first_type);
        ~Weapon(void);
        const std::string &getType(void) const;
        void        setType(std::string new_type);
};

#endif