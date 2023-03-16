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
# include "../inc/Brain.hpp"

class	Cat: public Animal
{
	private:
		Brain			*_brain;

	protected:
		std::string		_name;

	public:
		Cat(void);
		Cat(std::string const	name);
		Cat(Cat const	&other);
		virtual ~Cat(void);

		Cat				&operator=(Cat const &rhs);
		
		std::string		getName(void) const;
		Brain			*getBrain(void) const;

		virtual void	makeSound(void) const;
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Cat const &rhs);

#endif
