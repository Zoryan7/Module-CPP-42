/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:46:32 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/30 15:48:47 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"


int main(void)
{
    Data data;
    data.type = "Example";
    data.age = 25;
    data.favorite_letter = 'A';
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data: " << raw << std::endl;
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized data: " << deserialized->type << ", " << deserialized->age << ", " << deserialized->favorite_letter << std::endl;
    return (0);
}