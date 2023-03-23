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


/* ********************************************** */
/*  Ex01        shallow copy / deep copy          */
/* ********************************************** */

static int		test3(void)
{
	return 0;
}

static int		test2(void)
{
	Cat		kitten1 = Cat();
	Cat		*kitten2 = new Cat(kitten1);
	Animal	*kitten3 = new Cat();

	std::cout <<  std::endl;
	kitten1.setBrain(IDEA_RUN, 0);
	kitten1.setBrain(IDEA_COLLISON, 1);
	kitten1.setBrain(IDEA_RAT, 2);
	kitten1.setBrain(IDEA_MEAT_ON_BONE, 3);
	std::cout << "kitten1 : " << kitten1;
	kitten1.getBrain();
	std::cout << "kitten2 : " << *kitten2;
	kitten2->getBrain();

	*kitten3 = kitten1;
	std::cout << "kitten3 : " << *kitten3;
	kitten2->getBrain();
	std::cout << "kitten3 = kitten 1 (copy)" << std::endl;
	std::cout << "kitten3 : " << *kitten3;
	kitten2->getBrain();
	std::cout <<  std::endl;
	delete kitten2;
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
	std::cout << "puppy : " << *puppy;
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
	return 0;
}

/*
______________________________________________
TEST 1 
______________________________________________
const Animal	*kitten1 = new Cat("Princess USB");

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