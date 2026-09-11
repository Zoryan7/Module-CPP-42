/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:21:52 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 17:23:37 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() :
AMateria("ice")
{
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src) :
AMateria(src)
{
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	// std::cout << "Ice assignment operator called" << std::endl;
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "\033[36m* shoots an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
}
