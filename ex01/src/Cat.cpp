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
	this->_brain = new Brain();
	std::cout << EMO_CAT << " (Cat default constructor): created a Cat ";
	std::cout << EMO_CAT2 << std::endl;
	return ;
}

Cat::Cat(Cat const	&other)
{
	this->_brain = new Brain();
	*this = other;
	std::cout << EMO_CAT << " (Cat copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout  << EMO_CAT << COL_RED << " (Cat destructor): RIP little ";
	std::cout << this->Animal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

/* *this->_brain = *rhs._brain; */
Cat		&Cat::operator=(Cat const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout  << EMO_CAT << " (Cat copy assignment operator): ";
	std::cout << " Cat was updated to another " << rhs.getType();
	std::cout << "'s attributes" << std::endl;
	this->_type = rhs.getType();
	delete this->_brain;
	this->_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Cat::getBrain(void) const
{
	std::cout << "\t      " << COL_BLU <<  this->_brain;
	std::cout << " : " << EMO_THOUGHT << " Brain   " << *this->_brain;
	std::cout << COL_RES;
	return ;
}

void	Cat::setBrain(std::string const idea, int const index)
{
	this->_brain->setIdea(idea, index);
	return ;
}

/* Overriding makeSound() */
void	Cat::makeSound(void) const
{
	std::cout << EMO_CAT <<  " (Cat): " << this->Animal::_type;
	std::cout << " is Meowing ! "  << EMO_CAT2;
	std::cout << " Meeeow meeeeeeeeooooooooow !!! " << std::endl;
	return ;
}

/*
this->brain = other.brain; // shallow copy
*this->brain = *other.brain; // deep copy
*/

