/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:21 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:24 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(void):_type("type undefined")
{
	std::cout << EMO_WRENCH << " (AAnimal default constructor): a default AAnimal was created. ";
	std::cout << "it is a " << this->_type << std::endl;
	return ;
}

AAnimal::AAnimal(std::string const type):_type(type)
{
	std::cout << EMO_WRENCH << " (AAnimal parametric constructor): a new AAnimal was created. ";
	std::cout << "it is a " << this->_type << " ! " << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const	&other)
{
	std::cout << EMO_WRENCH << " (AAnimal copy constructor): a clone of " << this->getType();
	std::cout << " type was created." << std::endl;
	*this = other;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << COL_RED << EMO_MINUS << " (AAnimal destructor): RIP little ";
	std::cout << this->_type << " ! " << COL_RES  << std::endl;
	return ;
}

AAnimal		&AAnimal::operator=(AAnimal const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_WRENCH << " (AAnimal copy assignment operator): ";
	std::cout << this->_type << " was updated and copied another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	this->_type =rhs.getType();
	return (*this);
}

std::string		AAnimal::getType(void) const
{
	return this->_type;
}

void			AAnimal::makeSound(void) const
{
	std::cout << EMO_MINUS << " (AAnimal Makes Sound): undefined sound";
	std::cout << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream& oss, AAnimal const &rhs)
{
	oss << EMO_OPEN_BOOK << "  " << &rhs << " : " << rhs.getType() << std::endl;
	return oss;
}

/*
virtual : dynamic resolution for function call - runtime polymorphism
method = virtual member-function 
virtual destructor : guarantees that the object of derived class
destructed properly. Maintains the hierarchy of call destructors
from child clas object.
*/