/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/27 22:45:58 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <vector>

#include "Cell.hpp"
#include "Generator.hpp"
#include "Stock.hpp"
#include "coords.h"


class Map
{
	public:
		//Constructors-Destructors
		Map(size_t width, size_t height);
		~Map();

		//Setters
		void	set_cell(Cell cell, size_t x, size_t y);
		void	set_target(std::stack<coords> const& target, e_type type);

		//Getters
		size_t				get_width() const;
		size_t				get_height() const;
		Cell&				get_cell(size_t x, size_t y) const;
		Stock&				get_stock(e_owner index);
		std::stack<coords>	get_target();
		e_type				get_target_type();

		//Grid layer
		template <typename Type> Type**	new_grid_layer(Type value) const;
		template <typename Type> void	delete_grid_layer(Type** grid_layer) const;

		//Update
		void	update_grid();
		void	update_stocks();
		void	update_generators();

		//Generator
		void	add_generator(size_t x, size_t y, e_type type);
		bool	is_generator(size_t x, size_t y) const;
		bool	is_still_in_use(Generator const& it) const;

	private:
		size_t const			_width;
		size_t const			_height;
		Cell**					_grid;
		Stock					_stocks[STOCKS_NB];

		std::stack<coords>		_target;
		e_type					_target_type;
		std::vector<Generator>	_generators;
};

//Grid layer
template <typename Type>
Type**	Map::new_grid_layer(Type value) const
{
	Type** grid_layer = new Type*[_width];
	for (size_t x = 0; x < _width; ++x) {
		grid_layer[x] = new Type[_height];
		for (size_t y = 0; y < _height; ++y)
			grid_layer[x][y] = value;
	}
	return grid_layer;
}

template <typename Type> void	Map::delete_grid_layer(Type** grid_layer) const
{
	for (size_t x = 0; x < _width; ++x)
		delete grid_layer[x];
	delete grid_layer;
}
//-
