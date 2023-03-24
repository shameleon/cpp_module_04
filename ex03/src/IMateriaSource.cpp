/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:21:04 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:21:08 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# define COL_RED "\033[0;31m"
# define COL_GRN "\033[0;32m"
# define COL_YEL "\033[0;33m"
# define COL_BLU "\033[0;34m"
# define COL_PUR "\033[0;35m"
# define COL_INV_YEL "\033[7;93m"
# define COL_CYA "\033[0;36m"
# define COL_RES "\033[0m"

# include <iostream>
# include <iomanip>
# include "../inc/AMateria.hpp"

class	AMateria;

class	IMateriaSource
{
	public:
		virtual				~IMateriaSource(void) {}
		virtual void		learn(AMateria*)= 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, ICharacter const &rhs);

#endif


/*
•learnMateria(AMateria*)
	Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
	plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
	maximum. Ces dernières ne sont pas forcément uniques.
•createMateria(std::string const &)
	Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
	ment par la MateriaSource et dont le type est le même que celui passé en para-
	mètre. Retourne 0 si le type est inconnu.
En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.
12

*/
