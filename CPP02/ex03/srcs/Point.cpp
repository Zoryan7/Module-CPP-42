/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 05:28:45 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/18 11:41:34 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"


Point::Point(void)
: _x(0) , _y(0) 
{
	std::cout << "Point default constructor called" << std::endl;
	return ;
}
	
Point::Point(const float x, const float y)
: _x(x) , _y(y) 
{
	std::cout << "Point float constructor called" << std::endl;
	return ;
}

Point::Point(const Point &b):
_x(b.ft_getx()) , _y(b.ft_gety())
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point::~Point(void)
{
	std::cout << "Point destructor called" << std::endl;
	return ;
}

const Fixed &Point::ft_getx(void) const
{
	return this->_x;
}

const Fixed &Point::ft_gety(void) const
{
	return this->_y;
}
	
Point &Point::operator=(const Point &b)
{
	std::cout << "Point assignment operator called" << std::endl;
	(void) b;
	return (*this);
}
