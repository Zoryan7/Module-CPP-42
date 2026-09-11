/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:37:58 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/15 15:43:05 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP


#include "AAnimal.hpp"

class Brain
{
    private :
        std::string _ideas[100];
    public :
    
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();
        std::string ft_get_single_ideas(int index);
        void ft_set_single_ideas(std::string idea, int index);
};

#endif