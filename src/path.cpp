/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:10:56 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 02:02:37 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <stack>

#include "growth.hpp"
#include "path.hpp"

void	print_path(stack<pair<size_t, size_t> > path) {
	while (!path.empty()) {
		pair<size_t, size_t>& top = path.top();
		std::cerr << top.first << "x" << top.second << "y" << ", " << std::endl;
		path.pop();
	}
}

void	fill_path(int** grid_layer, stack<pair<size_t, size_t> >& path,
		size_t x, size_t y, int laps_index)
{
	while (laps_index > 0) {
		for (size_t i = 0; i < 4; ++i) {
			if (grid_layer[x + near_x[i]][y + near_y[i]] == laps_index) {
				x = x + near_x[i];
				y = y + near_y[i];
				
				path.push(make_pair(x, y));
				laps_index--;
				break;
			}
		}
	}
}

int	init_target_path(Map& map, stack<pair<size_t, size_t> >& path)
{
	int** grid_layer = map.new_grid_layer<int>(UNREACHED);

	for (size_t x = 0; x < map.get_width(); ++x) {
		for (size_t y = 0; y < map.get_height(); ++y) {
			try {
				Cell& cell = map.get_cell(x, y);
				if (cell.get_owner() == MYSELF)
					grid_layer[x][y] = 0;
			} catch (...) {}
		}
	}

	size_t	laps_index = 1;
	bool	still_growing = true;
	while (still_growing && laps_index < map.get_stock(MYSELF).get_protein(PROTEIN_A)) {
		still_growing = false;
		for (size_t x = 0; x < map.get_width(); ++x) {
			for (size_t y = 0; y < map.get_height(); ++y) {
				try {
					if (grid_layer[x][y] == static_cast<int>(laps_index) - 1) {
						for (size_t i = 0; i < 4; ++i) {
							Cell& cell = map.get_cell(x + near_x[i],
															y + near_y[i]);
							if (grid_layer[x + near_x[i]][y + near_y[i]] == UNREACHED
								&& cell.get_owner() == NO_OWNER) {
								if (cell.get_type() == A
									&& !map.is_generator(x + near_x[i], y + near_y[i])) {

									path.push(make_pair(x + near_x[i], y + near_y[i]));
									fill_path(grid_layer, path,
										x + near_x[i], y + near_y[i], laps_index - 1);
									map.delete_grid_layer<int>(grid_layer);
									print_path(path);
									return true;
								}
								else if (cell.get_type() != WALL) {
									grid_layer[x + near_x[i]][y + near_y[i]] = laps_index;
									still_growing = true;
								}	
							}
						}
					}
				} catch (...) {}
			}
		}
		laps_index++;
	}

	map.delete_grid_layer<int>(grid_layer);
	return false;
}
