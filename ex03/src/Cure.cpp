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
	if (AMateria::verbose)
		std::cout << EMO_BLUE_HEART << " def. " << "\t";
	return ;
}

Cure::Cure(Cure const &other)
{
	if (AMateria::verbose)
		std::cout << EMO_BLUE_HEART << " copy ";
	*this = other;
	return ;
}

Cure::~Cure(void)
{
	if (AMateria::verbose)
		std::cout << COL_RED << EMO_MINUS << " cure " << COL_RES;
	return ;
}

Cure			&Cure::operator=(Cure const &rhs)
{
	if (this == &rhs)
		return (*this);
	if (AMateria::verbose)
		std::cout << " = cure ";
	this->_type = rhs.getType();
	return (*this);
}

/* 	return (new Cure()); */
AMateria		*Cure::clone(void) const
{
	if (AMateria::verbose)
		std::cout << EMO_BLUE_HEART << " cure clone ";
	return (new Cure(*this));
}

void			Cure::use(ICharacter &target)
{
	std::cout << "* Heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}