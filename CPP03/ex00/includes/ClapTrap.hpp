/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 05:51:18 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/13 18:11:43 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
	protected:

		std::string _name;
		int _HitPoints;
		int _EnergyPoints;
		int _AttackDamage;
		
	public:
	
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &b);
		~ClapTrap(void);
		ClapTrap & operator=(const ClapTrap &b);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void ft_set_Name(std::string name);
		void ft_set_HitPoints(int HitPoints);
		void ft_set_EnergyPoints(int EnergyPoints);
		void ft_set_AttackDamage(int AttackDamage);
		std::string ft_get_Name(void) const;
		int ft_get_HitPoints(void) const;
		int ft_get_EnergyPoints(void) const;
		int ft_get_AttackDamage(void) const;
};

#endif
