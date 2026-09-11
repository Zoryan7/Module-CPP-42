/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 20:38:36 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/02 16:37:03 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *dest;
    int     i;

    dest = new Zombie[N];
    i = 0;
    while(i < N)
    {
        dest[i].ft_set_name(name);
        i++;
    }
    return (dest);
}