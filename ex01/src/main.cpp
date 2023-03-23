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

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"


/* ********************************************** */
/*  Ex01        shallow copy / deep copy          */
/* ********************************************** */

static int		test3(void)
{
	
	for ()
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
	wrong1.delBrain();
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

/* testing one brain for one cat */
static int		test1(void)
{
	const Animal	*kitten = new Cat();
	const Animal	*puppy = new Dog();

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
______________________________________________
TEST 1 
______________________________________________
const Animal	*kitten = new Cat("Princess USB");
...
delete kitten;
______________________________________________
TEST 2
______________________________________________
Cat		Spirou;
Cat		copycat(Spirou);
Cat		

______________________________________________
TEST 3
______________________________________________

Animal	*shelter[20]
for()
	shelter[i] = new Cat();

for()
	delete shelter[i];

*/