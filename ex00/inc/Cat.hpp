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

# include "../inc/Animal.hpp"

# define EMO_CAT "\U0001F431"
# define EMO_CAT2 "\U0001F408"

class	Cat: public Animal
{
	protected:
		std::string		_name;

	public:
		Cat(void);
		Cat(std::string const	name);
		Cat(Cat const	&other);
		~Cat(void);

		Cat				&operator=(Cat const &rhs);
		
		std::string		getName(void) const;

		void			makeSound(void) const;
};

#endif
