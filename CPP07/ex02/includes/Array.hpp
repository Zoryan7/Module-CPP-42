/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:32:22 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/19 13:44:03 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <cstdlib>


template<typename T>

class Array
{
    private:
        T *array;
        unsigned int len;
        
    public:
        Array();
        Array(unsigned int n) : array(new T[n]()), len(n) {};
        Array(const Array &other);
        Array &operator=(const Array &other);
        T &operator[](const unsigned int &i);
        const T &operator[](const unsigned int &i) const;
        class out_of_range : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Index out of range");
                }
        };
        unsigned int size() const;
        ~Array();
};

#include"../srcs/Array.tpp"

#endif