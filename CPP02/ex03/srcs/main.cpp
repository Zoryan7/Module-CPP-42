/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:05:25 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/17 21:56:12 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Point.hpp"

int main( void )
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point point(5, 5);

    if (bsp(a, b, c, point))
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;

    return 0;
}
