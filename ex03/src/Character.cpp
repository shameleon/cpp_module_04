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
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this->_backpack[i] != NULL)
	// 		delete this->_backpack[i];
	// }
	std::cout <<  " < Charact. destruction for ";
	std::cout << this->_name << " > " << std::endl;
	return ;
}

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

/*
AMateria const		*Character::getItem(int idx) const
{
	return *(this->_backpack[idx]);
}
*/

/*
void	Character::getInventory(void) const
{
	for (int i = 0; i < 4; i++)
		std::cout << " " << &(this->_backpack[i]);
	return ;
}
*/
void				Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_backpack[i] == NULL)
		{
			std::cout <<  " to backpack[" << "] > ";
			this->_backpack[i] = m;   // shallow
			delete m;
			std::cout <<  " + 1 " << m->getType() << " to backpack[" << i << "]" << std::endl;
			return;
		}
	}
	delete m;
	std::cout << " = backpack is full => Materia destroyed " << std::endl;
	return ;
}

/*
void Character::equip(AMateria *m) {
	if (this->_index < Character::ize) {
		this->_backpack[this->_index] = m; // shallow copy
		this->_index+;
	}
}
*/

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_backpack[idx] == NULL)
		return ;
	std::cout <<  " - 1 " << this->_backpack[idx]->getType() << " from backpack > ";
	//delete this->_backpack[idx];
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

std::ostream		&operator<<(std::ostream &oss, ICharacter const &rhs)
{
	oss << " " << EMO_NO_GOOD << " ";
	oss << std::setw(15) << rhs.getName();
	//rhs.getInventory();
	//for (int i = 0; i < 4; i++)
	//	oss << rhs.getItem(i);
	return oss;
}

 /*
void Character::unequip(int idx) {
	if (idx >= 0 && idx < this->_index) {
		delete this->_backpack[idx];
		int i = idx;
		for (; i < this->_nEquiped - 1; i++) {
			this->_inventory[i] = this->_inventory[i + 1];
		}
		this->_inventory[i] = NULL;
		--(this->_nEquiped);
	}
}

Character& Character::operator=(const Character& other) {
	this->_name = other._name;
	this->_nEquiped = other._nEquiped;
	for (int i = 0; i < Character::kInventorySize; i++) {
		//this->_inventory[i] = other._inventory[i]; // shallow copy
		this->_inventory[i] = other._inventory[i]->clone(); // deep copy
	}
	return *this;
}
*/