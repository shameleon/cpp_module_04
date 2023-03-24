/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:55:42 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 10:55:46 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# define EMO_CAT "\U0001F431"
# define EMO_CAT2 "\U0001F408"

# include "../inc/AAnimal.hpp"
# include "../inc/Brain.hpp"

class	Cat: public AAnimal
{
	private:
		Brain		*_brain;

	public:
		Cat(void);
		Cat(std::string const	name);
		Cat(Cat const	&other);
		~Cat(void);

		Cat			&operator=(Cat const &rhs);
		
		void		getBrain(void) const;
		void		setBrain(std::string const idea, int const index);

		void		makeSound(void) const override;
};

#endif
