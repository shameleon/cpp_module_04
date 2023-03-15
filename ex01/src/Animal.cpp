/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:21 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:24 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal(void):_type("undefined type")
{
	std::cout << ">(Animal default constructor): a default Animal was created. ";
	std::cout << "it is of " << this->_type << std::endl;
	return ;
}

Animal::Animal(std::string const type):_type(type)
{
	std::cout << ">(Animal parametric constructor): a new Animal was created. ";
	std::cout << "it is a " << this->_type << " ! " << std::endl;
	return ;
}

Animal::Animal(Animal const	&other):_type(other.getType())
{
	std::cout << ">(Animal copy constructor): a clone of " << this->getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << COL_RED << "->(Animal destructor): RIP little ";
	std::cout << this->_type << " ! " << COL_RES  << std::endl;
	return ;
}

Animal		&Animal::operator=(Animal const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "->(Animal copy assignment operator): ";
	if (this->_type != rhs.getType())
	{
		std::cout << this->_type << " cannot be updated and copied from ";
		std::cout << rhs.getType() << std::endl;
		return (*this);
	}
	std::cout << this->_type << " was updated and copied another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	return (*this);
}

std::string		Animal::getType(void) const
{
	return this->_type;
}

void		Animal::makeSound(void) const
{
	std::cout << ">(Animal Makes Sound): ";
	std::cout << this->_type << std::endl;
	return ;
}

/* * * * *  stream operator * * * * *
std::ostream	&operator<<(std::ostream &oss, Animal const &rhs)
{
	oss << rhs.getType();
	return oss;
}
*/
