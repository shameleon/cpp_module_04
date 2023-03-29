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

/* */
static void		test5(void)
{
	ICharacter		*me = new Character("me");

	delete me;
}

/* learn, create and equip to full */
static void		test4(void)
{
	IMateriaSource	*src = new MateriaSource();
	ICharacter		*me = new Character("me");
	AMateria		*tmp;

	std::cout << std::endl;
	src->learnMateria(new Ice());
	for (int i = 0; i < 5; i++)
		src->learnMateria(new Cure());

	std::cout << std::endl;
	tmp = src->createMateria("water");
	for (int i = 0; i < 5; i++)
	{
		tmp = src->createMateria("cure");
		me->equip(tmp);
	}

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << " unequip \t";
		me->unequip(1);
	}
	std::cout << "---- END ----" << std::endl;
	delete me;
	delete src;
	std::cout << "---- END of TESTS ----" << std::endl;
	return ;
}

/* AMateria derived classes */
static void		test3(void)
{
	AMateria		*ice_bolt = new Ice();
	AMateria		*antidote = new Cure();
	
	std::cout << std::endl;
	std::cout << *ice_bolt << std::endl;
	std::cout << *antidote << std::endl;

	AMateria		*antidote2 = antidote->clone();;
	std::cout << std::endl;
	std::cout << *antidote2 << std::endl;
	std::cout << std::endl;

	ICharacter		*toto = new Character("Tonia");
	std::cout << "Character : " << toto << std::endl; // KO
	antidote2->use(*toto);
	std::cout << std::endl;

	std::cout << "---- END ----" << std::endl;
	delete antidote2;
	delete ice_bolt;
	delete antidote;
	delete toto;
	return ;
}

/* tests learning Materia */
static void		test2(void)
{
	MateriaSource	*machine = new MateriaSource();

	std::cout << std::endl;
	for (int j = 0; j < 4; j++)
	{
		machine->learnMateria(new Ice());
		machine->learnMateria(new Cure());
	}
	std::cout << "\n---- END ----" << std::endl;
	delete machine;
	return ;
}

/* test from the subject pdf file */
/* added delete tmp */
static int		test1(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");

	// AMateria* 	tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	
	// ICharacter* bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);

	// std::cout << "---- END ----" << std::endl;
	// delete bob;
	// delete me;
	delete src;
	return 0;
}

int				main(void)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << COL_YEL << "TEST 1" << COL_RES << std::endl;
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
	std::cout << COL_YEL;
	std::cout << "______________________________________________" << std::endl;
	std::cout << COL_RES << std::endl;
	return 0;
}


/*
	leaks -atExit -- ./a.out
*/