/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:30 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 22:19:52 by aautin           ###   ########.fr       */
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
			if (map.get_cell(x + nearby[i][0], y + nearby[i][1]).get_owner() == owner)
				return map.get_cell(x + nearby[i][0], y + nearby[i][1]).get_organ_id();
		} catch (std::out_of_range) { /* std::cerr << "out_of_range" << std::endl; */}
	}
	return NO_ID;
}

void	grow_towards_target(Map& map, std::stack<std::pair<size_t, size_t> > & path)
{
	std::pair<size_t, size_t> it = path.top();
	if (path.size() == 2
		&& map.get_stock(MYSELF).get_protein(PROTEIN_C) && map.get_stock(MYSELF).get_protein(PROTEIN_D)) {
		size_t i;
		for (i = 0; i < 4; ++i) {
			try {
				Cell& cell = map.get_cell(it.first + nearby[i][0], it.second + nearby[i][1]);
				if (cell.get_type() == A)
					break;
			} catch (std::out_of_range) { /* std::cerr << "out_of_range" << std::endl; */}
		}
		std::cerr << static_cast<e_direction>(i) << std::endl;
		Cell cell(HARVESTER, MYSELF,
				static_cast<e_direction>(i), get_closest_id(map, it.first, it.second, MYSELF));
		grow(map, cell, it.first, it.second);
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
						Cell& it = map.get_cell(x + nearby[i][0], y + nearby[i][1]);
						if (it.get_owner() == NO_OWNER && it.get_type() != WALL) {
							x = x + nearby[i][0];
							y = y + nearby[i][1];
							Cell cell(BASIC, MYSELF, NORTH, get_closest_id(map, x, y, MYSELF));
							grow(map, cell, x, y);
							return ;
						}
					}
				}
			} catch (std::out_of_range) { /* std::cerr << "out_of_range" << std::endl; */}
		}
	}
	std::cout << "WAIT" << std::endl;
}

void	grow(Map& map, Cell const& cell, size_t x, size_t y)
{
	Stock& my_stock = map.get_stock(MYSELF);

	try {
		if (map.get_cell(x, y).get_type() == A)
			my_stock.set_protein_a(my_stock.get_protein(PROTEIN_A) + 3);

		map.set_cell(cell, x, y);
		my_stock.set_protein_a(my_stock.get_protein(PROTEIN_A) - 1);

		std::cout << "GROW " 
				<< cell.get_organ_id() << " " << x << " " << y << " "
				<< cell.type_itos(cell.get_type()) << " "
				<< cell.direction_itos(cell.get_direction()) << " "
				<< std::endl;
		
	} catch (std::out_of_range) { /* std::cerr << "out_of_range" << std::endl; */}
}
