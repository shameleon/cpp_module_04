/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:55:20 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 10:55:23 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define COL_RED "\033[0;31m"
# define COL_RES "\033[0m"

# define EMO_OPEN_BOOK "\U0001F4D6"

# include <iostream>
# include <iomanip>

class	WrongAnimal
{
	protected:
		std::string				_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const type);
		WrongAnimal(WrongAnimal const &other);
		virtual ~WrongAnimal(void);

		WrongAnimal				&operator=(WrongAnimal const &rhs);

		std::string				getType(void) const;
		virtual std::string		getName(void) const;

		virtual void			makeSound(void) const;

};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, WrongAnimal const &rhs);

#endif
