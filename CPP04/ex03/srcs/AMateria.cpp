/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:00:33 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 17:17:57 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria() :
_type("")
{
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src) :
_type(src._type)
{
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::AMateria(std::string const &type) :
_type(type)
{
	// std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout<< "* do a thing at ICharacter" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	// std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return *this;
}

std::string AMateria::ft_get_type(void)
{
	return (this->_type);
}