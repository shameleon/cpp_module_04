/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:20:28 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:20:34 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Ice.hpp"

Ice::Ice(void):AMateria("ice")
{
	if (AMateria::verbose)
		std::cout << EMO_ICE_CUBE << " def." << "\t\t";
	return ;
}

Ice::Ice(Ice const &other)
{
	if (AMateria::verbose)
		std::cout << EMO_ICE_CUBE << " copy ";
	*this = other;
	return ;
}

Ice::~Ice(void)
{
	if (AMateria::verbose)
		std::cout << COL_RED << EMO_MINUS << " ice " << COL_RES;
	return ;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return (*this);
	if (AMateria::verbose)
		std::cout << " = ice ";
	this->_type = rhs.getType();
	return (*this);
}

/* returns a new instance of the same type */
AMateria	*Ice::clone(void) const
{
	if (AMateria::verbose)
		std::cout << EMO_ICE_CUBE << " ice clone ";
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

