/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:24:51 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 13:48:09 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = "Default";
    this->ft_set_HitPoints(100);
	this->ft_set_EnergyPoints(50);
	 this->ft_set_AttackDamage(30);
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &b) : ClapTrap(b), ScavTrap(b), FragTrap(b)
{
    *this = b;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}
	
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->ft_set_HitPoints(100);
    this->ft_set_EnergyPoints(50);
	this->ft_set_AttackDamage(30);
    std::cout << "DiamondTrap constructor with name called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &b)
{
    this->_name = b._name;
    this->_HitPoints = b._HitPoints;
    this->_EnergyPoints = b._EnergyPoints;
    this->_AttackDamage = b._AttackDamage;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->_name << ", a DiamondTrap! and I am also " << ClapTrap::ft_get_Name() << " a ClapTrap!" << std::endl;
}
