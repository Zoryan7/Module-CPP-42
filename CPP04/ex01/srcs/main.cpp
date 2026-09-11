/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:48:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/02 11:49:48 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <string>


int main()
{
	Animal* i[10];
	Dog* j = new Dog();
	Cat* l = new Cat();
    std::string idea;
    int k;

    k = 0;
    while (k < 10)
    {
		if (k < 5)
        	i[k] = new Dog();
		else
			i[k] = new Cat();
        k++;
    }	
	std::cout << "hi i am a " << i[6]->getType() << std::endl;
    k = 1;
    std::cout << "what is the dog idea ?" << std::endl;
    std::getline(std::cin, idea);
    j->ft_get_Brain()->ft_set_single_ideas(idea, k);
    k = 1;
    std::cout << "what is the cat idea ?" << std::endl;
    std::getline(std::cin, idea);
    l->ft_get_Brain()->ft_set_single_ideas(idea, k);
    std::cout << "the dog idea is : " << j->ft_get_Brain()->ft_get_single_ideas(0) << std::endl;
    std::cout << "the cat idea is : " << l->ft_get_Brain()->ft_get_single_ideas(0) << std::endl;
	k = 0;
	while (k < 10)
	{
		delete i[k];
		k++;
	}
	delete j;
	delete l;
    return 0;
}