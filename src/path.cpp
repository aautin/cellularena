/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:10:56 by aautin            #+#    #+#             */
/*   Updated: 2024/12/27 15:48:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <stack>

#include "Stock.hpp"
#include "path.hpp"
#include "growth.hpp"
#include "near.h"

bool	is_path_valid(Map& map, std::stack<coords_t> path)
{
	if (path.empty())
		return false;

	while (!path.empty()) {
		try {
			Cell& next_cell = map.get_cell(path.top().first, path.top().second);
			if (next_cell.get_owner() != NO_OWNER || next_cell.get_type() == WALL)
				return false;
			path.pop();
		} catch (...) {}
	}
	return true;
}

void	print_path(std::stack<coords_t> path) {
	while (!path.empty()) {
		coords_t& top = path.top();
		std::cerr << top.first << "x" << top.second << "y" << ", " << std::endl;
		path.pop();
	}
}

void	retrace_steps(int** grid_layer, std::stack<coords_t>& path,
		size_t x, size_t y, int laps_index)
{
	path.push(std::make_pair(x, y));

	while (laps_index > 0) {
		for (size_t i = 0; i < 4; ++i) {
			size_t nearx = x + near_x[i], neary = y + near_y[i];
			if (grid_layer[nearx][neary] == laps_index) {

				path.push(std::make_pair(nearx, neary));
				laps_index--;
				break;
			}
		}
	}
}

static void mark_territory(Map& map, int** grid_layer, e_owner owner, int value)
{
	for (size_t x = 0; x < map.get_width(); ++x) {
		for (size_t y = 0; y < map.get_height(); ++y) {
			try {
				if (map.get_cell(x, y).get_owner() == owner)
					grid_layer[x][y] = value;
			} catch (...) {}
		}
	}
}

int	init_protein_path(Map& map, std::stack<coords_t>& path)
{
	int** grid_layer = map.new_grid_layer<int>(UNREACHED);
	mark_territory(map, grid_layer, MYSELF, 0);

	size_t	laps_index = 1;
	bool	still_growing = true;
	size_t	maximal_range = map.get_stock(MYSELF).get_protein(A)
		+ can_grow_harvester(map.get_stock(MYSELF));

	while (still_growing && laps_index <= maximal_range) {
		still_growing = false;
		for (size_t x = 0; x < map.get_width(); ++x) {
			for (size_t y = 0; y < map.get_height(); ++y) {
				try {
					if (grid_layer[x][y] != static_cast<int>(laps_index) - 1)
						continue;
					for (size_t i = 0; i < 4; ++i) {
						size_t nearx = x + near_x[i], neary = y + near_y[i];
						Cell& cell = map.get_cell(nearx, neary);

						if (grid_layer[nearx][neary] != UNREACHED
							|| cell.get_owner() != NO_OWNER)
							continue;
						still_growing = true;

						if (Stock::is_protein(cell) && !map.is_generator(nearx, neary)) {
							retrace_steps(grid_layer, path, nearx, neary, laps_index);
							map.delete_grid_layer<int>(grid_layer);
							return true;
						}
						if (cell.get_type() != WALL)
							grid_layer[nearx][neary] = laps_index;
					}
				} catch (...) {}
			}
		}
		++laps_index;
	}

	map.delete_grid_layer<int>(grid_layer);
	return false;
}
