/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 05:53:22 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/13 18:18:39 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
:_name(), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
:_name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap constructor with name called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &b)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = b;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &b)
{
	this->_name = b._name;
	this->_HitPoints = b._HitPoints;
	this->_EnergyPoints = b._EnergyPoints;
	this->_AttackDamage = b._AttackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left ! he cannot attack !" << std::endl;
		return ;
	}
	this->_EnergyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " has taken " << amount << " damage!" << std::endl;
	this->_HitPoints -= amount;
	if (this->_HitPoints < 0)
		this->_HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name << " has been repaired , he gains " << amount << " HP!" << std::endl;
	this->_HitPoints += amount;
	this->_EnergyPoints--;
}

void ClapTrap::ft_set_Name(std::string name)
{
	this->_name = name;
}

void ClapTrap::ft_set_HitPoints(int HitPoints)
{
	this->_HitPoints = HitPoints;
}

void ClapTrap::ft_set_EnergyPoints(int EnergyPoints)
{
	this->_EnergyPoints = EnergyPoints;
}

void ClapTrap::ft_set_AttackDamage(int AttackDamage)
{
	this->_AttackDamage = AttackDamage;
}

std::string ClapTrap::ft_get_Name(void) const
{
	return (this->_name);
}

int ClapTrap::ft_get_HitPoints(void) const
{
	return (this->_HitPoints);
}

int ClapTrap::ft_get_EnergyPoints(void) const
{
	return (this->_EnergyPoints);
}

int ClapTrap::ft_get_AttackDamage(void) const
{
	return (this->_AttackDamage);
}
