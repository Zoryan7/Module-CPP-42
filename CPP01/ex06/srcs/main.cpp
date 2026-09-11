/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:03:06 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/02 16:43:26 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    
    if (argc != 2)
        return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 1);
    harl.complain(argv[1]);
    return (0);
}