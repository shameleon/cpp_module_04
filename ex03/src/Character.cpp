/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:19:53 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:19:57 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include "../inc/Character.hpp"


Character::Character(void):_name("Character")
{
	std::cout <<  " < Charact. def.constr > ";
	for (int i = 0; i < 4; i++)
		this->_backpack[i] = NULL;
	return ;
}

Character::Character(std::string const name):_name(name)
{
	std::cout << EMO_NO_GOOD <<  " < Charact. param. constr. for " << this->_name;
	std::cout << " > " << std::endl;
	for (int i = 0; i < 4; i++)
		this->_backpack[i] = NULL;
	return ;
}

Character::Character(Character const &other):_name(other.getName())
{
	std::cout <<  " < Charact. copy constr > ";
	*this = other;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_backpack[i] != NULL)
			delete this->_backpack[i];
	}
	std::cout <<  " < Charact. destruction for ";
	std::cout << this->_name << " > " << std::endl;
	return ;
}

/* *this->_brain = *rhs._brain; */
Character	&Character::operator=(Character const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_backpack[i] != NULL)
			delete this->_backpack[i];
		if (rhs._backpack[i] != NULL)
			this->_backpack[i] = rhs._backpack[i]->clone();
		else
			this->_backpack[i] = NULL;
	}
	std::cout <<  " < Charact. copy assignment operator > ";
	return *this;
}

std::string const	&Character::getName(void) const
{
	return this->_name;
}

AMateria const		&Character::getItem(int idx) const
{
	return *(this->_backpack[idx]);
}

void				Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_backpack[i] == NULL)
		{
			this->_backpack[i] = m;
			std::cout <<  " + 1 " << m->getType() << " to backpack > ";
			return;
		}
		std::cout << " = backpack is full = ";
	}
	return ;
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_backpack[idx] == NULL)
		return ;
	std::cout <<  " - 1 " << this->_backpack[idx]->getType() << " from backpack > ";
	delete this->_backpack[idx];
	for (int i = idx + 1; i < 4 ; i++)
	{
		this->_backpack[i - 1] = this->_backpack[i];
		this->_backpack[i] = NULL;
	}
	return ;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || this->_backpack[idx] == NULL)
		return ;
	this->_backpack[idx]->use(target);
	this->unequip(idx);
	return ;
}

std::ostream		&operator<<(std::ostream &oss, Character const &rhs)
{
	oss << &rhs << " " << EMO_NO_GOOD << " ";
	oss << std::setw(15) << rhs.getName() << " ";
	for (int i = 0; i < 4; i++)
		oss << rhs.getItem(i);
	return oss;
}