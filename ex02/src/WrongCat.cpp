/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:32 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:34 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal("WrongCat")
{
	this->_brain = new Brain();
	std::cout << EMO_CAT << " (Wrong Cat default constructor): created an unamed Wrong Cat";
	std::cout << EMO_CAT2 << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const	&other):WrongAnimal(other)
{
	this->_brain = new Brain();
	*this = other;
	std::cout << EMO_CAT << " (WrongCat copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

/* delete this->_brain;  // removed to allow test */
WrongCat::~WrongCat(void)
{
	delete this->_brain;
	std::cout << EMO_CAT << COL_RED << " (WrongCat default destructor): RIP little ";
	std::cout << this->WrongAnimal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_CAT << " (WrongCat copy assignment operator): ";
	std::cout << " WrongCat was updated to another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	this->_type = rhs.getType();
	*this->_brain = *rhs._brain;
	return (*this);
}

void		WrongCat::getBrain(void) const
{
	std::cout << "\t      " << COL_BLU <<  this->_brain;
	std::cout << " : " << EMO_THOUGHT << " Brain   " << *this->_brain;
	std::cout << COL_RES;
	return ;
}

void		WrongCat::setBrain(std::string const idea, int const index)
{
	this->_brain->setIdea(idea, index);
	return ;
}

/* Overriding makeSound() */
void		WrongCat::makeSound(void) const
{
	std::cout <<  EMO_CAT << " (WrongCat): " << this->WrongAnimal::_type;
	std::cout << " is Wrongly Meowing ! "  << EMO_CAT2;
	std::cout << " Moooooooh mooohhh !!! " << std::endl;
	return ;
}
