/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:51:43 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/21 14:13:01 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <ctime>


typedef struct s_index
{
    unsigned int number;
    unsigned int index;
} t_index;

template<template<typename, typename> class T>
class PmergeMe
{
    private :
        typedef T<t_index, std::allocator<t_index> > container_type;
        typedef T<unsigned int, std::allocator<unsigned int> > pos_type;

        container_type  _src;
        container_type  _result;
        double          _algo_time;

        //fonctions auxiliaires
        static bool ft_compare_index(const t_index &a, const t_index &b)
        {return (a.number < b.number);}
        double ft_mesure_time(std::clock_t &start, std::clock_t &end)
        {return(double (end - start) * 1000000  / CLOCKS_PER_SEC);}
    
        // fonctions de l'algorithme
        void ft_update_b_pos(pos_type &b_pos,
            typename container_type::iterator &it, container_type &result);
        container_type ft_insert(container_type &b_table,
            container_type &a_table, const unsigned int (&len)[3], const unsigned int &odd_i);
        bool ft_len(unsigned int (&len)[3], const container_type &vec);
        void ft_make_pair(container_type &vec, container_type &a_table,
            container_type &b_table, const unsigned int (&len)[3],
            const unsigned int &max_size);
        container_type ft_ford_johnson(container_type &vec,
            const unsigned int &max_size);
        
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe(const container_type &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        void ft_add_time(double time);
        void ft_algorithm(void);
        container_type get_src() const;
        container_type get_result() const;
        double get_algo_time() const;
        void ft_print_result() const;
        void print_time(const std::string &container_name) const;
};

#endif
