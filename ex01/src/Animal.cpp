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

Animal::Animal(void):_type("type undefined")
{
	std::cout << EMO_WRENCH << " (Animal default constructor): a default Animal was created. ";
	std::cout << "it is a " << this->_type << std::endl;
	return ;
}

Animal::Animal(std::string const type):_type(type)
{
	std::cout << EMO_WRENCH << " (Animal parametric constructor): a new Animal was created. ";
	std::cout << "it is a " << this->_type << " ! " << std::endl;
	return ;
}

Animal::Animal(Animal const	&other)
{
	std::cout << EMO_WRENCH << " (Animal copy constructor): a clone of " << this->getType();
	std::cout << " type was created." << std::endl;
	*this = other;
	return ;
}

Animal::~Animal(void)
{
	std::cout << COL_RED << EMO_MINUS << " (Animal destructor): RIP little ";
	std::cout << this->_type << " ! " << COL_RES  << std::endl;
	return ;
}

Animal		&Animal::operator=(Animal const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_WRENCH << " (Animal copy assignment operator): ";
	std::cout << this->_type << " was updated and copied another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

std::string		Animal::getType(void) const
{
	return this->_type;
}

void			Animal::makeSound(void) const
{
	std::cout << EMO_MINUS << " (Animal Makes Sound): undefined sound";
	std::cout << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream& oss, Animal const &rhs)
{
	oss << EMO_OPEN_BOOK << "  " << &rhs << " : " << rhs.getType() << std::endl;
	return oss;
}
