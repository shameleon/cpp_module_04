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
	this->_name = "WrongKitty";
	std::cout << "> (Wrong Cat default constructor): created an unamed Wrong Cat";
	std::cout << " and named it " << this->_name << std::endl;
	return ;
}

WrongCat::WrongCat(std::string const name):WrongAnimal("WrongCat")
{
	this->_name = name;
	std::cout << "> (WrongCat parametric constructor): a newly created WrongCat named ";
	std::cout << this->_name << " ! " << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const	&other):WrongAnimal(other)
{
	*this = other;
	std::cout << "> (WrongCat copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << COL_RED << "> (WrongCat default destructor): RIP little ";
	std::cout << this->_name << this->WrongAnimal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

WrongCat		&WrongCat::operator=(WrongCat const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "> (WrongCat copy assignment operator): ";
	std::cout << this->_name << " was updated to " << rhs.getName();
	std::cout << "'s attributes " << std::endl;
	WrongAnimal::operator=(rhs);
	this->_name = rhs.getName();
	return (*this);
}

std::string		WrongCat::getName(void) const
{
	return this->_name;
}

/* Overriding makeSound() */
void		WrongCat::makeSound(void) const
{
	std::cout << "> (WrongCat): " << this->WrongAnimal::_type;
	std::cout << " named " << this->_name << " is Wrongly Meowing ! ";
	std::cout << std::endl;
	return ;
}
