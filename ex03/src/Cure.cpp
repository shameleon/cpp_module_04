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

Cure::Cure(void):AMateria("cure")
{
	std::cout << EMO_BLUE_HEART << " def. " << "\t";
	return ;
}

Cure::Cure(Cure const &other)
{
	std::cout << EMO_BLUE_HEART << " copy ";
	*this = other;
	return ;
}

Cure::~Cure(void)
{
	std::cout << COL_RED << EMO_MINUS << " cure destr. ";
	std::cout << COL_RES;
	return ;
}

Cure			&Cure::operator=(Cure const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << " = cure ";
	this->_type =rhs.getType();
	return (*this);
}

/* 	return (new Cure()); */
AMateria		*Cure::clone(void) const
{
	std::cout << EMO_BLUE_HEART << " cure clone ";
	return (new Cure(*this));
}

void			Cure::use(ICharacter &target)
{
	std::cout << COL_YEL <<  "* Heals " << target.getName();
	std::cout << "'s wounds *" << COL_RES << std::endl;
	return ;
}