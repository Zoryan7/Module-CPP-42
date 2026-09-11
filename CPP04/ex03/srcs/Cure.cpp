/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:24:40 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 17:16:32 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() :
AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src) :
AMateria(src)
{
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	// std::cout << "Cure assignment operator called" << std::endl;
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "\033[32m* heals " << target.getName() << "'s wounds *\033[0m" << std::endl;
}
