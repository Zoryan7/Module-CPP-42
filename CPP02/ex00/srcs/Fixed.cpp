/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:20:28 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/18 10:51:30 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Fixed default constructor called" << std::endl;
    this->_raw_bits = 0;
    return ;   
}

Fixed::Fixed(const Fixed &b)
{
    std::cout << "Fixed copy constructor called" << std::endl;
    this->_raw_bits = b.getRawBits();
    return ;    
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
    return(this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
    this->_raw_bits = raw;
    return ;
}
Fixed::~Fixed(void)
{
    std::cout << "Fixed destructor called" << std::endl;
    return ;
}

Fixed& Fixed::operator=(const Fixed &b)
{
    std::cout << "Fixed copy assignment called" << std::endl;
    if (this != &b)
    {
        this->_raw_bits = b.getRawBits();
    }
    return *this;
}
