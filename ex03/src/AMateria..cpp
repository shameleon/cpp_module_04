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

AMateria::AMateria(void):_type("type undefined")
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
	if (this == &rhs)
		return (*this);
	std::cout << EMO_WRENCH << " (AMateria copy assignment operator) ";
	this->_type =rhs.getType();
	return (*this);
}

std::string	const	&AMateria::getType(void) const
{
	return ;
}

AMateria			&AMateria::clone(void) const
{
	std::cout << EMO_MINUS << " (AMateria::clone)";
	return ;
}

std::ostream	&operator<<(std::ostream& oss, AMateria const &rhs)
{
	oss << EMO_OPEN_BOOK << &rhs << " : " << rhs.getType() << std::endl;
	return oss;
}
