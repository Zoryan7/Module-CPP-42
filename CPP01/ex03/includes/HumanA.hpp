/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:47:09 by ymoumene          #+#    #+#             */
/*   Updated: 2026/05/03 16:04:16 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA 
{
    private :
        std::string _name;
        Weapon &_weapon;
    
    public :

        HumanA(std::string name, Weapon &dest);
        ~HumanA(void);
        void attack(void) const;
};

#endif