/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:17:00 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/24 09:17:06 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "../inc/AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &other);
		virtual ~Ice(void);

		Ice		&operator=(Ice const &rhs);

		Ice		*clone(void) override;
		void	use(ICharacter &target);
};

#endif

