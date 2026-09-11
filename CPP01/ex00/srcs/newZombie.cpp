/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:37:02 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/02 16:36:13 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *newzombie;

    newzombie = new Zombie(name); 
    return (newzombie);
}
