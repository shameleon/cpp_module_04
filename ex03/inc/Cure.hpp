/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:16:48 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:16:53 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "../inc/AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &other);
		~Cure(void);

		Cure		&operator=(Cure const &rhs);
		
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif

/*
	AMateria	*clone(void) const override;
*/
