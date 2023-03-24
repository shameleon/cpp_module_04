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

# define EMO_DOG "\U0001F436"
# define EMO_DOG2 "\U0001F415"

# include "../inc/AAnimal.hpp"
# include "../inc/Brain.hpp"

class	Dog: public AAnimal
{
	private:
		Brain		*_brain;

	public:
		Dog(void);
		Dog(std::string const	name);
		Dog(Dog const	&other);
		~Dog(void);

		Dog			&operator=(Dog const &rhs);

		void		getBrain(void) const;
		void		setBrain(std::string const idea, int const index);

		void		makeSound(void) const override;
};

#endif
