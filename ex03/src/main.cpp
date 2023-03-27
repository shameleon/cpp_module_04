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

static void		test4(void)
{
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

	Character		toto("Tonia");
	std::cout << "toto : " << &toto << std::endl;
	antidote2->use(toto);
	std::cout << "---- END ----" << std::endl;
	delete antidote2;
	delete ice_bolt;
	delete antidote;
	return ;
}

static void		test2(void)
{
	ICharacter		*toto = new Character("Tonia");
	IMateriaSource	*ice_machine = new MateriaSource();

	//ice_machine->learnMateria(ice_bolt);
	std::cout << ice_machine << std::endl;
	//std::cout << toto << std::endl;
	std::cout << "---- END ----" << std::endl;
	delete ice_machine;
	delete toto;
	return ;
}

// static int		test1(void)
// {
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");   // 1 (32 bytes) ROOT LEAK: <Ice 0x7fb7a9c05a30> [32]
// 	// me->equip(tmp);   // SEG FAULT
// 	tmp = src->createMateria("cure");     // NO LEAK 
// 	//me->equip(tmp);     // SEG FAULT
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
//	std::cout << "---- END ----" << std::endl;
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

int				main(void)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << COL_YEL << "TEST 1" << COL_RES << std::endl;
	std::cout << "______________________________________________" << std::endl;
	//test1();
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
	return 0;
}


/*
	delete :  ~MateriaSource  { if -source[i] not NULL 

	leaks -atExit -- ./a.out
*/