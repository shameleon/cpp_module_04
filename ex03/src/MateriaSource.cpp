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
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
	std::cout << " { MateriaSource default constr. } " << std::endl;
	return;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = other;
	std::cout << " { MateriaSource copy constr. } ";
	return;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_source[i] != NULL)
			delete this->_source[i];
	std::cout << " { MateriaSource destructor (delete)} ";
	return;
}

// new ?
MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] != NULL)
		{
			delete this->_source[i];
			if (rhs._source[i] != NULL)
				this->_source[i] = rhs._source[i]->clone();
			else
				this->_source[i] = NULL;
		}
	}
	std::cout << " {MateriaSource copy assignement} ";
	return *this;
}

void			MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] == NULL)
		{
			this->_source[i] = m;
			std::cout << " {MateriaSource[" << i << "] learned ";
			std::cout << m->getType() << "} " << std::endl;
			return ;
		}
	}
	std::cout << " {MateriaSource full} ";
	return ;
}

AMateria		*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] != NULL)
		{
			if (this->_source[i]->getType() == type && type != "")
			{
				std::cout << " {MateriaSource[" << i << "] created} ";
				std::cout << this->_source[i]->getType() << " ";
				return this->_source[i]->clone();
			}
		}
	}
	return NULL;
}

/*
std::ostream	&operator<<(std::ostream &oss, MateriaSource const &rhs)
{
	for (int i = 0; i < 4; i++)
		oss << rhs._source[i];
	oss << std::endl;
	return oss;
}
*/
