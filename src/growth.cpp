/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:30 by aautin            #+#    #+#             */
/*   Updated: 2024/12/21 17:29:00 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

#include "growth.hpp"

void	grow_towards_target(Map& map, std::queue<std::pair<size_t, size_t> > & path)
{
	(void) map;
	(void) path;
	return;
}

void	grow_where_possible(Map& map)
{
	for (size_t x = 0; x < map.get_width(); ++x) {
		for (size_t y = 0; y < map.get_height(); ++y) {
			try {
				if (map.get_cell(x, y).get_owner() == MYSELF) {
					size_t const coords[4][2] = { 
						{x - 1, y}, {x + 1, y},
						{x, y - 1}, {x, y + 1}
					};
					for (size_t i = 0; i < 4; ++i) {
						Cell& it = map.get_cell(coords[i][0], coords[i][1]);
						if (it.get_owner() == NO_OWNER && it.get_type() == NO_TYPE) {
							grow(map, coords[i][0], coords[i][1], BASIC);
							return ;
						}
					}
				}
			}
			catch (std::out_of_range) {}
		}
	}
}

void	grow(Map& map, size_t x, size_t y, e_type type)
{
	Cell cell(type, MYSELF, NO_DIRECTION);
	map.set_cell(cell, x, y);

	Stock& my_stock = map.get_stock(MYSELF);
	my_stock.set_protein_a(my_stock.get_protein(PROTEIN_A) - 1);
}
