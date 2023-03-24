/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:55:20 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 10:55:23 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "../inc/Ice.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &other);
		virtual ~Ice(void);

		Ice		&operator=(Ice const &rhs);
		
		Ice		*clone(void);
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, Ice const &rhs);

#endif

/* https://github.com/99x/emojicpp/blob/master/emoji.h */