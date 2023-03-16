/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:40 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:42 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void):Animal("Dog")
{
	this->_name = "Doggie";
	std::cout << ">(Dog default constructor): a Dog with no name. ";
	std::cout << "it is named " << this->_name << std::endl;
	return ;
}

Dog::Dog(std::string const name):Animal("Dog")
{
	this->_name = name;
	std::cout << ">(Dog parametric constructor): a new Dog named ";
	std::cout << this->_name << " ! " << std::endl;
	return ;
}

Dog::Dog(Dog const	&other):Animal("Dog")
{
	this->Animal::_type = other.getType();
	this->_name = other.getName();
	std::cout << ">(Dog copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << COL_RED << ">(Dog destructor): RIP little ";
	std::cout << this->_name << " " << this->Animal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

Dog		&Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << ">(Dog copy assignment operator): ";
	if (this->Animal::_type != rhs.getType())
	{
		std::cout << this->Animal::_type << " cannot be updated and copied from ";
		std::cout << rhs.getType() << std::endl;
		return (*this);
	}
	std::cout << this->_name << " was updated to " << rhs.getName();
	std::cout << "'s attributes " << std::endl;
	return (*this);
}

std::string		Dog::getName(void) const
{
	return this->_name;
}

/* Overriding makeSound() */
/* Method = virtual member fonction */
void		Dog::makeSound(void) const
{
	std::cout << ">(Dog): " << this->Animal::_type;
	std::cout << " named " << this->_name << " is Barking ! ";
	std::cout << std::endl;
	return ;
}
