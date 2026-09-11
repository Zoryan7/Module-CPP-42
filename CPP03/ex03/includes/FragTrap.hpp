/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 08:09:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/14 12:03:18 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &b);
		~FragTrap(void);
		void highFivesGuys(void);
		FragTrap &operator=(const FragTrap &b);
};

#endif