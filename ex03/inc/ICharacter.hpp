/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:17:13 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:17:17 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <iomanip>
# include "../inc/AMateria.hpp"

class	ICharacter
{
	public:
		virtual						~ICharacter(void){}
		virtual	std::string const	&getName(void) const = 0
		virtual AMateria			*getMateria(int idx) =0;
		virtual void				equip(AMateria *m)= 0;
		virtual void				unequip(int idx)= 0;
		virtual void				use(int idx, ICharacter &target)= 0;
};

#endif

/*
	Interface for class MateriaSource
	
	ICharacter : interface class :
					 contains only pure virtual functions
					 no implementation, no attributes, no member-functions
*/
