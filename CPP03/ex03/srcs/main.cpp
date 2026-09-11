/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 06:05:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 13:49:44 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int    main(void)
{
    FragTrap    Enzo("Enzo");
    ScavTrap    Arnaud("Arnaud");
    DiamondTrap    Logan(" Logan");
    int            Previous_Enzo_Ep = Enzo.ft_get_EnergyPoints();

    Logan.whoAmI();
    Logan.attack("aaaaaaaaaaaa");
    std::cout << "\n|| Welcome to the ADC (Amazing DiamondTrap Combat) ||\n" << std::endl;
    Arnaud.guardGate();
    Enzo.highFivesGuys();
    for (int i = 0; i < 15; i++)
    {
        std::cout << "\n~~!!!Round " << i + 1 << " Started!!!~~\n" << std::endl;
        Enzo.attack("Arnaud");
        if (Previous_Enzo_Ep != 0)
            Arnaud.takeDamage(Enzo.ft_get_AttackDamage());
        Previous_Enzo_Ep = Enzo.ft_get_EnergyPoints();
        if (i % 2)
            Arnaud.beRepaired(1);
        Logan.attack("AAAAAAAAAA");
        std::cout << "\n~~!!!Round " << i + 1 << " Finished!!!~~\n" << std::endl;
    }
    std::cout << "\n|| See you next time at the ADC ||\n" << std::endl;
    return (0);
}