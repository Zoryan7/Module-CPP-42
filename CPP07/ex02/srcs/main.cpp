/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:25:02 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/20 13:52:18 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main(void)
{
    Array<int> arr1(5);
	Array<int> arr2;
    Array<std::string> arr3(3);
	
    std::cout << "Array size: " << arr1.size() << std::endl; 
    for (unsigned int i = 0; i < arr1.size(); i++)
        arr1[i] = i * 10;
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    try
    {
        std::cout << "Accessing out of range index: " << arr2[10] << std::endl;
    }
    catch (const Array<int>::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
	arr3[0] = "Hello";
	arr3[1] = "World";
	std::cout << "arr3[0]: " << arr3[0] << std::endl;
	std::cout << "arr3[1]: " << arr3[1] << std::endl;
    return (0);
}