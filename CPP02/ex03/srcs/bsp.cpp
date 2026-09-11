/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 05:42:24 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/18 10:50:32 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

float cross_product(Point const &a, Point const &b, Point const &point)
{
	return ((b.ft_getx().toFloat() - a.ft_getx().toFloat()) * (point.ft_gety().toFloat()
	 - a.ft_gety().toFloat()) - (b.ft_gety().toFloat() - a.ft_gety().toFloat()) * (point.ft_getx().toFloat() 
	 - a.ft_getx().toFloat()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float AB;
	float BC;
	float CA;
	
	AB = cross_product(a, b, point);
	BC = cross_product(b, c, point);
	CA = cross_product(c, a, point);
	if ((AB > 0 && BC > 0 && CA > 0) || (AB < 0 && BC < 0 && CA < 0))
		return (true);
	return (false);
}
