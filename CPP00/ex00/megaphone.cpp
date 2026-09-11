/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:00:29 by ymoumene          #+#    #+#             */
/*   Updated: 2026/04/23 11:58:25 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include<iostream>

int main(int argc, char **argv)
{
    int i;
    int j;


    i = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while(i < argc)
    {
        std::string message(argv[i]);
        j = 0;
        while (message[j])
        {
            std::cout << (char)std::toupper(message[j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}
