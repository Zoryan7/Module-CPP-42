/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:18:42 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/20 15:44:08 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack() 
: std::stack<T>() 
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) 
: std::stack<T>(src) 
{}

template<typename T>
MutantStack<T>::~MutantStack() 
{}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &src)
{
    if (this != &src)
        this->c = src.c;
    return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() 
{
    return this->c.end();
}


template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const 
{
	return this->c.begin();
}


template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const 
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const 
{
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() 
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() 
{
	return this->c.rend();
}
