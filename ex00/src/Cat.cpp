/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:32 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:34 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void):Animal("Cat")
{
	this->_name = "Kitty";
	std::cout << ">(Cat default constructor): a kitten with no name. ";
	std::cout << "it is named " << this->_name << std::endl;
	return ;
}

Cat::Cat(std::string const name):Animal("Cat")
{
	this->_name = name;
	std::cout << ">(Cat parametric constructor): a new Cat named ";
	std::cout << this->_name << " ! " << std::endl;
	return ;
}

Cat::Cat(Cat const	&other)
{
	this->Animal::_type = other.getType();
	this->_name = other.getName();
	std::cout << ">(Cat copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << COL_RED << ">(Cat default destructor): RIP little ";
	std::cout << this->_name << this->Animal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

Cat		&Cat::operator=(Cat const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << ">(Cat copy assignment operator): ";
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

std::string		Cat::getName(void) const
{
	return this->_name;
}

/* Overriding makeSound() */
/* Method = virtual member fonction */
void		Cat::makeSound(void) const
{
	std::cout << ">(Cat): " << this->Animal::_type;
	std::cout << " named " << this->_name << " is Meowing ! ";
	std::cout << std::endl;
	return ;
}
