/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:55:42 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 10:55:46 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# define EMO_CAT "\U0001F431"
# define EMO_CAT2 "\U0001F408"

# include "../inc/WrongAnimal.hpp"
# include "../inc/Brain.hpp"

class	WrongCat: public WrongAnimal
{
	private:
		Brain		*_brain;

	public:
		WrongCat(void);
		WrongCat(std::string const	name);
		WrongCat(WrongCat const	&other);
		~WrongCat(void);

		WrongCat	&operator=(WrongCat const &rhs);
		
		void		getBrain(void) const;
		void		setBrain(std::string const idea, int const index);

		void		makeSound(void) const;
};

#endif

/*
	void		makeSound(void) const override;
*/