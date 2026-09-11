/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:54:13 by ymoumene          #+#    #+#             */
/*   Updated: 2026/05/03 16:02:51 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
    private :
        std::string _name;
        Weapon *_weapon;
    
    public :

        HumanB(std::string name);
        ~HumanB(void);
        void setWeapon(Weapon &dest);
        void attack(void) const;
};

#endif