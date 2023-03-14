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
# define COL_GRN "\033[0;32m"
# define COL_YEL "\033[0;33m"
# define COL_PUR "\033[0;35m"
# define COL_INV_YEL "\033[7;93m"
# define COL_CYA "\033[0;36m"
# define COL_RES "\033[0m"

# include <iostream>
# include <iomanip>

class	WrongAnimal
{
	protected:
		std::string		_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const	type);
		WrongAnimal(WrongAnimal const	&other);
		virtual ~WrongAnimal(void);

		WrongAnimal			&operator=(WrongAnimal const &rhs);

		std::string		getType(void) const;

		virtual void	makeSound(void) const;

};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, WrongAnimal const &rhs);

#endif
