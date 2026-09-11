/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:29:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/20 10:25:43 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
	// std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	// std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer()
{
	// std::cout << "Serializer destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	// std::cout << "Serializer assignment operator called" << std::endl;
	if (this != &src)
	{
	}
	return *this;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}