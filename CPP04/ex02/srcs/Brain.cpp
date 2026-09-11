/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 13:50:21 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/14 16:28:35 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"


Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    int i;

    i = 0;
    while (i < 100)
    {
        this->_ideas[i] = other._ideas[i];
        i++;
    }
    return (*this);
}

void Brain::ft_set_single_ideas(std::string idea, int index)
{
    if (index < 0 || index >= 100)
        std::cout << "Index out of bounds" << std::endl;
    else
        this->_ideas[index] = idea;
}

std::string Brain::ft_get_single_ideas(int index)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "Index out of bounds" << std::endl;
        return (NULL);
    }
    else
        return (this->_ideas[index]);
}
