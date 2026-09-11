/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:25:53 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/25 18:42:51 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *_inventory[4];
		int 	_size_inventory;
		std::string _name;

	public:
		Character();
		Character(std::string name);
		Character(const Character &src);
		~Character();
		Character &operator=(const Character &src);
		virtual std::string const & getName() const;
    	virtual void equip(AMateria* m);
    	virtual void unequip(int idx);
    	virtual void use(int idx, ICharacter& target);
};

#endif
