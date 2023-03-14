/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:21 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:24 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Brain::Brain(void):_type("undefined type")
{
	std::cout << ">(Brain default constructor): a default Brain was created. ";
	std::cout << std::endl;
	return ;
}

Brain::Brain(std::string const idea)
{
	std::cout << ">(Brain parametric constructor): a new Brain was created. ";
	std::cout << std::endl;
	return ;
}

Brain::Brain(Brain const	&other):_type(other.getType())
{
	std::cout << ">(Brain copy constructor): brain cloned ";
	std::cout << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << COL_RED << "->(Brain destructor)";
	std::cout << this->_type << " ! " << COL_RES  << std::endl;
	return ;
}

Brain		&Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "->(Brain copy assignment operator): ";
	if (this->_type != rhs.getType())
	{
		std::cout << this->_type << " cannot be updated and copied from ";
		std::cout << rhs.getType() << std::endl;
		return (*this);
	}
	std::cout << this->_type << " was updated and copied another " << rhs.getType();
	std::cout << "'s attributes " << std::endl;
	return (*this);
}

std::string		Brain::getType(void) const
{
	return this->_type;
}

void		Brain::makeSound(void) const
{
	std::cout << ">(Brain Makes Sound): wrong sound";
	std::cout << this->_type << std::endl;
	return ;
}

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Brain const &rhs)
{
	oss << rhs.getType() << std::endl;
	return oss;
}
