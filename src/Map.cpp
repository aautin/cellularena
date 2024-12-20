/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/21 16:44:56 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "Map.hpp"

//Constructors-Destructors
Map::Map(size_t width, size_t height)
: _grid_width(width), _grid_height(height), _stocks{Stock(), Stock()}
{
	_grid = new Cell*[width];
	for (size_t i = 0; i < width; ++i)
		_grid[i] = new Cell[height];
}

Map::~Map()
{
	for (size_t i = 0; i < _grid_width; ++i)
		delete _grid[i];
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
	throw std::out_of_range(NULL);
}

Stock&	Map::get_stock(e_owner index) { return _stocks[index]; }
//-


//Setters
void	Map::set_cell(Cell& cell, size_t x, size_t y)
{
	if (x >= 0 && x < _grid_width
		&& y >= 0 && y < _grid_height)
		_grid[x][y] = cell;
	throw std::out_of_range(NULL);
}
//-
