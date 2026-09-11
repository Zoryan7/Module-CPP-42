/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:52:03 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/20 22:47:41 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

template<template<typename, typename> class T>

PmergeMe<T>::PmergeMe() 
: _algo_time(0.0)
{
}

template<template<typename, typename> class T>

PmergeMe<T>::PmergeMe(const typename PmergeMe<T>::container_type &src)
    : _src(src), _algo_time(0.0)
{
}

template<template<typename, typename> class T>

PmergeMe<T>::PmergeMe(const PmergeMe &src)
    : _src(src._src), _result(src._result), _algo_time(src._algo_time)
{
}

template<template<typename, typename> class T>

PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_src = src._src;
        this->_result = src._result;
        this->_algo_time = src._algo_time;
    }
    return (*this);
}

template<template<typename, typename> class T>

PmergeMe<T>::~PmergeMe()
{
}

template<template<typename, typename> class T>

typename PmergeMe<T>::container_type PmergeMe<T>::get_src() const
{
    return (this->_src);
}

template<template<typename, typename> class T>

typename PmergeMe<T>::container_type PmergeMe<T>::get_result() const
{
    return (this->_result);
}

template<template<typename, typename> class T>

double PmergeMe<T>::get_algo_time() const
{
    return (this->_algo_time);
}

template<template<typename, typename> class T>

void PmergeMe<T>::ft_update_b_pos(pos_type &b_pos,
    typename container_type::iterator &it, container_type &result)
{
    unsigned int pos;
    typename pos_type::iterator first;

    pos = static_cast<unsigned int>(it - result.begin());
    first = std::lower_bound(b_pos.begin(), b_pos.end(), pos);
    while (first != b_pos.end())
    {
        (*first)++;
        first++;
    }
}

template<template<typename, typename> class T>

typename PmergeMe<T>::container_type PmergeMe<T>::ft_insert( container_type &b_table, container_type &a_table,
    const unsigned int (&len)[3], const unsigned int &odd_i)
{
    container_type result;
    typename container_type::iterator it;
    pos_type b_pos;
    unsigned int i = 0;
    unsigned int j;
    unsigned int is_odd = (len[0] < len[2]);
    unsigned int first = 1;
    unsigned int second = 3;
    unsigned int third;

    while (i < len[1] + is_odd)
    {
        b_pos.push_back(i + 1);
        i++;
    }
    result.push_back(a_table[b_table[0].index]);
    result.insert(result.end(), b_table.begin(), b_table.end());
    if (is_odd)
    {
        b_table.push_back(a_table[odd_i]);
    }
    while (first < len[1] + is_odd)
    {
        j = std::min(len[1] + is_odd, second);
        while (j > first)
        {
            it = std::lower_bound(result.begin(),
                    result.begin() + b_pos[j - 1],
                    a_table[b_table[j - 1].index], ft_compare_index);
            ft_update_b_pos(b_pos, it, result);
            result.insert(it, a_table[b_table[j - 1].index]);
            j--;
        }
        third = second + 2 * first;
        first = second;
        second = third;
    }
    if (is_odd)
        b_table.pop_back();
    return (result);
}

template<template<typename, typename> class T>

void PmergeMe<T>::ft_make_pair(container_type &vec, container_type &a_table,
    container_type &b_table, const unsigned int (&len)[3],
    const unsigned int &max_size)
{
    unsigned int i;
    t_index b_zero;

    b_zero.index = 0;
    b_zero.number = 0;
    a_table.assign(max_size, b_zero);
    i = 0;
    while (i < len[0])
    {
        if (vec[i].number < vec[i + 1].number)
        {
            b_table.push_back(vec[i + 1]);
            a_table[vec[i + 1].index] = vec[i];
        }
        else
        {
            b_table.push_back(vec[i]);
            a_table[vec[i].index] = vec[i + 1];
        }
        i += 2;
    }
    if (len[0] != len[2])
        a_table[vec.back().index] = vec.back();
}

template<template<typename, typename> class T>

bool PmergeMe<T>::ft_len(unsigned int (&len)[3], const container_type &vec)
{
    len[2] = static_cast<unsigned int>(vec.size());
    if (len[2] == 1)
        return (true);
    len[0] = len[2];
    if (len[2] % 2 != 0)
        len[0]--;
    len[1] = len[0] / 2;
    return (false);
}

template<template<typename, typename> class T>

typename PmergeMe<T>::container_type PmergeMe<T>::ft_ford_johnson(
    container_type &vec, const unsigned int &max_size)
{
    unsigned int len[3];
    unsigned int odd_i  = vec.back().index;
    container_type b_table;
    container_type a_table;
    container_type result;

    if (ft_len(len, vec))
        return (vec);
    ft_make_pair(vec, a_table, b_table, len, max_size);
    b_table = ft_ford_johnson(b_table, max_size);
    result = ft_insert(b_table, a_table, len, odd_i);
    return (result);
}

template<template<typename, typename> class T>

void PmergeMe<T>::ft_algorithm(void)
{
    std::clock_t start;
    std::clock_t end;

    start = std::clock();
    this->_result = ft_ford_johnson(this->_src, this->_src.size());
    end = std::clock();
    this->_algo_time = ft_mesure_time(start, end);
}

template<template<typename, typename> class T>

void PmergeMe<T>::ft_print_result() const
{
    typename container_type::const_iterator it;

    it = this->_result.begin();
    while (it != this->_result.end())
    {
        std::cout << it->number << " ";
        it++;
    }
    std::cout << std::endl;
}

template<template<typename, typename> class T>

void PmergeMe<T>::print_time(const std::string &container_name) const
{
    std::cout << "Time to process a range of " << this->_src.size()
              << " elements with " << container_name << " : " << std::fixed
              << this->_algo_time << " us" << std::endl;
}

template<template<typename, typename> class T>
void PmergeMe<T>::ft_add_time(double time)
{
    this->_algo_time += time;
}

template class PmergeMe<std::vector>;
template class PmergeMe<std::deque>;



