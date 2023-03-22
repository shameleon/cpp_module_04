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

static void			put_animal(Animal const &obj)
{
	std::cout << EMO_OPEN_BOOK << " " << &obj << ": ";
	std::cout << obj.getName();
	std::cout << " (" << obj.getType() << ")" << std::endl;
	return ;
}

static int		test3(void)
{
	Cat			j = Cat("PrincessUSB");
	Cat			*k = new Cat(j);

	std::cout << COL_BLU <<  std::endl;
	put_animal(j);
	j.makeSound();
	std::cout << COL_CYA << std::endl;
	put_animal(*k);
	k->makeSound();
	std::cout << COL_RES << std::endl;
	delete k;
	return 0;
}

static int		test2(void)
{
	const WrongAnimal	*meta = new WrongAnimal();
	const WrongAnimal	*i = new WrongCat();
	const Animal		*j= new Cat();

	std::cout << std::endl;
	std::cout << *meta;
	std::cout << *j;
	std::cout << *i;
	std::cout <<  std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	return 0;
}

static int		test1(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << std::endl;
	std::cout << *meta;
	std::cout << *j;
	std::cout << *i;
	std::cout <<  std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
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
	return 0;
}


/*
	std::cout <<  EMO_OPEN_BOOK  << std::endl;
	std::cout << meta << " : " << meta->getType() << " " << std::endl;
	std::cout << j << " : " << j->getType() << " " << std::endl;
	std::cout << i << " : " << i->getType() << " " << std::endl;
	std::cout <<  std::endl;
*/