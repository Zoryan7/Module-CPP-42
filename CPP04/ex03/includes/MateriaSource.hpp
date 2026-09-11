/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:48:14 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 17:04:12 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_template[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &src);
		void learnMateria(AMateria*);
       	AMateria* createMateria(std::string const & type);
};

#endif
