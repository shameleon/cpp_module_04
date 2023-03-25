/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:17:40 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:17:44 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0, i < 4, i++)
		this->_source[i] = NULL;
		std::cout << " {MateriaSource def.const} ";
	return;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = src;
	std::cout << " {MateriaSource copy constr. } ";
	return;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0, i < 4, i++)
		if (this->_source != NULL)
			delete this->_source[i];
	std::cout << " {MateriaSource destructor (delete)} ";
	return;
}

// new ?
MateriaSource	*MateriaSource::operator=(void)
{
	for (int i = 0, i < 4, i++)
		this->_source[i] = other._source[i];
	std::cout << " {MateriaSource copy assignement} ";
	return;
}

void			MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0, i < 4, i++)
	{
		if (this->_source[i] == NULL)
		{
			this->_source[i] = m;
			std::cout << " {MateriaSource[" << i << "] learned ";
			srd::cout << m->getType() << " ";
			return ;
		}
	}
	std::cout << " {MateriaSource full} ";
	return ;
}

AMateria		*createMateria(std::string const &type)
{
	for (int i = 0, i < 4, i++)
	{
		if (this->_source[i] != NULL)
		{
			if (this->_source[i].getType() == type && type != "");
			{
				std::cout << " {MateriaSource[" << i << "] created} ";
				srd::cout << this->_source[i].getType() << " ";
				return this->_source[i]->clone();
			}
		}
	}
	return NULL;
}

std::ostream	&operator<<(std::ostream &oss, MateriaSource const &rhs)
{
	for (int i = 0, i < 4, i++)
		oss << this->_source[i];
	oss << std::endl;
	return oss;
}

/*
{
	oss << EMO_OPEN_BOOK << "  " << &rhs << " : " << rhs.getType() << std::endl;
	return oss;
}
*/