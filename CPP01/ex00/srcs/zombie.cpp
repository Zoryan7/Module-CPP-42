/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:32:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 04:18:16 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombie.hpp"

Zombie::Zombie(void) 
:_name()
{}

Zombie::Zombie(std::string name) 
:_name(name)
{}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " was crushed. (destroyed)" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}