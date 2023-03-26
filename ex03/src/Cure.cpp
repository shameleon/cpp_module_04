/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:20:04 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:20:17 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Cure.hpp"

Cure::Cure(void):AMateria("Cure")
{
	std::cout << EMO_BLUE_HEART << " (Cure def. constr.) ";
	return ;
}

Cure::Cure(Cure const	&other)
{
	std::cout << EMO_BLUE_HEART << " (Cure copy constructor) ";
	*this = other;
	return ;
}

Cure::~Cure(void)
{
	std::cout << COL_RED << EMO_MINUS << " (Cure destructor) ";
	std::cout << COL_RES;
	return ;
}

Cure			&Cure::operator=(Cure const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_BLUE_HEART << " (Cure copy assignment operator) ";
	this->_type =rhs.getType();
	return (*this);
}

/* 	return (new Cure()); */
AMateria		*Cure::clone(void) const
{
	std::cout << EMO_MINUS << " (Cure::clone)";
	return (new Cure());
}

void			Cure::use(ICharacter &target)
{
	std::cout << " * Heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}