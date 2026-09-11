/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:41:51 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/19 20:48:41 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
		Span();

	public:
		Span(unsigned int nb);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);
		void addNumber(int nb);
		template<typename T>
		void addNumber(T begin, T last)
		{
			std::vector<int> temp (begin, last);
		
			if(temp.size() <= _n -_vec.size())
			{
				_vec.insert(_vec.end(), temp.begin(), temp.end());
				return;
			}
			throw Span::Span_full(); 
		}
		unsigned int shortestSpan() const ;
		unsigned int longestSpan() const ;
		class not_enough_nb : public std::exception
		{
			const char *what() const throw()
			{
				return("not enough value in the Span !");
			}
		};
		class Span_full : public std::exception
		{
			const char *what() const throw()
			{
				return ("The Span cannot take another value!");
			}
		};
};

#endif
