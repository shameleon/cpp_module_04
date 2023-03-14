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

# include "../inc/WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	protected:
		std::string		_name;

	public:
		WrongCat(void);
		WrongCat(std::string const	name);
		WrongCat(WrongCat const	&other);
		virtual ~WrongCat(void);

		WrongCat	&operator=(WrongCat const &rhs);
		
		std::string		getName(void) const;

		virtual void	makeSound(void) const;
};

#endif
