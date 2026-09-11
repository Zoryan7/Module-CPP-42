/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:48:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/02 11:49:07 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <string>


int main()
{
	Cat *Anis = new Cat();
	Dog *Milo = new Dog();
	std::string idea;
	int k;

	k = 0;
	std::cout << "what is the dog idea ?" << std::endl;
	std::getline(std::cin, idea);
	Milo->ft_get_Brain()->ft_set_single_ideas(idea, k);
	k = 0;
	std::cout << "what is the cat idea ?" << std::endl;
	std::getline(std::cin, idea);
	Anis->ft_get_Brain()->ft_set_single_ideas(idea, k);
	std::cout << "the dog idea is : " << Milo->ft_get_Brain()->ft_get_single_ideas(0) << std::endl;
	std::cout << "the cat idea is : " << Anis->ft_get_Brain()->ft_get_single_ideas(0) << std::endl;
	delete Anis;
	delete Milo;
	return (0);
}