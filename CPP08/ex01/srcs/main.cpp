/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:16:00 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/19 21:22:28 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
    Span sp = Span(10);
    std::vector<int> arr;   
    
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(-3);
    arr.push_back(4);
    arr.push_back(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(arr.begin(), arr.end());
    Span dp = Span(sp);
    std::cout << dp.shortestSpan() << std::endl;
    std::cout << dp.longestSpan() << std::endl;
    return (0);
}