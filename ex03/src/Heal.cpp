/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heal.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:20:04 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:20:17 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/AMateria.hpp"

Heal::Heal(void):AMateria("Heal")
{
	std::cout << EMO_Heal_CUBE << " (Heal def. constr.) ";
	return ;
}

Heal::Heal(std::string const &type):AMateria(type)
{
	std::cout << EMO_Heal_CUBE << " (Heal param. constr.) ";
	return ;
}

Heal::Heal(Heal const	&other)
{
	std::cout << EMO_Heal_CUBE << " (Heal copy constructor) ";
	*this = other;
	return ;
}

Heal::~Heal(void)
{
	std::cout << COL_RED << EMO_MINUS << " (Heal destructor) ";
	std::cout << COL_RES;
	return ;
}

Heal			&Heal::operator=(Heal const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << EMO_Heal_CUBE << " (Heal copy assignment operator) ";
	this->_type =rhs.getType();
	return (*this);
}

Heal			&Heal::clone(void) const
{
	std::cout << EMO_MINUS << " (Heal::clone)";
	return (new Heal(*this));
}

void	use(ICharacter &target)
{
	std::cout << "* heals " << target->getName() << "'s wounds *" << std::endl;
	return ;
}