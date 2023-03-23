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
	return 0;
}

/* testing one brain for one cat */
static int		test1(void)
{
	const Animal	*kitten1 = new Cat();
	const Animal	*kitten2 = new Dog();

	std::cout <<  std::endl;
	kitten1->makeSound();
	kitten2->makeSound();
	std::cout <<  std::endl;
	std::cout << "kitten1 : " << *kitten1;
	//kitten1->setBrain("coucou");
	//std::cout << kitten1->getBrain();
	std::cout << "kitten2 : " << *kitten2;
	std::cout <<  std::endl;
	delete kitten1;
	delete kitten2;
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