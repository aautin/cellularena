/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:30 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 15:07:45 by aautin           ###   ########.fr       */
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

void	grow_towards_target(Map& map, std::stack<std::pair<size_t, size_t> > & path)
{
	std::pair<size_t, size_t> it = path.top();
	if (path.size() == 2
		&& map.get_stock(MYSELF).get_protein(C)
		&& map.get_stock(MYSELF).get_protein(D)) {
		size_t i;
		for (i = 0; i < 4; ++i) {
			try {
				Cell& cell = map.get_cell(it.first + near_x[i], it.second + near_y[i]);
				if (cell.get_type() == A)
					break;
			} catch (...) {}
		}
		std::cerr << static_cast<e_direction>(i) << std::endl;
		Cell cell(HARVESTER, MYSELF,
				static_cast<e_direction>(i), get_closest_id(map, it.first, it.second, MYSELF));
		grow(map, cell, it.first, it.second);
		map.add_generator(it.first + near_x[i], it.second + near_y[i],
			map.get_cell(it.first + near_x[i], it.second + near_y[i]).get_type());
		path.pop();
	}
	else {
		Cell cell(BASIC, MYSELF, NORTH, get_closest_id(map, it.first, it.second, MYSELF));
		grow(map, cell, it.first, it.second);
	}
	path.pop();
	return;
}

void	grow_where_possible(Map& map)
{
	for (size_t x = 0; x < map.get_width(); ++x) {
		for (size_t y = 0; y < map.get_height(); ++y) {
			try {
				if (map.get_cell(x, y).get_owner() == MYSELF) {
					for (size_t i = 0; i < 4; ++i) {
						Cell& it = map.get_cell(x + near_x[i], y + near_y[i]);
						if (it.get_owner() == NO_OWNER && it.get_type() != WALL) {
							x = x + near_x[i];
							y = y + near_y[i];
							Cell cell(BASIC, MYSELF, NORTH, get_closest_id(map, x, y, MYSELF));
							grow(map, cell, x, y);
							return ;
						}
					}
				}
			} catch (...) {}
		}
	}
	std::cout << "WAIT" << std::endl;
}

void	grow(Map& map, Cell const& cell, size_t x, size_t y)
{
	Stock& my_stock = map.get_stock(MYSELF);

	try {
		switch (static_cast<size_t>(map.get_cell(x, y).get_type())) {
			case A:
				my_stock.set_protein(A, my_stock.get_protein(A) + 3);
				break;
			case B:
				my_stock.set_protein(B, my_stock.get_protein(B) + 3);
				break;
			case C:
				my_stock.set_protein(C, my_stock.get_protein(C) + 3);
				break;
			case D:
				my_stock.set_protein(D, my_stock.get_protein(D) + 3);
				break;
		}

		switch (static_cast<size_t>(cell.get_type())) {
			case BASIC:
				my_stock.set_protein(A, my_stock.get_protein(A) - 1);
				break;
			case HARVESTER:
				my_stock.set_protein(C, my_stock.get_protein(C) - 1);
				my_stock.set_protein(D, my_stock.get_protein(D) - 1);
				break;
		}

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
