/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:21 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:24 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):_type("undefined type")
{
	std::cout << ">(WrongAnimal default constructor): a default WrongAnimal was created. ";
	std::cout << "it is of " << this->_type << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string const type):_type(type)
{
	std::cout << ">(WrongAnimal parametric constructor): a new WrongAnimal was created. ";
	std::cout << "it is a " << this->_type << " ! " << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const	&other):_type(other.getType())
{
	std::cout << ">(WrongAnimal copy constructor): a clone of " << this->getType();
	std::cout << " type was created." << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << COL_RED << "->(WrongAnimal default destructor): RIP little ";
	std::cout << this->_type << " ! " << COL_RES  << std::endl;
	return ;
}

WrongAnimal		&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "->(WrongAnimal copy assignment operator): ";
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

std::string		WrongAnimal::getType(void) const
{
	return this->_type;
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << ">(WrongAnimal Makes Sound): wrong sound";
	std::cout << this->_type << std::endl;
	return ;
}

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, WrongAnimal const &rhs)
{
	oss << rhs.getType() << std::endl;
	return oss;
}
