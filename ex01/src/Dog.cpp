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
	this->_brain = new Brain();
	std::cout << EMO_DOG << " (Dog default constructor): created a Dog ";
	std::cout << EMO_DOG2 << std::endl;
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
	delete this->_brain;
	std::cout << COL_RED << EMO_DOG << " (Dog destructor): RIP little";
	std::cout << this->Animal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

Dog		&Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_DOG << " (Dog copy assignment operator): ";
	std::cout << " Dog was updated to another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	Animal::operator=(rhs);
	this->_brain = new Brain(*rhs._brain);
	return (*this);
}

Brain		*Dog::getBrain(void) const
{
	return (this->_brain);
}

/* Overriding makeSound() */
void		Dog::makeSound(void) const
{
	std::cout << EMO_DOG << " (Dog): " << this->Animal::_type;
	std::cout << " is Barking ! " << EMO_DOG2;
	std::cout << " WOOF WOOF !!!! " << std::endl;
	return ;
}
