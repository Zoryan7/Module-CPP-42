/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:36:32 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 16:42:04 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() 
: AAnimal()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout  << "Dog default constructor called" << std::endl;
}
	
Dog::Dog(const Dog &other)
: AAnimal(other)
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    *this->brain = *other.brain;
    this->type = other.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "WOUAF WOUAF" << std::endl;
}

Brain *Dog::ft_get_Brain() const
{
    return (this->brain);
}

void Dog::ft_set_Brain(Brain *brain)
{
    *this->brain = *brain;
}