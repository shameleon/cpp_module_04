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
#include "../inc/Brain.hpp"

Brain::Brain(void)
{
	std::cout << ">(Brain default constructor): a default Brain was created. ";
	std::cout << std::endl;
	for (int i = 0; i < _size; i++)
		this->_ideas[i] = "_";
	return ;
}

Brain::Brain(Brain const	&other)
{
	std::cout << ">(Brain copy constructor): brain cloned ";
	std::cout << std::endl;
	for (int i = 0; i < _size; i++)
		this->_ideas[i] = other.getIdea(i);
	// 	*this = other;
	return ;
}

Brain::~Brain(void)
{
	std::cout << COL_RED << "->(Brain destructor)";
	std::cout << COL_RES  << std::endl;
	return ;
}

Brain			&Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "->(Brain copy assignment operator): ";
	std::cout << " Brain was updated and copied another Brain ideas.";
	std::cout << std::endl;
	for (int i = 0; i < _size; i++)
		this->_ideas[i] = rhs.getIdea(i);
	// 	std::copy(rhs._ideas, rhs._ideas + 100, this->_ideas);
	return (*this);
}

std::string		Brain::getIdea(int const index) const
{
	if (index > 0 && index < _size)
		return this->_ideas[index];
	return "";
}

std::string		*Brain::getIdea(void) const
{
	return this->_ideas;
}

int		Brain::getBrainSize(void) const
{
	return this->_size;
}

void			Brain::setIdea(std::string const idea, int const index)
{
	if (index > 0 && index < _size)
		this->_ideas[index] = idea;
	return ;
}

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Brain const &rhs)
{
	for (int i = 0; i < rhs.getBrainSize(); i++)
		oss << rhs.getIdea(i);
	return oss;
}