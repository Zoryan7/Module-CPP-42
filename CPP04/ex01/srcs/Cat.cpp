/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:39:51 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 16:05:19 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
: Animal()
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
:Animal(other)
{
    this->brain = new Brain();
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    *this->brain = *other.brain;
    this->type = other.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "MIAOOOOOUUUUUUUUU" << std::endl;
}

Brain *Cat::ft_get_Brain() const
{
    return (this->brain);
}

void Cat::ft_set_Brain(Brain *brain)
{
    *this->brain = *brain;
}