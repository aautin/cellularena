/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/28 19:26:31 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Map.hpp"
#include "near.h"

//Constructors-Destructors
Map::Map(size_t width, size_t height)
: _width(width), _height(height), _stocks{Stock(), Stock()}, _target_type(NO_TYPE)
{
	_grid = new Cell*[width];
	for (size_t x = 0; x < width; ++x)
		_grid[x] = new Cell[height];
}

Map::~Map()
{
	for (size_t x = 0; x < _width; ++x)
		delete _grid[x];
	delete _grid;
}
//-


//Setters
void	Map::set_cell(Cell cell, size_t x, size_t y)
{
	if (x >= _width || y >= _height)
		throw std::out_of_range("");
	_grid[x][y] = cell;
}

void	Map::set_target(std::stack<coords> target, e_type type)
{
	_target = target;
	_target_type = type;
}
//-


//Getters
size_t	Map::get_width() const { return _width; }

size_t	Map::get_height() const { return _height; }

Cell&	Map::get_cell(size_t x, size_t y) const
{
	if (x < _width && y < _height)
		return _grid[x][y];
	throw std::out_of_range("");
}

Stock&	Map::get_stock(e_owner index) { return _stocks[index]; }

std::stack<coords>	Map::get_target() { return _target; }

e_type				Map::get_target_type() { return _target_type; }
//-


//Update
void	Map::update_grid()
{
	size_t cells_nb;
	std::cin >> cells_nb; std::cin.ignore();

	for (size_t i = 0; i < cells_nb; i++) {
		int x, y, owner, organ_id, organ_parent_id, organ_root_id;
		std::string type, organ_dir;

		std::cin >> x >> y >> type >> owner >> organ_id
			>> organ_dir >> organ_parent_id >> organ_root_id; std::cin.ignore();

		try {
			set_cell(Cell(type, static_cast<e_owner>(owner), organ_dir, organ_id), x, y);
		} catch (...) {}
	}
}

void	Map::update_stocks()
{
	size_t a, b, c, d;

	std::cin >> a >> b >> c >> d; std::cin.ignore();
	get_stock(MYSELF).set_proteins(a, b, c, d);

	std::cin >> a >> b >> c >> d; std::cin.ignore();
	get_stock(OPPONENT).set_proteins(a, b, c, d);
}

void	Map::update_generators()
{
	std::vector<Generator>::iterator it;
	for (it = _generators.begin(); it != _generators.end();) {
		try {
			Cell& cell = get_cell(it->get_x(), it->get_y());
			if (!Cell::is_protein(cell) || !is_still_in_use(*it))
				it = _generators.erase(it);
			else
				++it;
		} catch (...) { it = _generators.erase(it); }
	}
}
//-


//Generator
void	Map::add_generator(size_t x, size_t y, e_type type)
{
	_generators.push_back(Generator(x, y, type));

	Stock&	stock = _stocks[MYSELF];
	switch (static_cast<size_t>(_generators.back().get_type())) {
		case A:
			stock.set_protein(A, stock.get_protein(A) + 1);
			break;
		case B:
			stock.set_protein(B, stock.get_protein(B) + 1);
			break;
		case C:
			stock.set_protein(C, stock.get_protein(C) + 1);
			break;
		case D:
			stock.set_protein(D, stock.get_protein(D) + 1);
			break;
	}
}

bool	Map::is_generator(size_t x, size_t y) const
{
	std::vector<Generator>::const_iterator it;
	for (it = _generators.begin(); it != _generators.end(); ++it) {
		if (it->get_x() == x && it->get_y() == y)
			return true;
	}
	return false;
}

bool	Map::is_still_in_use(Generator const& it) const
{
	e_direction reverse_dirs[DIRECTIONS_NB] = {EAST, WEST, SOUTH, NORTH};

	for (size_t i = 0; i < 4; ++i) {
		size_t nearx = it.get_x() + near_x[i], neary = it.get_y() + near_y[i];
		try {
			Cell& cell = get_cell(nearx, neary);
			if (cell.get_owner() == MYSELF && cell.get_type() == HARVESTER
				&& cell.get_direction() == reverse_dirs[i])
				return true;
		} catch (...) {}
	}
	return false;
}
//-
