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
	std::cout << EMO_CAT << " (Cat default constructor): created a unamed Cat";
	std::cout << EMO_CAT2 << " type was created." << std::endl;
	return ;
}


Cat::Cat(Cat const	&other)
{
	// this->_brain = new Brain();
	// this->_brain = new Brain(*other._brain);
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

/*
this->brain = other.brain; // shallow copy
*this->brain = *other.brain; // deep copy
this->_brain
*/
Cat		&Cat::operator=(Cat const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout  << EMO_CAT  << " (Cat copy assignment operator): ";
	//this->_name = rhs.getName();
	std::cout << " Cat was updated to another " << rhs.getType();
	std::cout << "'s attributes";
	std::cout << ", name and ideas." << std::endl;
	Animal::operator=(rhs);
	this->_brain = new Brain(*rhs._brain);
	// *this->_brain = *rhs.getBrain();
	return (*this);
}

Brain			*Cat::getBrain(void) const
{
	return (this->_brain);
}

/* Overriding makeSound() */
void		Cat::makeSound(void) const
{
	std::cout << EMO_CAT <<  " (Cat): " << this->Animal::_type;
	std::cout << " is Meowing ! "  << EMO_CAT2;
	std::cout << " Meeeow meeeeeeeeooooooooow !!! " << std::endl;
	return ;
}



