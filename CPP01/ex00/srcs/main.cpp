/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:33:20 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 03:26:15 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("Yanis");
	
    randomChump("Shanice");
    zombie->announce();
    delete zombie;
    return 0;
}