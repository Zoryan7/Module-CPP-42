/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:33:20 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 04:15:27 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombie.hpp"

int main()
{
    int i;
    int size;

    size = 8;
    Zombie *zombie = zombieHorde(8, "Jon");
    i = 0;
    while(i < size)
    {
        zombie[i].announce();
        i++;
    }
    delete[] zombie;
    return 0;
}