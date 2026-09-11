/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:45:31 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/19 13:44:37 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Array.hpp"

template<typename T>
Array<T>::Array() 
: array(0), len(0) 
{}

template<typename T>
Array<T>::Array(const Array &other) : array(new T[other.len]()), len(other.len)
{
    for (unsigned int i = 0; i < len; i++)
        array[i] = other.array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] array;
        len = other.len;
        array = new T[len]();
        for (unsigned int i = 0; i < len; i++)
            array[i] = other.array[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](const unsigned int &i)
{
    if(i < len)
        return(this->array[i]);
    throw out_of_range();
}

template<typename T>
const T &Array<T>::operator[](const unsigned int &i) const
{
    if(i < len)
        return(this->array[i]);
    throw out_of_range();
}


template<typename T>
unsigned int Array<T>::size() const
{
    return (len);
}

template<typename T>
Array<T>::~Array()
{
    delete[] array;
}