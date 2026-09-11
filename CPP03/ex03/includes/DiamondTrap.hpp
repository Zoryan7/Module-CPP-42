/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:11:48 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 13:31:15 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include"ScavTrap.hpp"
#include"FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
    private :
        std::string _name;
    
	public :
    
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &b);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		void attack(const std::string &target);
		DiamondTrap &operator=(const DiamondTrap &b);
		void whoAmI();
};


#endif