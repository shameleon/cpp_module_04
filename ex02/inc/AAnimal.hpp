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

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

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
# include "../inc/Brain.hpp"

class	AAnimal
{
	protected:
		std::string		_type;

	public:
		AAnimal(void);
		AAnimal(std::string const	type);
		AAnimal(AAnimal const	&other);
		virtual ~AAnimal(void);

		AAnimal			&operator=(AAnimal const &rhs);

		std::string		getType(void) const;

		virtual void	makeSound(void) const = 0;

};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, AAnimal const &rhs);

#endif

/*
	AAnimal   : abstract class 
	makeSound : pure virtual function. 
				function override in derived class(es)
	
	Abstract class cannot be instanciated. only throught pointers or references.
	Tests :
	Animal	mypet;							   // [KO]
	Animal  *my_pet = new Dog("Rantanplan");   // [OK]
*/
