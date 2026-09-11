/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:20:28 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/18 10:42:50 by ymoumene         ###   ########.fr       */
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

Fixed::Fixed(const int b)
{
    std::cout << "Fixed int constructor called" << std::endl;
    this->_raw_bits = b *( 1 << this->_fractional_bits);
    return ;
}

Fixed::Fixed(const float b)
{
    std::cout << "Fixed float constructor called" << std::endl;
    this->_raw_bits = roundf (b * (1 <<this->_fractional_bits));
    return ;
}

float Fixed::toFloat( void ) const
{
    return( this->_raw_bits / float (1 << this->_fractional_bits));
}

int Fixed::toInt( void ) const
{
    return( this->_raw_bits / (1 << this->_fractional_bits));
}

int Fixed::getRawBits(void) const
{
    return(this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
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

std::ostream &operator<<(std::ostream &other, const Fixed &value)
{
    other << value.toFloat();
    return (other);
}
