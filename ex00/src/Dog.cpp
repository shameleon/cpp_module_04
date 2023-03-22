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
	this->_name = "Puppy";
	std::cout << EMO_DOG << " (Dog default constructor): created an unamed Dog ";
	std::cout << " and named it " << this->_name << std::endl;
	return ;
}

Dog::Dog(std::string const name):Animal("Dog")
{
	this->_name = name;
	std::cout << EMO_DOG << " (Dog parametric constructor): a newly created Dog named ";
	std::cout << this->_name << " ! " << std::endl;
	return ;
}

Dog::Dog(Dog const	&other):Animal(other)
{
	*this = other;
	std::cout << EMO_DOG << " (Dog copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << COL_RED << EMO_DOG << " (Dog destructor): RIP ";
	std::cout << this->_name << " " << this->Animal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

Dog		&Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_DOG << " (Dog copy assignment operator): ";
	std::cout << this->_name << " was updated to " << rhs.getName();
	std::cout << "'s attributes " << std::endl;
	Animal::operator=(rhs);
	this->_name = rhs.getName();
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
	std::cout << EMO_DOG << " (Dog): " << this->Animal::_type;
	std::cout << " named " << this->_name << " is Barking ! ";
	std::cout << " WOOF WOOF !!!! " << std::endl;
	return ;
}
