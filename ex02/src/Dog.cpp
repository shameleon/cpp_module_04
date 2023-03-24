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

Dog::Dog(void):AAnimal("Dog")
{
	this->_brain = new Brain();
	std::cout << EMO_DOG << " (Dog default constructor): created a Dog ";
	std::cout << EMO_DOG2 << std::endl;
	return ;
}

Dog::Dog(Dog const	&other):AAnimal(other)
{
	delete this->_brain;
	*this = other;
	std::cout << EMO_DOG << " (Dog copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << COL_RED << EMO_DOG << " (Dog destructor): RIP little";
	std::cout << this->AAnimal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

Dog		&Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_DOG << " (Dog copy assignment operator): ";
	std::cout << " Dog was updated to another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	this->_type = rhs.getType();
	delete this->_brain;
	this->_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Dog::getBrain(void) const
{
	std::cout << "\t      " << COL_BLU <<  this->_brain;
	std::cout << " : " << EMO_THOUGHT << " Brain   " << *this->_brain;
	std::cout << COL_RES;
	return ;
}

void	Dog::setBrain(std::string const idea, int const index)
{
	this->_brain->setIdea(idea, index);
	return ;
}

/* Overriding makeSound() */
void		Dog::makeSound(void) const
{
	std::cout << EMO_DOG << " (Dog): " << this->AAnimal::_type;
	std::cout << " is Barking ! " << EMO_DOG2;
	std::cout << " WOOF WOOF !!!! " << std::endl;
	return ;
}
