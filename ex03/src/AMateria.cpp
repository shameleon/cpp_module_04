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
	if (AMateria::verbose)
		std::cout << EMO_WRENCH << " AMat. def. ";
	return ;
}

AMateria::AMateria(std::string const &type):_type(type)
{
	if (AMateria::verbose)
		std::cout << EMO_WRENCH  << " AMat. param. ";
	return ;
}

AMateria::AMateria(AMateria const	&other)
{
	if (AMateria::verbose)
		std::cout << EMO_WRENCH  << " AMat. clone ";
	*this = other;
	return ;
}

AMateria::~AMateria(void)
{
	if (AMateria::verbose)
		std::cout << COL_RED << EMO_MINUS << COL_RES << std::endl;
	return ;
}

AMateria			&AMateria::operator=(AMateria const &rhs)
{
	if (this->_type == rhs.getType())
		return (*this);
	if (AMateria::verbose)
		std::cout << EMO_WRENCH << " copy ";
	this->_type = rhs.getType();
	return (*this);
}

std::string	const	&AMateria::getType(void) const
{
	return this->_type;
}

/*
Unimplemented :

AMateria			*AMateria::clone(void) const = 0;
*/

void				AMateria::use(ICharacter &target)
{
	if (this->_type == "ice")
		std::cout << "# shoots an ice bolt at " << target.getName() << " #" << std::endl;
	if (this->_type == "cure")
		std::cout << "# Heals " << target.getName() << "'s wounds #" << std::endl;
	return ;
}

std::ostream		&operator<<(std::ostream &oss, AMateria const &rhs)
{
	if (rhs.getType() == "ice")
		oss << EMO_ICE_CUBE;
	else if (rhs.getType() == "cure")
		oss << EMO_BLUE_HEART;
	else
		oss << EMO_FREE;
	return oss;
}

bool			AMateria::verbose = false;
