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

#include "../inc/AAnimal.hpp"
#include "../inc/Brain.hpp"

Brain::Brain(void)
{
	std::cout << EMO_THOUGHT<< " (Brain default constructor): a Brain was created. ";
	std::cout << std::endl;
	for (int i = 0; i < _size; i++)
		this->_ideas[i] = EMO_STAR;
	return ;
}

/*	*this = other */
Brain::Brain(Brain const &other)
{
	std::cout << EMO_THOUGHT << "(Brain copy constructor): brain cloned ";
	std::cout << std::endl;
	for (int i = 0; i < _size; i++)
		this->_ideas[i] = other.getIdea(i);
	return ;
}

Brain::~Brain(void)
{
	std::cout <<  EMO_THOUGHT << COL_RED << " (Brain destructor)";
	std::cout << COL_RES  << std::endl;
	return ;
}

Brain			&Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << " (Brain copy assignment operator): ";
	std::cout << " Brain was updated and copied another Brain ideas.";
	std::cout << std::endl;
	for (int i = 0; i < _size; i++)
		this->_ideas[i] = rhs.getIdea(i);
	return (*this);
}

std::string		Brain::getIdea(int const index) const
{
	if (index >= 0 && index < _size)
		return this->_ideas[index];
	return "";
}

void			Brain::setIdea(std::string const idea, int const index)
{
	if (index >= 0 && index < _size)
		this->_ideas[index] = idea;
	return ;
}

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Brain const &rhs)
{
	for (int i = 0; i < 20; i++)
		oss << rhs.getIdea(i);
	oss << std::endl;
	return oss;
}