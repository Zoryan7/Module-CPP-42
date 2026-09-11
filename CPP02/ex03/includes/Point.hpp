/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 05:21:59 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/18 10:49:36 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
	
		const Fixed _x;
		const Fixed _y;
		
	public :
	
		Point(void);
		Point(const float x, const float y);
		Point(const Point &b);
		~Point(void);
		Point &operator=(const Point &b);
		const Fixed &ft_getx(void) const;
		const Fixed &ft_gety(void) const;
		
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif
