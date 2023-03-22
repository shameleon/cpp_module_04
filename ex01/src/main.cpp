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
/*         Ex01 shallow copy / deep copy          */
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
	const Animal	*kitten1 = new Cat("Mrs Norris");
	const Animal	*kitten2 = new Cat("Crookshanks");
	//const Animal	*kitten3 = new Cat(kitten1);

	kitten1->makeSound();
	kitten2->makeSound();
	std::cout << "kitten1 : " << &kitten1 << std::endl;
	std::cout << "kitten2 : " << &kitten2 << std::endl;
	//std::cout << "kitten3 : " << kitten3 << std::endl;
	std::cout <<  std::endl;
	//kitten2 = kitten1; malloc: *** error for object 0x7fe31cc05a30: pointer being freed was not allocated
	kitten2->makeSound();
	std::cout << std::endl;
	std::cout << "kitten1 : " << &kitten1 << std::endl;
	std::cout << "kitten2 : " << &kitten2 << std::endl;
	std::cout << std::endl;
	std::cout << kitten1->getType() << std::endl;
	delete kitten1;
	delete kitten2;
	return 0;
}

int				main(void)
{
	std::string		flatline = "_______________________________________________";

	std::cout << std::endl <<  flatline + flatline << std::endl;
	std::cout << "TEST 1 " << std::endl;
	std::cout << flatline + flatline << std::endl;
	test1();
	std::cout << std::endl << std::endl;
	std::cout << "TEST 2 " << std::endl;
	std::cout << flatline + flatline << std::endl;
	test2();
	std::cout << std::endl << std::endl;
	std::cout << "TEST 3 " << std::endl;
	std::cout << flatline + flatline << std::endl;
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