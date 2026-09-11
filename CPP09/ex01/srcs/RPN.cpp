/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:11:32 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/21 14:45:38 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int ft_calcul(std::list<int> &nb, char op)
{
    int a;
    int b;
    int result;

    b = nb.back();
    nb.pop_back();
    a = nb.back();
    nb.pop_back();

    switch (op)
    {
        case '+':
            result = (a + b);
            break;
        case '-':
            result = (a - b);
            break;
        case '*':
            result = (a * b);
            break;
        case '/':
            if (b == 0)
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
            result = (a / b);
    }
    nb.push_back(result);
    return (0);
}

int ft_RPN(const std::string &dest, std::list<int> &nb)
{
    int i = 0;
    
    while (dest[i])
    {
        while (dest[i] == ' '  || (dest[i] >= 9 && dest[i] <= 13))
            i++;
		if(!dest[i])
            break;
        if (isdigit(dest[i]))
        {
            if (dest[i + 1] && dest[i + 1] != ' ' && (dest[i + 1] < 9 || dest[i + 1] > 13))
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
            nb.push_back(dest[i] - '0');
        }
        else if (dest[i] == '+' || dest[i] == '-' || dest[i] == '*' || dest[i] == '/')
        {
            if (dest[i + 1] && dest[i + 1] != ' ' && (dest[i + 1] < 9 || dest[i + 1] > 13))
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
            if (nb.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
            if (ft_calcul(nb, dest[i]))
                return (1);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return (1);
        }
        i++;
    }
    if (nb.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    std::cout << nb.front() << std::endl;
    return (0);
}

