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
	std::cout << EMO_CAT << " (Cat default constructor): created an unamed Cat";
	std::cout << " and named it " << this->_name << std::endl;
	return ;
}

Cat::Cat(std::string const name):Animal("Cat")
{
	this->_name = name;
	std::cout << EMO_CAT << " (Cat parametric constructor): a newly created Cat named ";
	std::cout << this->_name << " ! " << std::endl;
	return ;
}

/* *this = other; */
Cat::Cat(Cat const	&other):Animal(other)
{
	//this->_type = other.getType();
	//this->_name = other.getName();
	*this = other;
	std::cout << EMO_CAT << " (Cat copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << COL_RED << EMO_CAT << " (Cat destructor): RIP ";
	std::cout << this->_name << " " <<this->Animal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

Cat		&Cat::operator=(Cat const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_CAT << " (Cat copy assignment operator): ";
	std::cout << this->_name << " was updated to " << rhs.getName();
	std::cout << "'s attributes " << std::endl;
	//Animal::operator=(rhs);
	this->_type = rhs.getType();
	this->_name = rhs.getName();
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
	std::cout << EMO_CAT <<  " (Cat): " << this->Animal::_type;
	std::cout << " named " << this->_name << " is Meowing ! ";
	std::cout << " Meeeow meow meeeeeeeeooooooooow !!! " << std::endl;
	return ;
}
