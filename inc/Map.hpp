/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/25 00:44:22 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "Cell.hpp"
#include "Generator.hpp"
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

		//Update
		void	update_grid();
		void	update_stocks();
		bool	update_generator(std::vector<Generator>::iterator& it);
		void	update_generators();

		//Generator
		void	add_generator(size_t x, size_t y, e_type type);
		bool	is_generator(size_t x, size_t y) const;
		bool	is_generator(std::vector<Generator>::iterator& it) const;
		bool	is_in_use(size_t x, size_t y) const;
		void	pop_generator(size_t x, size_t y);

	private:
		size_t const	_grid_width;
		size_t const	_grid_height;
		Cell**			_grid;
		Stock			_stocks[STOCKS_NB];

		std::vector<Generator>	_generators;
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
