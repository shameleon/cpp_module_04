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
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

/* *********************************** */
/*         Ex00 Polymorphism           */
/* *********************************** */

static int		test4(void)
{
	const Animal	*j = new Cat("PrincessUSB");

	std::cout << &j << ": " << j->getName() << " (" << j->getType() << ")\n";
	j->makeSound();
	std::cout << j;
	delete j;
	return 0;
}
static int		test3(void)
{
	const Animal	*j = new Dog("WiFi");
	const Animal	*i = new Cat("PrincessUSB");
	const Animal	*k = new Cat("HelloK");

	std::cout <<  std::endl;
	std::cout << &j << ": " << j->getName() << " (" << j->getType() << ")\n";
	std::cout << &i << ": " << i->getName() << " (" << i->getType() << ")\n";
	std::cout << &k << ": " << k->getName() << " (" << k->getType() << ")\n";
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << COL_GRN << "\n - - - Copying cats : HelloKitty = PrincessUSB - - - \n";
	k = i;
	std::cout << &i << ": " << i->getName() << " (" << i->getType() << ")\n";
	std::cout << &k << ": " << k->getName() << " (" << k->getType() << ")\n";
	k->makeSound();
	std::cout << COL_RES << std::endl;
	std::cout << COL_PUR << "- - - Cat went surgery and extensive DNA editing to become a dog - - - \n";
	std::cout << "- - - PrincessUSB = Wifi - - - \n";
	i = j;
	std::cout << &j << ": " << j->getName() << " (" << j->getType() << ")\n";
	std::cout << &i << ": " << i->getName() << " (" << i->getType() << ")\n";
	i->makeSound();
	std::cout << COL_RES << std::endl;
	delete j;
	delete k;
	return 0;
}

static int		test2(void)
{
	const WrongAnimal	*meta = new WrongAnimal();
	const WrongAnimal	*i = new WrongCat();
	const Animal		*j= new Cat();

	std::cout <<  std::endl;
	std::cout << &meta << ": " << meta->getName() << " (" << meta->getType() << ")\n";
	std::cout << &i << ": " << i->getName() << " (" << i->getType() << ")\n";
	std::cout << &j << ": " << j->getName() << " (" << j->getType() << ")\n";
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
	return 0;
}

static int		test1(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout <<  std::endl;
	std::cout << &meta << ": " << meta->getType() << " " << std::endl;
	std::cout << &j << ": " << j->getType() << " " << std::endl;
	std::cout << &i << ": " << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
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
Process:         a.out [2001]
Load Address:    0x10c7e3000
Identifier:      a.out
Version:         ???
Code Type:       X86-64
Platform:        macOS
Parent Process:  leaks [2000]

Date/Time:       2023-03-14 18:06:23.428 +0100
Launch Time:     2023-03-14 18:06:23.297 +0100
OS Version:      macOS 11.7.4 (20G1120)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         344K
Physical footprint (peak):  344K
----

leaks Report Version: 4.0
Process 2001: 169 nodes malloced for 12 KB
Process 2001: 0 leaks for 0 total leaked bytes.
*/