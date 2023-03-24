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


Character::Character(void):_name("default")
{
	return ;
}

Character::Character(std::string const name):_name(name)
{
	return ;
}

Character::Character(Character const &other):_name(name)
{
	*this = other;
	return ;
}

Character::~Character(void)
{
	return ;
}

Character	*Character::operator=(Character const &rhs)
{
	this->_name = rhs->getName();
	/* *this->_brain = *rhs._brain; */
	return ;
}

std::string const	&getName(void) const
{
	return &(this->_name)
}

void		Character::equip(AMateria *m)
{
	return ;
}

void		Character::unequip(int idx)
{
	return ;
}

void		Character::use(int idx, ICharacter &target)
{
	return ;
}
