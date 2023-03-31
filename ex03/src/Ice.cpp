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
	std::cout << EMO_ICE_CUBE << " def." << "\t";
	return ;
}

Ice::Ice(Ice const &other)
{
	std::cout << EMO_ICE_CUBE << " copy ";
	*this = other;
	return ;
}

Ice::~Ice(void)
{
	std::cout << COL_RED << EMO_MINUS << " ice  destr. ";
	std::cout << COL_RES;
	return ;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << " = ice ";
	this->_type = rhs.getType();
	return (*this);
}

/* returns a new instance of the same type */
AMateria	*Ice::clone(void) const
{
	std::cout << EMO_ICE_CUBE << " ice clone ";
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << COL_YEL << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << COL_RES << std::endl;
	return ;
}

