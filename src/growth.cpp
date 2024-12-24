/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:30 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 17:18:29 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <stdexcept>

#include "growth.hpp"

static size_t	get_closest_id(Map& map, size_t x, size_t y, e_owner owner)
{
	for (size_t i = 0; i < 4; ++i) {
		try {
			if (map.get_cell(x + near_x[i], y + near_y[i]).get_owner() == owner)
				return map.get_cell(x + near_x[i], y + near_y[i]).get_organ_id();
		} catch (...) {}
	}
	return NO_ID;
}

static bool	should_set_harvester(Stock const& stock, size_t path_size)
{
	return path_size == 2 && stock.get_protein(C) && stock.get_protein(D);
}

void	grow_towards_target(Map& map, std::stack<std::pair<size_t, size_t> > & path)
{
	std::pair<size_t, size_t> next = path.top();
	path.pop();

	if (should_set_harvester(map.get_stock(MYSELF), path.size())) {
		std::pair<size_t, size_t> target = path.top();
		e_direction dir = Cell::coords_to_direction(
			target.first - next.first, target.second - next.second);

		Cell harvester(HARVESTER, MYSELF, dir, get_closest_id(map, next.first, next.second, MYSELF));
		grow(map, harvester, next.first, next.second);

		e_type target_type = map.get_cell(target.first, target.second).get_type();
		map.add_generator(target.first, target.second, target_type);

		path.pop();
		return;
	}

	Cell cell(BASIC, MYSELF, NORTH, get_closest_id(map, next.first, next.second, MYSELF));
	grow(map, cell, next.first, next.second);
}

void	grow_where_possible(Map& map)
{
	for (size_t x = 0; x < map.get_width(); ++x) {
		for (size_t y = 0; y < map.get_height(); ++y) {
			try {
				if (map.get_cell(x, y).get_owner() != MYSELF)
					continue;
				for (size_t i = 0; i < 4; ++i) {
					Cell& it = map.get_cell(x + near_x[i], y + near_y[i]);
					if (it.get_owner() == NO_OWNER && it.get_type() != WALL) {
						x += near_x[i];
						y += near_y[i];
						Cell cell(BASIC, MYSELF, NORTH, get_closest_id(map, x, y, MYSELF));
						grow(map, cell, x, y);
						return ;
					}
				}
			} catch (...) {}
		}
	}
	std::cout << "WAIT" << std::endl;
}

static void	apply_grow_on_stock(Stock& stock, Cell const& old_cell, Cell const& new_cell)
{
	switch (static_cast<size_t>(old_cell.get_type())) {
		case A:
			stock.set_protein(A, stock.get_protein(A) + 3);
			break;
		case B:
			stock.set_protein(B, stock.get_protein(B) + 3);
			break;
		case C:
			stock.set_protein(C, stock.get_protein(C) + 3);
			break;
		case D:
			stock.set_protein(D, stock.get_protein(D) + 3);
			break;
	}

	switch (static_cast<size_t>(new_cell.get_type())) {
		case BASIC:
			stock.set_protein(A, stock.get_protein(A) - 1);
			break;
		case HARVESTER:
			stock.set_protein(C, stock.get_protein(C) - 1);
			stock.set_protein(D, stock.get_protein(D) - 1);
			break;
	}
}

void	grow(Map& map, Cell const& cell, size_t x, size_t y)
{
	try {
		apply_grow_on_stock(map.get_stock(MYSELF), map.get_cell(x, y), cell);

		if (map.is_generator(x, y))
			map.pop_generator(x, y);

		map.set_cell(cell, x, y);
		std::cout << "GROW "
			<< cell.get_organ_id() << " " << x << " " << y << " "
			<< cell.type_itos(cell.get_type()) << " "
			<< cell.direction_itos(cell.get_direction()) << " "
			<< std::endl;

	} catch (...) {}
}
