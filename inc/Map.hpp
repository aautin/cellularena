/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 13:15:06 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Cell.hpp"

class Map
{
	public:
		Map(size_t width, size_t height);
		~Map();

		//Getters
		size_t	get_width() const;
		size_t	get_height() const;
		Cell&	get_cell(size_t x, size_t y) const;
		//-

		//Setters
		void	set_cell(Cell& cell, size_t x, size_t y);
		//-

	private:
		size_t const	_width;
		size_t const	_height;

		Cell**			_grid;
};

#endif