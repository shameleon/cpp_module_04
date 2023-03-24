/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:17:40 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:17:44 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "../inc/IMateriaSource.hpp"

class	MateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &other);
		~MateriaSource(void);

		MateriaSource	*operator=(MateriaSource const &rhs);
		
		void		learn(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

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
