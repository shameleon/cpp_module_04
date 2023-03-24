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
	std::cout << EMO_WRENCH << " (AMateria copy constructor): a clone of " << this->getType();
	std::cout << " type was created." << std::endl;
	*this = other;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << COL_RED << EMO_MINUS << " (AMateria destructor): RIP little ";
	std::cout << this->_type << " ! " << COL_RES  << std::endl;
	return ;
}

AMateria		&AMateria::operator=(AMateria const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_WRENCH << " (AMateria copy assignment operator): ";
	std::cout << this->_type << " was updated and copied another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	this->_type =rhs.getType();
	return (*this);
}

std::string		AMateria::getType(void) const
{
	return this->_type;
}

void			AMateria::makeSound(void) const
{
	std::cout << EMO_MINUS << " (AMateria Makes Sound): undefined sound";
	std::cout << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream& oss, AMateria const &rhs)
{
	oss << EMO_OPEN_BOOK << "  " << &rhs << " : " << rhs.getType() << std::endl;
	return oss;
}
