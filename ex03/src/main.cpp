/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:21:15 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:21:21 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"
#include "../inc/IMateriaSource.hpp"
#include "../inc/MateriaSource.hpp"

/* ********************************************** */
/*  Ex03        Interfaces                        */
/* ********************************************** */

/* Character stream operator      OK              */
/* MateriaSource stream operator  not implemented */

/* copying instances */
static int		test6(void)
{
	MateriaSource	*src1 = new MateriaSource();

	src1->learnMateria(new Cure());
	MateriaSource	*src2 = new MateriaSource();
	*src2 = *src1;
	std::cout << std::endl;

	AMateria		*tmp1;
	std::cout << std::endl;
	tmp1 = src1->createMateria("cure");
	if (tmp1)
		delete tmp1;

	AMateria		*tmp2;
	tmp2 = src2->createMateria("cure");
	if (tmp2)
		delete tmp2;
	std::cout << std::endl;
	delete src1;
	delete src2;
	return 0;
}

/* conditional jump */
static int		test5(void)
{
	Character		me = Character("me");
	//Character		*bob = new Character(me);
	Character		*mike = new Character("Mike");
	
	*mike = me;

	//delete bob;
	delete mike;
	return 0;
}

/* learn, create and equip to full then unequip */
static void		test4(void)
{
	IMateriaSource	*src = new MateriaSource();
	ICharacter		*me = new Character("me");
	AMateria		*tmp;

	std::cout << std::endl;
	src->learnMateria(new Ice());
	for (int i = 0; i < 5; i++)
		src->learnMateria(new Cure());

	std::cout << COL_CYA << std::endl;
	tmp = src->createMateria("water");
	std::cout << COL_RES << std::endl;
	for (int i = 0; i < 3; i++)
	{
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
	}

	AMateria		*at_floor = NULL;

	std::cout << *me;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		int	slot = 1;
		at_floor = me->getItem(slot);
		me->unequip(slot);
		if (at_floor)
			delete at_floor;
		std::cout << *me;
	}
	std::cout  << std::endl;
	delete me;
	delete src;
	std::cout << std::endl;
	return ;
}

/* AMateria derived classes */
static void		test3(void)
{
	AMateria		*ice_bolt = new Ice();
	AMateria		*antidote = new Cure();
	
	std::cout << std::endl;
	AMateria		*antidote2 = antidote->clone();;
	std::cout << std::endl;

	ICharacter		*toto = new Character("Tonia");
	std::cout << *toto << std::endl;
	antidote2->use(*toto);
	std::cout << std::endl;

	delete antidote2;
	delete ice_bolt;
	delete antidote;
	delete toto;
	return ;
}

/* learning Materia */
static void		test2(void)
{
	MateriaSource	*machine = new MateriaSource();

	std::cout << std::endl;
	for (int j = 0; j < 3; j++)
	{
		machine->learnMateria(new Ice());
		machine->learnMateria(new Cure());
	}
	std::cout << std::endl;
	delete machine;
	return ;
}

/* test from the subject pdf file */
/* verbose set to true */
static int		test1(void)
{
	IMateriaSource 	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter		*me = new Character("me");
	AMateria		*tmp;

	std::cout << *me;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << *me;
	
	ICharacter		*bob = new Character("bob");

	std::cout << std::endl;
	me->use(0, *bob);
	std::cout << *me;

	me->use(1, *bob);
	std::cout << *me;

	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}

/* test from the ex03 subject */
static int		test0(void)
{
	IMateriaSource 	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter		*me = new Character("me");

	AMateria		*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter		*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}

int				main(int argc, char **argv)
{
	if (argc == 1)
	{
		test0();
		std::cout << "\n>>>\t\t" << COL_YEL << "$ ./a.out verbose" << COL_RES;
		std::cout << "\tto run all tests\t<<<" << std::endl;
		return 0;
	}
	if (argv[1] != NULL)
		std::cout << std::endl << std::endl;
	Character::verbose = true;
	AMateria::verbose = true;
	MateriaSource::verbose = true;
	std::cout << COL_GRN << "\t\t verbose mode" << COL_RES << std::endl;
	std::cout << std::endl;
	std::cout << COL_YEL << "TEST 1" << COL_RES <<  std::endl;
	std::cout << "______________________________________________" << std::endl;
	test1();
	std::cout << std::endl << std::endl;
	std::cout << COL_YEL << "TEST 2" << COL_RES <<  std::endl;
	std::cout << "______________________________________________" << std::endl;
	test2();
	std::cout << std::endl << std::endl;
	std::cout << COL_YEL << "TEST 3" << COL_RES << std::endl;
	std::cout << "______________________________________________" << std::endl;
	test3();
	std::cout << std::endl << std::endl;
	std::cout << COL_YEL << "TEST 4" << COL_RES << std::endl;
	std::cout << "______________________________________________" << std::endl;
	test4();
	std::cout << std::endl << std::endl;
	std::cout << COL_YEL << "TEST 5" << COL_RES << std::endl;
	std::cout << "______________________________________________" << std::endl;
	test5();
	std::cout << std::endl << std::endl;
	std::cout << COL_YEL << "TEST 6" << COL_RES << std::endl;
	std::cout << "______________________________________________" << std::endl;
	test6();
	std::cout << std::endl << std::endl;
	std::cout << "______________________________________________" << std::endl;
	std::cout << COL_RES << std::endl;
	return 0;
}


/*
	Darwin :	leaks -atExit -- ./a.out


	Subject : unequip cannot delete unequiped Materia

	AMateria		*at_floor = NULL;
	
	at_floor = me->getItem(slot);
	me->unequipe(slot);
	if (at_floor)
		delete at_floor;
	std::cout << *me;
*/