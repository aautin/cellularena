/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 17:53:37 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Cell.hpp"
#include "Stock.hpp"

class Map
{
	public:
		//Constructors-Destructors
		Map(size_t width, size_t height);
		~Map();

		//Setters
		void	set_cell(Cell cell, size_t x, size_t y);

		//Getters
		size_t	get_width() const;
		size_t	get_height() const;
		Cell&	get_cell(size_t x, size_t y) const;
		Stock&	get_stock(e_owner index);

		//Grid layer
		template <typename Type> Type**	new_grid_layer(Type value) const;
		template <typename Type> void	delete_grid_layer(Type** grid_layer) const;

	private:
		size_t const	_grid_width;
		size_t const	_grid_height;
		Cell**			_grid;

		Stock			_stocks[STOCKS_NB];
};


//Grid layer
template <typename Type>
Type**	Map::new_grid_layer(Type value) const
{
	Type** grid_layer = new Type*[_grid_width];
	for (size_t x = 0; x < _grid_width; ++x) {
		grid_layer[x] = new Type[_grid_height];
		for (size_t y = 0; y < _grid_height; ++y)
			grid_layer[x][y] = value;
	}
	return grid_layer;
}

template <typename Type> void	Map::delete_grid_layer(Type** grid_layer) const
{
	for (size_t x = 0; x < _grid_width; ++x)
		delete grid_layer[x];
	delete grid_layer;
}
//-
