/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria..cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:19:42 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:19:47 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(void):_type("")
{
	std::cout << EMO_WRENCH << " (AMateria def. constr.) ";
	return ;
}

AMateria::AMateria(std::string const &type):_type(type)
{
	std::cout << EMO_WRENCH << " (AMateria param. constr.) ";
	return ;
}

AMateria::AMateria(AMateria const	&other)
{
	std::cout << EMO_WRENCH << " (AMateria copy constructor) ";
	*this = other;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << COL_RED << EMO_MINUS << " (AMateria destructor) ";
	std::cout << COL_RES;
	return ;
}

AMateria			&AMateria::operator=(AMateria const &rhs)
{
	if (this->_type == rhs.getType())
		return (*this);
	std::cout << EMO_WRENCH << " (AMateria copy assignment operator) ";
	this->_type =rhs.getType();
	return (*this);
}

std::string	const	&AMateria::getType(void) const
{
	return this->_type;
}

AMateria			&AMateria::clone(void) const
{
	return ;
}

std::ostream	&operator<<(std::ostream &oss, AMateria const &rhs)
{
	if (AMateria.getType == "Ice")
		oss << EMO_ICE_CUBE;
	else if (AMateria.getType == "Heal")
		oss << EMO_BLUE_HEART;
	else if (AMateria.getType == NULL)
		oss << EMO_FREE;
	else
		oss << EMO_BLACK_SQ;
	return oss;
}


