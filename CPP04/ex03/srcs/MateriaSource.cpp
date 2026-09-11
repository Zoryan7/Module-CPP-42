/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:48:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/02 11:47:58 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource default constructor called" << std::endl;
	int i = 0;
	while(i < 4)
	{
		this->_template[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	int i = 0;
	while(i < 4)
	{
		if (this->_template[i])
			delete this->_template[i];
		this->_template[i] = NULL;
		i++;
	}		
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	// std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &src)
	{
		int i = 0;
		while(i < 4)
		{
			this->_template[i] = NULL;
			i++;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *other)
{
	int i = 0;
	while(i < 4)
	{
		if (this->_template[i] == NULL)
		{
			this->_template[i] = other;
			return ;
		}
		i++;
	}
	delete other; 
	std::cout << "Cannot learn more materia!!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while(i < 4)
	{
		if (this->_template[i] && this->_template[i]->getType() == type)
		{
			return (this->_template[i]->clone());
		}
		i++;
	}
	std::cout << "Materia not found" << std::endl;
	return (NULL);
}

