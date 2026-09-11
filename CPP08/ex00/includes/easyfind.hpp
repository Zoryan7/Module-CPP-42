/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:46:17 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/01 21:28:37 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>


template<typename T>
typename T::iterator easyfind(T &container, int target)
{
    typename T::iterator dest;
    dest = std::find(container.begin(), container.end(), target);
    return (dest);
}

#endif