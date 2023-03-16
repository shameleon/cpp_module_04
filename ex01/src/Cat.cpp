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
	this->_brain = new Brain();
	std::cout << ">(Cat default constructor): a kitten with default name ";
	std::cout << this->_name << "." << std::endl;
	return ;
}

Cat::Cat(std::string const name):Animal("Cat")
{
	this->_name = name;
	this->_brain = new Brain();
	std::cout << ">(Cat parametric constructor): a new Cat named ";
	std::cout << this->_name << " ! " << std::endl;
	return ;
}

Cat::Cat(Cat const	&other)
{
	this->_brain = new Brain();
	*this = other;
	std::cout << ">(Cat copy constructor): a clone of " << other.getType();
	std::cout << " type was created." << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << COL_RED << ">(Cat destructor): RIP little ";
	std::cout << this->_name << " " <<this->Animal::_type  << " ! " << COL_RES  << std::endl;
	return ;
}

/*
this->brain = other.brain; // shallow copy
*this->brain = *other.brain; // deep copy
*/
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
	this->_name = rhs.getName();
	std::cout << this->_name << " was updated to " << rhs.getName();
	std::cout << "'s attributes";
	// *this->_brain = *rhs.getBrain();
	std::cout << ", name and ideas." << std::endl;
	return (*this);
}

std::string		Cat::getName(void) const
{
	return this->_name;
}

Brain			*Cat::getBrain(void) const
{
	return this->_brain;
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

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Cat const &rhs)
{
	oss << rhs.getType() << " name: " << rhs.getName();
	// std::cout << " Brain: " << rhs.getBrain() << std::endl;
	return oss;
}

