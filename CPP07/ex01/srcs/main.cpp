/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:05:57 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/20 13:56:23 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/iter.hpp"


template<typename T>

void ft_print(const T &c)
{
    std::cout << c << std::endl;
}

template<typename T>

void ft_increment(T &c)
{
    c++;
}

int main(void)
{
    char c[5] = {'a', 'b', 'c', 'd', 'e'};
    const int i[5] = {1, 2, 3, 4, 5};
    iter(c, 5, ft_print<char>);
    iter(i, 5, ft_print<int>);
    iter(c, 5, ft_increment<char>);
    // iter(i, 5, ft_increment<int>);
    iter(c, 5, ft_print<char>);
    return 0;
}