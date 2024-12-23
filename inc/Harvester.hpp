/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harvester.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:50:08 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 22:16:06 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define MEALS_NB_MAX 3

#include <cstddef>

class Harvester
{
	public:
		//Constructors-Destructors
		Harvester(size_t x, size_t y);
		~Harvester();

		//Overloads
		Harvester	operator=(Harvester const& other);

		//Getters
		size_t	get_x() const;
		size_t	get_y() const;

		//Meals
		void	eat_meal();
		bool	can_eat() const;

	private:
		size_t const	_x;
		size_t const	_y;
		size_t			_meals_number;
};
