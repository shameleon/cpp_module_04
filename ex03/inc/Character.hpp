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

class	Character: public ICharacter
{
	private: 
		std::string			_name;
		AMateria			*_backpack[4];

		Character(void);

	public:
		Character(std::string const name);
		Character(Character const &other);
		~Character(void);

		Character			&operator=(Character const &rhs);
		std::string const	&getName(void) const;
		AMateria			*getItem(int idx) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		static bool			verbose;
};

/* * * * *  stream operator * * * * */
std::ostream				&operator<<(std::ostream &oss, ICharacter const &rhs);

#endif

/*
	override; 
*/
