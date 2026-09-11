/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:21:11 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/10 14:49:02 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>

class Fixed 
{

    private :
        int _raw_bits;
        static const int _fractional_bits = 8;
    
    public :
    
    Fixed(void);
    Fixed(const Fixed &b);
    Fixed &operator=(const Fixed &b);
    ~Fixed(void);
    int getRawBits( void ) const;
    void setRawBits( int const raw);
};

#endif
