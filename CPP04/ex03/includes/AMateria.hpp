/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:00:33 by ymoumene          #+#    #+#             */
/*   Updated: 2026/06/27 17:00:48 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria();
		AMateria(const AMateria &src);
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &src);
		static void 	destroy_all_materias();
		static void		add_materia(AMateria *temp);
		static void		remove_materia(AMateria *temp);
		std::string ft_get_type(void);
};

struct MateriaNode
{
	AMateria	*materia;
	MateriaNode	*next;
};

struct Materia_list
{
	MateriaNode	*head;
	MateriaNode	*tail;
	int			count;
};

#endif
