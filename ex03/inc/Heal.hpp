/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heal.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:16:48 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:16:53 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAL_HPP
# define HEAL_HPP

# include "../inc/AMateria.hpp"

class	Heal: public AMateria
{
	public:
		Heal(void);
		Heal(Heal const &other);
		virtual ~Heal(void);

		Heal	&operator=(Heal const &rhs);
		
		Heal	*clone(void);
};

#endif

/* https://github.com/99x/emojicpp/blob/master/emoji.h */
