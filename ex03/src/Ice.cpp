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

# include "../inc/AMateria.hpp"

Ice::Ice(void):AMateria("Ice")
{
	std::cout << EMO_ICE_CUBE << " (Ice def. constr.) ";
	return ;
}

Ice::Ice(std::string const &type):AMateria(type)
{
	std::cout << EMO_ICE_CUBE << " (Ice param. constr.) ";
	return ;
}

Ice::Ice(Ice const	&other)
{
	std::cout << EMO_ICE_CUBE << " (Ice copy constructor) ";
	*this = other;
	return ;
}

Ice::~Ice(void)
{
	std::cout << COL_RED << EMO_MINUS << " (Ice destructor) ";
	std::cout << COL_RES;
	return ;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_ICE_CUBE << " (Ice copy assignment operator) ";
	this->_type =rhs.getType();
	return (*this);
}

Ice			&Ice::clone(void) const
{
	std::cout << EMO_MINUS << " (Ice::clone)";
	return (new Ice(*this));
}

void	use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target->getName() << " *" << std::endl;
	return ;
}

