/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:55:59 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/02 16:40:24 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
:_name(name),_weapon(NULL)
{}

HumanB::~HumanB(void)
{}

void HumanB::attack(void) const
{
    std::cout<< this->_name <<" attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &dest)
{
    this->_weapon = &dest;
}