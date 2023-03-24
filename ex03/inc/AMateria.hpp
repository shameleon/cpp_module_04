/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:15:53 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:16:03 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define COL_RED "\033[0;31m"
# define COL_GRN "\033[0;32m"
# define COL_YEL "\033[0;33m"
# define COL_BLU "\033[0;34m"
# define COL_PUR "\033[0;35m"
# define COL_INV_YEL "\033[7;93m"
# define COL_CYA "\033[0;36m"
# define COL_RES "\033[0m"

# define EMO_MINUS "\U00002796"
# define EMO_WRENCH "\U0001F527"
# define EMO_NO_ENTRY "\U000026D4"
# define EMO_HEAVY_CHECK "\U00002714"
# define EMO_OPEN_BOOK "\U0001F4D6"
# define EMO_THOUGHT "\U0001F4AD"
# define IDEA_FORK "\U0001F374"
# define IDEA_COLLISON "\U0001F4A5"
# define IDEA_RAT "\U0001F400"
# define IDEA_MEAT_ON_BONE "\U0001F356"

# include <iostream>
# include <iomanip>
# include "../inc/.hpp"

class	AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const	&other);
		virtual ~AMateria(void);

		AMateria			&operator=(AMateria const &rhs);

		std::string	const	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, AMateria const &rhs);

#endif


/*
#include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	public:
		virtual ~ICharacter(void) {}
		virtual const std::string&	get_name(void) const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};


lass IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

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
