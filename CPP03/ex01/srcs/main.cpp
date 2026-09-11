/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 06:05:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 13:17:04 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int    main(void)
{
  	ScavTrap   Enzo("Enzo");
    ClapTrap   Evan("Evan");
    int            Previous_Enzo_Ep = Enzo.ft_get_EnergyPoints();

    std::cout << "\n\033[1;32m|| Welcome to the ASC (Amazing ScavTrap Combat) ||\033[0m\n" << std::endl;
	Enzo.guardGate();
    for (int i = 0; i < 15; i++)
    {
        std::cout << "\n\033[31m~~!!!Round " << i + 1 << " Started!!!~~\033[0m\n" << std::endl;
        Enzo.attack("Evan");
        if (Previous_Enzo_Ep != 0)
            Evan.takeDamage(Enzo.ft_get_AttackDamage());
        Previous_Enzo_Ep = Enzo.ft_get_EnergyPoints();
        if (i % 2)
            Evan.beRepaired(3);
        std::cout << "\n\033[31m~~!!!Round " << i + 1 << " Finished!!!~~\033[0m\n" << std::endl;
    }
	std::cout << Enzo.ft_get_Name() << " has " << Enzo.ft_get_HitPoints() << " hit points remaining.\033[0m\n" << std::endl;
	std::cout << Evan.ft_get_Name() << " has " << Evan.ft_get_HitPoints() << " hit points remaining.\033[0m\n" << std::endl;
	if (Enzo.ft_get_HitPoints() > Evan.ft_get_HitPoints()
		&& Enzo.ft_get_HitPoints() > 0)
	std::cout << "\n\033[1;32m|| " << Enzo.ft_get_Name() << " is the winner of the ASC ||\033[0m\n" << std::endl;
	else if (Evan.ft_get_HitPoints() > Enzo.ft_get_HitPoints()
		&& Evan.ft_get_HitPoints() > 0)
	std::cout << "\n\033[2;32m|| " << Evan.ft_get_Name() << " is the winner of the ASC ||\033[0m\n" << std::endl;	
    std::cout << "\n\033[1;32m|| See you next time at the ASC ||\033[0m\n" << std::endl;
    return (0);
}