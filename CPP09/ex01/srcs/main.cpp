/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:24:52 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/08 19:02:15 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int ac, char **av)
{
    std::list<int> numbers;
    
    if (ac != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return (1);
    }
    if (ft_RPN(av[1], numbers))
        return (1);
    return (0);    
}
