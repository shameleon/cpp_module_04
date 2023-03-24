/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:16:28 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:16:35 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "../inc/ICharacter.hpp"


class	Character
{
	private:
		std::string const	_name;
	public:
		Character(void);
		Character(std::string const name);
		Character(Character const &other);
		~Character(void);

		Character			*operator=(Character const &rhs)
		std::string const	&getName(void) const;
		void				equip(AMateria *m)= 0;
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif


/*

*/
