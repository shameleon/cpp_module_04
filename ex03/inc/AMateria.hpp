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
# define EMO_FREE "\U0001F193"
# define EMO_BLACK_SQ "\U00002B1B"
# define EMO_BLUE_HEART "\U0001F496" // "\U0001F499"
# define EMO_ICE_CUBE "\U0001F4A0"
# define EMO_NO_GOOD "\U0001F645"
# define EMO_SPY "\U0001F575"

# include <iostream>
# include <iomanip>
# include "../inc/ICharacter.hpp"

/*  used forward declaration in the header files 
to get around the circular dependencies*/
class	ICharacter;

class	AMateria
{
	protected:
		std::string			_type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const	&other);
		virtual ~AMateria(void);

		AMateria			&operator=(AMateria const &rhs);

		std::string	const	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

		static bool			verbose;
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, AMateria const &rhs);

#endif


/*
Abstrat class AMateria : 
	cannot be instanciated. but ca
	can be declared through a pointer

function clone : pure virtual function. Override in derived class(es)
*/
