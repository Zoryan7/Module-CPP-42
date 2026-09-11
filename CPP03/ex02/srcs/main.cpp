/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 06:05:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 13:26:56 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"


int    main(void)
{
  	ScavTrap   Enzo("Enzo");
    FragTrap   Hugo("Hugo");
    int        Previous_Enzo_Ep = Enzo.ft_get_EnergyPoints();

    std::cout << "\n\033[1;32m|| Welcome to the AFC (Amazing FragTrap Combat) ||\033[0m\n" << std::endl;
	Enzo.guardGate();
	Hugo.highFivesGuys();
    for (int i = 0; i < 15; i++)
    {
        std::cout << "\n\033[31m~~!!!Round " << i + 1 << " Started!!!~~\033[0m\n" << std::endl;
        Enzo.attack("Hugo");
        if (Previous_Enzo_Ep != 0)
            Hugo.takeDamage(Enzo.ft_get_AttackDamage());
        Previous_Enzo_Ep = Enzo.ft_get_EnergyPoints();
        if (i % 2)
            Hugo.beRepaired(3);
        std::cout << "\n\033[31m~~!!!Round " << i + 1 << " Finished!!!~~\033[0m\n" << std::endl;
    }
	std::cout << Enzo.ft_get_Name() << " has " << Enzo.ft_get_HitPoints() << " hit points remaining.\033[0m\n" << std::endl;
	std::cout << Hugo.ft_get_Name() << " has " << Hugo.ft_get_HitPoints() << " hit points remaining.\033[0m\n" << std::endl;
	if (Enzo.ft_get_HitPoints() > Hugo.ft_get_HitPoints()
		&& Enzo.ft_get_HitPoints() > 0)
	std::cout << "\n\033[1;32m|| " << Enzo.ft_get_Name() << " is the winner of the AFC ||\033[0m\n" << std::endl;
	else if (Hugo.ft_get_HitPoints() > Enzo.ft_get_HitPoints()
		&& Hugo.ft_get_HitPoints() > 0)
	std::cout << "\n\033[2;32m|| " << Hugo.ft_get_Name() << " is the winner of the AFC ||\033[0m\n" << std::endl;	
    std::cout << "\n\033[1;32m|| See you next time at the AFC ||\033[0m\n" << std::endl;
    return (0);
}
