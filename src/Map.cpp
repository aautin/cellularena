/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 02:43:44 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "Map.hpp"

//Constructors-Destructors
Map::Map(size_t width, size_t height)
: _grid_width(width), _grid_height(height), _stocks{Stock(), Stock()}
{
	_grid = new Cell*[width];
	for (size_t x = 0; x < width; ++x)
		_grid[x] = new Cell[height];
}

Map::~Map()
{
	for (size_t x = 0; x < _grid_width; ++x)
		delete _grid[x];
	delete _grid;
}
//-


//Getters
size_t	Map::get_width() const { return _grid_width; }

size_t	Map::get_height() const { return _grid_height; }

Cell&	Map::get_cell(size_t x, size_t y) const
{
	if (x >= 0 && x < _grid_width
		&& y >= 0 && y < _grid_height)
		return _grid[x][y];
	throw std::out_of_range("");
}

Stock&	Map::get_stock(e_owner index) { return _stocks[index]; }
//-


//Setters
void	Map::set_cell(Cell cell, size_t x, size_t y)
{
	if (x >= _grid_width || y >= _grid_height)
		throw std::out_of_range("");
	_grid[x][y] = cell;
}
//-


//Grid layer
template <typename Type>
Type**	Map::new_grid_layer(Type value) const
{
	Type** grid_layer = new Type*[_grid_width];
	for (size_t x = 0; x < _grid_width; ++x) {
		grid_layer[x] = new Type[_grid_height];
		for (size_t y = 0; y < _grid_height; ++y)
			grid_laye[x][y] = value;
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