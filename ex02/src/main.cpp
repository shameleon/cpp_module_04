/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:12:00 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 13:12:08 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"


/* ********************************************** */
/*  Ex02        Abstract Class                    */
/* ********************************************** */

static int		test4(void)
{
	AAnimal		*shelter[20];

	for (int i = 0; i < 20; i++)
	{
		shelter[i++] = new Cat();
		shelter[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout << i << " : " << *shelter[i];
		std::cout << std::endl;
	}
	for (int i = 0; i < 20; i++)
	{
		delete shelter[i];
	}
	return 0;
}
static int		test3(void)
{
	WrongCat	wrong1 = WrongCat();
	wrong1.setBrain(EMO_CAT2, 0);
	wrong1.setBrain(IDEA_RAT, 1);
	wrong1.setBrain(EMO_WRENCH, 2);
	std::cout << COL_PUR << std::endl;
	WrongCat	wrong2 = WrongCat(wrong1);
	std::cout << COL_CYA << std::endl;
	WrongCat	*wrong3 = new WrongCat();

	std::cout << COL_RES << std::endl;
	wrong1.setBrain(IDEA_COLLISON, 3);
	wrong1.setBrain(IDEA_FORK, 4);
	wrong1.setBrain(IDEA_MEAT_ON_BONE, 5);
	std::cout << "wrong1 : " << wrong1;
	wrong1.getBrain();
	std::cout << "wrong2 : " << wrong2;
	wrong2.getBrain();
	std::cout << "wrong3 : " << *wrong3;
	wrong3->getBrain();
	std::cout << COL_CYA << std::endl;
	*wrong3 = wrong1;
	std::cout << COL_RES;
	std::cout << "wrong3 : " << *wrong3;
	wrong3->getBrain();
	std::cout <<  std::endl;
	std::cout << "______________________________________________" << std::endl;
	wrong1.setBrain(EMO_STAR, 0);
	wrong1.setBrain(EMO_STAR, 5);
	wrong2.setBrain(EMO_STAR, 2);
	wrong3->setBrain(EMO_STAR, 1);
	wrong3->setBrain(EMO_STAR, 3);
	std::cout << "wrong1 : " << wrong1;
	wrong1.getBrain();
	std::cout << "wrong2 : " << wrong2;
	wrong2.getBrain();
	std::cout << "wrong3 : " << *wrong3;
	wrong3->getBrain();
	delete wrong3;
	return 0;
}

static int		test2(void)
{
	Cat		kitten1 = Cat();
	kitten1.setBrain(EMO_CAT2, 0);
	kitten1.setBrain(IDEA_RAT, 1);
	kitten1.setBrain(EMO_WRENCH, 2);
	std::cout << COL_PUR << std::endl;
	Cat		kitten2 = Cat(kitten1);
	std::cout << COL_CYA << std::endl;
	Cat		*kitten3 = new Cat();

	std::cout << COL_RES << std::endl;
	kitten1.setBrain(IDEA_COLLISON, 3);
	kitten1.setBrain(IDEA_FORK, 4);
	kitten1.setBrain(IDEA_MEAT_ON_BONE, 5);
	std::cout << "kitten1 : " << kitten1;
	kitten1.getBrain();
	std::cout << "kitten2 : " << kitten2;
	kitten2.getBrain();
	std::cout << "kitten3 : " << *kitten3;
	kitten3->getBrain();
	std::cout << COL_CYA << std::endl;
	*kitten3 = kitten1;
	std::cout << COL_RES;
	std::cout << "kitten3 : " << *kitten3;
	kitten3->getBrain();
	std::cout <<  std::endl;
	std::cout << "______________________________________________" << std::endl;
	kitten1.setBrain(EMO_STAR, 0);
	kitten1.setBrain(EMO_STAR, 5);
	kitten2.setBrain(EMO_STAR, 2);
	kitten3->setBrain(EMO_STAR, 1);
	kitten3->setBrain(EMO_STAR, 3);
	std::cout << "kitten1 : " << kitten1;
	kitten1.getBrain();
	std::cout << "kitten2 : " << kitten2;
	kitten2.getBrain();
	std::cout << "kitten3 : " << *kitten3;
	kitten3->getBrain();
	delete kitten3;
	return 0;
}

static int		test1(void)
{
	const AAnimal	*kitten = new Cat();
	const AAnimal	*puppy = new Dog();

	std::cout <<  std::endl;
	kitten->makeSound();
	puppy->makeSound();
	std::cout <<  std::endl;
	std::cout << "kitten : " << *kitten;
	//kitten1->setBrain("coucou");
	//std::cout << kitten1->getBrain();
	std::cout << "puppy  : " << *puppy;
	std::cout <<  std::endl;
	delete kitten;
	delete puppy;
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
	return 0;
}

/*
	valgrind tests : 1[ok] 2[ok] 3[ok] 4[ok]
*/