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
		std::string const	_name;
		AMateria			*_backpack[4];

	public:
		Character(void);
		Character(std::string const name);
		Character(Character const &other);
		~Character(void);

		Character			*operator=(Character const &rhs)
		std::string const	&getName(void) const override;
		AMateria			*getMateria(int idx) const override;
		void				equip(AMateria *m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter &target) override;
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Character const &rhs);

#endif

/*

*/
