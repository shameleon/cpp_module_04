/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:55:20 by jmouaike          #+#    #+#             */
/*   Updated: 2023/03/14 10:55:23 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "../inc/Animal.hpp"

class	Brain
{
	protected:
		std::string		_ideas[100];

	public:
		Brain(void);
		Brainl(std::string const	idea);
		Brain(Brain const	&other);
		virtual ~Brain(void);

		Brain			&operator=(Brain const &rhs);

};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &o, Brain const &rhs);

#endif
