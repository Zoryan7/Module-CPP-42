/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:25:53 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 17:16:51 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
{
	int	i;

	// std::cout << "Character default constructor called" << std::endl;
	_name = "";
	_size_inventory = 0;
	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}
Character::Character(std::string name) :
_size_inventory(0), _name(name)
{
	int	i;

	// std::cout << "Character name constructor called" << std::endl;
	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}
Character::Character(const Character &src)
{
	int	i;

	// std::cout << "Character copy constructor called" << std::endl;
	_name = "";
	_size_inventory = 0;
	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
	*this = src;
}

Character::~Character()
{
	int	i;

	// std::cout << "Character destructor called" << std::endl;
	i = 0;
	while (i < 4)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		i++;
	}
}

Character &Character::operator=(const Character &src)
{
	int	i;

	// std::cout << "Character assignment operator called" << std::endl;
	if (this != &src)
	{
		i = 0;
		while (i < 4)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			i++;
		}
		this->_name = src._name;
		this->_size_inventory = 0;
		i = 0;
		while (i < 4)
		{
			if (src._inventory[i] != NULL)
			{
				this->_inventory[i] = src._inventory[i]->clone();
				this->_size_inventory++;
			}
			i++;
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::unequip(int idx)
{
	int i;

	if (idx >= 0 && idx < this->_size_inventory && this->_inventory[idx])
	{
		i = idx;
		while (i < this->_size_inventory - 1)
		{
			this->_inventory[i] = this->_inventory[i + 1];
			i++;
		}
		this->_inventory[i] = NULL;
		this->_size_inventory--;
	}
	std::cout << "invalid index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < this->_size_inventory && this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
		return ;
	}
	std::cout << "invalid index" << std::endl;
}


void Character::equip(AMateria* m)
{
	int i = 0;
	
	if (this->_size_inventory != 4)
	{
		while (i < _size_inventory)
		{
			if(&m == &this->_inventory[i])
			{
				std::cout << "the Character has already equip this materia !!" << std::endl;
				return ; 
			}
			i++;
		}	
		this->_inventory[_size_inventory] = m;
		this->_size_inventory++;
	}
	else
		std::cout << "inventory full of materias !!" << std::endl;
}