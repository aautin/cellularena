/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 16:02:26 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Cell&	Map::get_cell(size_t x, size_t y) const { return _grid[x][y]; }

Stock&	Map::get_stock(t_stock index) { return _stocks[index]; }
//-


//Setters
void	Map::set_cell(Cell& cell, size_t x, size_t y)
{
	_grid[x][y] = cell;
}
//-
