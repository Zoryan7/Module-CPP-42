/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:55:15 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/02 16:40:11 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &dest)
:_name(name), _weapon(dest)
{}

HumanA::~HumanA(void)
{}

void HumanA::attack(void) const
{
    std::cout<< this->_name <<" attacks with their " << this->_weapon.getType() << std::endl;
}