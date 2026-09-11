/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:41:51 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/19 21:21:29 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <algorithm>
#include <vector>

Span::Span()
{
	//std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int nb) :
_n(nb)
{
	return ;
}

Span::Span(const Span &src)
{
	//std::cout << "Span copy constructor called" << std::endl;
	*this = src;
}

Span::~Span()
{
	//std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(const Span &src)
{
	//std::cout << "Span assignment operator called" << std::endl;
	if (this != &src)
	{
		_n = src._n;
		_vec = src._vec;
	}
	return *this;
}

void Span::addNumber(int nb)
{
	if(this->_vec.size() < this->_n)
	{
		_vec.push_back(nb);
		return; 
	}
	throw Span::Span_full();
}



unsigned int Span::shortestSpan() const
{
	unsigned int	shortest;
	unsigned int 	temp_shortest;
	size_t i;
	std::vector<int> temp = this->_vec;
	
	if(this->_vec.size() < 2)
		throw Span::not_enough_nb();
	std::sort(temp.begin(), temp.end());
	shortest = static_cast<unsigned int>(temp[1]) - static_cast<unsigned int>(temp[0]);
	i = 1;
	while(i < temp.size() - 1)
	{
		temp_shortest = static_cast<unsigned int>(temp[i+1]) - static_cast<unsigned int>(temp[i]);
		if(temp_shortest < shortest)
			shortest = temp_shortest;
		i++;
	}
	return (shortest);
}

unsigned int Span::longestSpan() const
{
	int min;
	int max;
	
	if(this->_vec.size() < 2)
		throw Span::not_enough_nb();
	min = *std::min_element(this->_vec.begin(),this->_vec.end());
	max = *std::max_element(this->_vec.begin(),this->_vec.end());
	return (static_cast<unsigned int>(max) - static_cast<unsigned int>(min));
}

