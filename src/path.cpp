/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:10:56 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 03:37:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "growth.hpp"
#include "path.hpp"

int	init_target_path(Map& map, std::stack<std::pair<size_t, size_t> >& path)
{
	int** grid_layer = map.new_grid_layer<int>(UNREACHED);

	for (size_t x = 0; x < map.get_width(); ++x) {
		for (size_t y = 0; y < map.get_height(); ++y) {
			Cell& cell = map.get_cell(x, y);
			if (cell.get_owner() == MYSELF)
				grid_layer[x][y] = 0;
		}
	}

	size_t	laps_index = 1;
	bool	still_growing = true;
	while (still_growing && laps_index < map.get_stock(MYSELF).get_protein(PROTEIN_A)) {
		still_growing = false;
		for (size_t x = 0; x < map.get_width(); ++x) {
			for (size_t y = 0; y < map.get_height(); ++y) {
				try {
					if (grid_layer[x][y] == laps_index - 1) {
						for (size_t i = 0; i < 4; ++i) {
							Cell& cell = cell = map.get_cell(x + nearby[i][0],
															y + nearby[i][1]);
							if (grid_layer[x + nearby[i][0]][y + nearby[i][1]] == UNREACHED
								&& cell.get_owner() == NO_OWNER) {
								if (cell.get_type() == A) {
									// To be continued...
									// here build the std::stack path in reverse order
									// through the grid_layer
									map.delete_grid_layer<int>(grid_layer);
									return true;
								}
								else if (cell.get_type() != WALL) {
									grid_layer[x + nearby[i][0]][y + nearby[i][1]] = laps_index;
									still_growing = true;
								}	
							}
						}
					}
				} catch (std::out_of_range) { std::cerr << "out_of_range" << std::endl; }
			}
		}
		laps_index++;
	}

	map.delete_grid_layer<int>(grid_layer);
	return false;
}
