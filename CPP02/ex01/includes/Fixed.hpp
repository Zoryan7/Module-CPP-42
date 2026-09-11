/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:21:11 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/18 10:38:34 by ymoumene         ###   ########.fr       */
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
    Fixed &operator=(const Fixed &b);
    
    ~Fixed(void);
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits() const;
    void setRawBits(const int b);
};

std::ostream &operator<<(std::ostream &other, const Fixed &value);

#endif
