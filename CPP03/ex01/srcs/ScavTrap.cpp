/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 06:09:56 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/13 18:39:54 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
: ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	std::cout << "ScavTrap constructor with name called" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &b)
: ClapTrap(b)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}
	
void ScavTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy left ! he cannot attack !" << std::endl;
		return ;
	}
	this->_EnergyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap "<< this->_name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &b)
{
	this->_name = b._name;
	this->_HitPoints = b._HitPoints;
	this->_EnergyPoints = b._EnergyPoints;
	this->_AttackDamage = b._AttackDamage;
	return (*this);
}
