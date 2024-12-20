/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 13:19:15 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

//Constructors-Destructors
Map::Map(size_t width, size_t height) : _width(width), _height(height)
{
	_grid = new Cell*[width];
	for (size_t i = 0; i < width; ++i)
		_grid[i] = new Cell[height];
}

Map::~Map() { }
//-


//Getters
size_t	Map::get_width() const { return _width; }

size_t	Map::get_height() const { return _height; }

Cell&	Map::get_cell(size_t x, size_t y) const { return _grid[x][y]; }
//-


//Setters
void	Map::set_cell(Cell& cell, size_t x, size_t y)
{
	_grid[x][y] = cell;
}
//-
