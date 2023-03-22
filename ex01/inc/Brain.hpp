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
	private : //protected:
		static const int	_size = 100;
		std::string			_ideas[_size];

	public:
		Brain(void);
		Brain(Brain const &other);
		~Brain(void);

		Brain				&operator=(Brain const &rhs);

		std::string			getIdea(int const index) const;
		std::string			*getIdeas(void) const;
		//int					getBrainSize(void) const;
		void				setIdea(std::string const idea, int const index);
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Brain const &rhs);

#endif
