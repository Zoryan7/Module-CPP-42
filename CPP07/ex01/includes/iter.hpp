/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:03:13 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/01 16:09:21 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template<typename T, typename F>

void iter(T *array, unsigned int len, F f)
{
    unsigned int i;

    i = 0;
    while(i < len)
    {
        f(array[i]);
        i++;
    }
}

#endif