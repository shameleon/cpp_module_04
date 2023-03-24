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
	return;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0, i < 4, i++)
		this->_source[i] = other._source[i];
	return;
}

MateriaSource::~MateriaSource(void)
{
	return;
}

MateriaSource	*MateriaSource::operator=(void)
{
	for (int i = 0, i < 4, i++)
		this->_source[i] = other._source[i];
	return;
}

MateriaSource::~MateriaSource(void)
{
	return;
}

void			MateriaSource::learn(AMateria *m)
{
	for (int i = 0, i < 4, i++)
	{
		if (this->_source[i] == NULL)
			break;
	}
	if (this->_source[i] == NULL)
		this->_source[i] = m;
	return;
}

AMateria		*createMateria(std::string const &type)
{

	return;
}

/*

*/