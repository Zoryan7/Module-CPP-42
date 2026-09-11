/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:10:11 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/14 12:03:26 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
: ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->ft_set_HitPoints(100);
	this->ft_set_EnergyPoints(100);
	this->ft_set_AttackDamage(30);
	return ;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
	std::cout << "FragTrap constructor with name called" << std::endl;
	this->ft_set_HitPoints(100);
	this->ft_set_EnergyPoints(100);
	this->ft_set_AttackDamage(30);
	return ;
}

FragTrap::FragTrap(const FragTrap &b)
: ClapTrap(b)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}
	
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "<< this->ft_get_Name() << " want a big high five!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &b)
{
	this->_name = b._name;
	this->_HitPoints = b._HitPoints;
	this->_EnergyPoints = b._EnergyPoints;
	this->_AttackDamage = b._AttackDamage;
	return (*this);
}
