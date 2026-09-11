/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:52:30 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/21 14:10:28 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool ft_parsing(std::vector<t_index> &vec, std::deque<t_index> &queue,
    char **av, int ac)
{
    int i;
    char *end;
    long nb;
    t_index temp;

    i = 1;
    while (i < ac)
    {
        errno = 0;
        nb = std::strtol(av[i], &end, 10);
        if (errno == ERANGE || nb <= 0 || nb > std::numeric_limits<int>::max() || end[0] != 0 || end == av[i])
		{
			std::cerr << "Error" << std::endl;
            return (true);
        }
        temp.number = static_cast<unsigned int>(nb);
        temp.index = i - 1;
        vec.push_back(temp);
        queue.push_back(temp);
        i++;
    }
    std::cout << "Before: ";
    i = 0;
    while (i < ac - 1)
    {
        std::cout << vec[i].number << " ";
        i++;
    }
    std::cout << std::endl;
    return (false);
}

int main(int ac, char **av)
{
    std::vector<t_index> vec;
    std::deque<t_index> queue;

    if (ac < 2)
    { 
        std::cerr << "Error" << std::endl;
        return (1);
    }
    if (ft_parsing(vec, queue, av, ac))
        return (1);
    PmergeMe<std::vector> vec_algo(vec);
    PmergeMe<std::deque> queue_algo(queue);
    vec_algo.ft_algorithm();
    queue_algo.ft_algorithm();
    std::cout << "After: ";
    vec_algo.ft_print_result();
    vec_algo.print_time("std::vector");
    queue_algo.print_time("std::deque");
    return (0);
}
