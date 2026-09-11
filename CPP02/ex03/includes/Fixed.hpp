/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:21:11 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/18 10:33:34 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>

class Fixed 
{

    private :
        int _raw_bits;
        static const int _fractional_bits = 8;
    
    public :
    
    Fixed(void);
    Fixed(const Fixed &b);
    Fixed(const int raw);
    Fixed(const float raw);
	~Fixed(void);
	
    Fixed &operator=(const Fixed &b);
	bool operator<(const Fixed &b) const;
	bool operator>(const Fixed &b) const;
	bool operator<=(const Fixed &b) const;
	bool operator>=(const Fixed &b) const;
	bool operator==(const Fixed &b) const;
	bool operator!=(const Fixed &b) const;
	Fixed operator+(const Fixed &b) const;
	Fixed operator-(const Fixed &b) const;
    Fixed operator*(const Fixed &b) const;
	Fixed operator/(const Fixed &b) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	
    static const Fixed &max(const Fixed &a, const Fixed &b) ;
	static const Fixed &min(const Fixed &a, const Fixed &b) ;
	static  Fixed &max(Fixed &a, Fixed &b) ;
	static  Fixed &min(Fixed &a, Fixed &b) ;
	
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits() const;
    void setRawBits(const int b);
};

std::ostream &operator<<(std::ostream &other, const Fixed &value);

#endif
