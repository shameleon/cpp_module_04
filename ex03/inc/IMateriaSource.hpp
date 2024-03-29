/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:17:27 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:17:31 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <iomanip>
# include "../inc/AMateria.hpp"

class	IMateriaSource
{
	public:
		virtual				~IMateriaSource(void) {}
		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif

/*
	IMateriaSource : Interface for class MateriaSource

					 contains only pure virtual functions
					 no implementation, no attributes, no member-functions
*/

