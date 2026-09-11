/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:06:58 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/20 16:18:21 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>
#include <list>


int main()
{
    std::vector<int> vec;
	std::cout << "Vector: ";
    for (int i = 23; i > 0; --i)
        vec.push_back(i);
    std::vector<int>::iterator it = easyfind(vec, 5);
    std::cout << "Found: " << *it << std::endl;
    it = easyfind(vec, 100);
    std::cout <<  "Found: " << (it == vec.end() ? "No" : "Yes") << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	std::cout << "List: ";
	std::list<int>::iterator it2 = easyfind(lst, 10);
	std::cout << "Found: " << *it2 << std::endl;
	it2 = easyfind(lst, 5);
	std::cout << "Found: " << (it2 == lst.end() ? "No" : "Yes") << std::endl;
    return 0;
}