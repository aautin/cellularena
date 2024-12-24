/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 16:34:01 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

void	Map::update_generator(std::vector<Generator>::iterator& it)
{
	Stock&	stock = _stocks[MYSELF];
	switch (static_cast<size_t>(it->get_type())) {
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

void	Map::update_generators()
{
	std::vector<Generator>::iterator it;
	for (it = _generators.begin(); it < _generators.end(); ++it)
		update_generator(it);
}
//-

//Generator
void	Map::add_generator(size_t x, size_t y, e_type type)
{
	_generators.push_back(Generator(x, y, type));
	update_generator(--_generators.end());
}

bool	Map::is_generator(size_t x, size_t y) const
{
	std::vector<Generator>::const_iterator it;
	for (it = _generators.begin(); it < _generators.end(); ++it) {
		if (it->get_x() == x && it->get_y() == y)
			return true;
	}
	return false;
}

void	Map::pop_generator(size_t x, size_t y)
{
	std::vector<Generator>::const_iterator it;
	for (it = _generators.begin(); it < _generators.end(); ++it) {
		if (it->get_x() == x && it->get_y() == y)
			_generators.erase(it);
	}
}
//-
