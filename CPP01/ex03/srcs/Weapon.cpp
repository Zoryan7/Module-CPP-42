/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 11:52:26 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 03:47:41 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string first_type)
: _type(first_type)
{}

Weapon::~Weapon(void)
{}

const std::string &Weapon::getType(void) const
{
    return(this->_type);
}

void Weapon::setType(std::string new_type)
{
    this->_type = new_type;
}
