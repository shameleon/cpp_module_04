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


Character::Character(void):_name("N/A")
{
	if (Character::verbose)
		std::cout << EMO_NO_GOOD << " Def. ";
	for (int i = 0; i < 4; i++)
		this->_backpack[i] = NULL;
	return ;
}

Character::Character(std::string const name):_name(name)
{
	if (Character::verbose)
		std::cout << EMO_NO_GOOD <<  " Param. " << this->_name << std::endl;
	for (int i = 0; i < 4; i++)
		this->_backpack[i] = NULL;
	return ;
}

Character::Character(Character const &other):_name(other.getName())
{
	if (Character::verbose)
		std::cout << EMO_NO_GOOD <<  " Copy ";
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
	if (Character::verbose)
		std::cout << EMO_MINUS << " " << EMO_NO_GOOD << " " << this->_name << std::endl;
	return ;
}

//this->_name = rhs.getName();
Character	&Character::operator=(Character const &rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (this->_backpack[i] != NULL)
			delete this->_backpack[i];
		if (rhs._backpack[i] != NULL)
			this->_backpack[i] = rhs._backpack[i]->clone();
		else
			this->_backpack[i] = NULL;
	}
	if (Character::verbose)
		std::cout << EMO_SPY << " copy assignment operator " << std::endl;
	return *this;
}

std::string const	&Character::getName(void) const
{
	return this->_name;
}

AMateria			*Character::getItem(int idx) const
{
	if (idx < 0 || idx >= 4 || this->_backpack[idx] == NULL)
		return NULL;
	return (this->_backpack[idx]);
}

void				Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_backpack[i] == NULL)
		{
			this->_backpack[i] = m;
			if (Character::verbose)
			{
				std::cout << COL_GRN <<  "\nequip : " <<  " + 1 " << m->getType();
				std::cout << " to backpack[" << i << "]" << COL_RES << std::endl;
			}
			return;
		}
	}
	delete m;
	std::cout << COL_PUR << " equip : backpack is full => Materia destroyed " << COL_RES << std::endl;
	return ;
}

/* subject : no delete for unequip , cannot delete this->_backpack[idx]; */
void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_backpack[idx] == NULL)
	{
		if (Character::verbose)
			std::cout << "Backpack slot is either empty or unvailable " << std::endl;
		return ;
	}
	if (Character::verbose)
	{
		std::cout <<  " Unequip : -1 " << this->_backpack[idx]->getType();
		std::cout << " from backpack["  << idx << "]" << std::endl;;
	}
	this->_backpack[idx] = NULL;
	for (int i = idx + 1; i < 4; i++)
		this->_backpack[i - 1] = this->_backpack[i];
	this->_backpack[3] = NULL;
	return ;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_backpack[idx] != NULL)
		this->_backpack[idx]->use(target);
	else 
		std::cout << "could not use item" << std::endl;
	return ;
}

std::ostream		&operator<<(std::ostream &oss, ICharacter const &rhs)
{
	AMateria		*item= NULL;

	oss << std::endl << EMO_SPY << std::setw(10) << rhs.getName() << "  ";
	for (int i = 0; i < 4; i++)
	{
		item = rhs.getItem(i);
		if (item)
			oss << *item << " ";
		else
			oss << EMO_FREE << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return oss;
}

 /* static initialization */
bool			Character::verbose = false;