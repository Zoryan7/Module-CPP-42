/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 06:05:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 13:16:11 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int    main(void)
{
    ClapTrap    Anis("Anis");
    ClapTrap    Evan("Evan");
    int            Previous_anis_Ep = Anis.ft_get_EnergyPoints();

    std::cout << "\n\033[1;32m|| Welcome to the ACC (Amazing ClapTrap Combat) ||\033[0m\n" << std::endl;
    for (int i = 0; i < 15; i++)
    {
        std::cout << "\n\033[31m~~!!!Round " << i + 1 << " Started!!!~~\033[0m\n" << std::endl;
        Anis.attack("Evan");
        if (Previous_anis_Ep != 0)
            Evan.takeDamage(Anis.ft_get_AttackDamage());
        Previous_anis_Ep = Anis.ft_get_EnergyPoints();
        if (i % 2)
            Evan.beRepaired(3);
        std::cout << "\n\033[31m~~!!!Round " << i + 1 << " Finished!!!~~\033[0m\n" << std::endl;
    }
	std::cout << Anis.ft_get_Name() << " has " << Anis.ft_get_HitPoints() << " hit points remaining.\033[0m\n" << std::endl;
	std::cout << Evan.ft_get_Name() << " has " << Evan.ft_get_HitPoints() << " hit points remaining.\033[0m\n" << std::endl;
	if (Anis.ft_get_HitPoints() > Evan.ft_get_HitPoints()
		&& Anis.ft_get_HitPoints() > 0)
	std::cout << "\n\033[1;32m|| " << Anis.ft_get_Name() << " is the winner of the ACC ||\033[0m\n" << std::endl;
	else if (Evan.ft_get_HitPoints() > Anis.ft_get_HitPoints()
		&& Evan.ft_get_HitPoints() > 0)
	std::cout << "\n\033[2;32m|| " << Evan.ft_get_Name() << " is the winner of the ACC ||\033[0m\n" << std::endl;	
    std::cout << "\n\033[1;32m|| See you next time at the ACC ||\033[0m\n" << std::endl;
    return (0);
}