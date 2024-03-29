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
	if (MateriaSource::verbose)
		std::cout << " MSource default constr. " << std::endl;
	return;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	if (this == &other)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] != NULL)
			delete this->_source[i];
		if (other._source[i] != NULL)
			this->_source[i] = other._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
	if (MateriaSource::verbose)
		std::cout << " MSource copy constr. ";
	return;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_source[i] != NULL)
			delete this->_source[i];
	if (MateriaSource::verbose)
		std::cout <<  EMO_MINUS << " MSource destruction" << std::endl;
	return;
}

// new ?
MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] != NULL)
			delete this->_source[i];
		if (rhs._source[i] != NULL)
			this->_source[i] = rhs._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
	if (MateriaSource::verbose)
		std::cout << " MSource copy assignement ";
	return *this;
}

/* learns and stores up to 4 new materials, not necessarily unique materials.
When _source is full, it deletes incoming AMateria parameter and declares _source full */
void			MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] == NULL)
		{
			this->_source[i] = m;
			if (MateriaSource::verbose)
			{
				std::cout << " MSource[" << i << "] learned ";
				std::cout << m->getType() << std::endl;
			}
			return ;
		}
	}
	delete m;
	if (MateriaSource::verbose)
		std::cout << " {MSource is full} " << std::endl;
	return ;
}

/* 	returns a new Materia copied from previously learned Materias that are stored in _source
	type of the returned MAteria is pecified by the parameter 'type' 
	Returns NULL if type is unknown to _source */
AMateria		*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] && this->_source[i]->getType() == type)
		{
			if (MateriaSource::verbose)
			{
				std::cout << " MSource[" << i << "] = ";
				std::cout << this->_source[i]->getType() << " " << std::endl;
			}
			return this->_source[i]->clone();
		}
	}
	if (MateriaSource::verbose)
		std::cout << " MSource could not create unknown Materia " << std::endl;
	return NULL;
}

/* initialize static */
bool			MateriaSource::verbose = false;

/*
•learnMateria(AMateria*)
	Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
	plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
	maximum. Ces dernières ne sont pas forcément uniques.
•createMateria(std::string const &)
	Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
	ment par la MateriaSource et dont le type est le même que celui passé en para-
	mètre. Retourne 0 si le type est inconnu.
En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.

*/