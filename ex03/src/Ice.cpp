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
	std::cout << EMO_ICE_CUBE << " (Ice  def. constr.) " << std::endl;
	return ;
}

Ice::Ice(Ice const	&other)
{
	std::cout << EMO_ICE_CUBE << " (Ice  copy constructor) ";
	*this = other;
	return ;
}

Ice::~Ice(void)
{
	std::cout << COL_RED << EMO_MINUS << " (Ice  destructor) ";
	std::cout << COL_RES;
	return ;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_ICE_CUBE << " (Ice  copy assignment operator) ";
	this->_type = rhs.getType();
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	std::cout << EMO_WRENCH << " ! ice cloned ! ";
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

