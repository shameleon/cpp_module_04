/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:55:55 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 10:55:57 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../inc/Animal.hpp"

class	Dog: public Animal
{
	protected:
		std::string		_name;

	public:
		Dog(void);
		Dog(std::string const	name);
		Dog(Dog const	&other);
		virtual ~Dog(void);

		Dog	&operator=(Dog const &rhs);
		
		virtual std::string		getName(void) const;

		virtual void	makeSound(void) const;
};

#endif
