/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:36:32 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 15:50:29 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() 
: Animal()
{
  this->type = "Dog";
  std::cout  << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
: Animal(other)
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    this->type = other.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "WOUAF WOUAF" << std::endl;
}