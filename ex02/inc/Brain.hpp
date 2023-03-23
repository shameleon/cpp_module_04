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

# define EMO_STAR "\U00002B50"

# include "../inc/AAnimal.hpp"

class	Brain
{
	private:
		static const int	_size = 100;
		std::string			_ideas[_size];

	public:
		Brain(void);
		Brain(Brain const &other);
		~Brain(void);

		Brain				&operator=(Brain const &rhs);

		std::string			getIdea(int const index) const;
		void				setIdea(std::string const idea, int const index);
};

/* * * * *  stream operator * * * * */
std::ostream	&operator<<(std::ostream &oss, Brain const &rhs);

#endif
