/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:35:25 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/19 21:14:55 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>

void swap(T &x, T &y)
{
    T temp = y;
    y = x;
    x = temp;
}
template<typename T>

T &max(T &x, T &y)
{
    return(x > y ? x : y);
}


template<typename T>

T &min(T &x, T &y)
{
    return(x < y ? x : y);
}

#endif