/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 06:09:39 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/14 12:03:22 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(const ScavTrap &b);
		ScavTrap(std::string name);
		~ScavTrap(void);
		void guardGate(void);
		void attack(const std::string &target);
		ScavTrap &operator=(const ScavTrap &b);
};

#endif