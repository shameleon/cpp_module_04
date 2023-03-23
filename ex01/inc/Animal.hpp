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

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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
# define IDEA_RUN "\U0001F356"
# define IDEA_COLLISON "\U0001F4A5"
# define IDEA_RAT "\U0001F400"
# define IDEA_MEAT_ON_BONE "\U0001F356"

# include <iostream>
# include <iomanip>
# include "../inc/Brain.hpp"

class	Animal
{
	protected:
		std::string		_type;

	public:
		Animal(void);
		Animal(std::string const	type);
		Animal(Animal const	&other);
		virtual ~Animal(void);

		Animal			&operator=(Animal const &rhs);

		std::string		getType(void) const;

		virtual void	makeSound(void) const;

};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, Animal const &rhs);

#endif
