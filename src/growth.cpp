/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:30 by aautin            #+#    #+#             */
/*   Updated: 2024/12/22 17:56:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
					// std::cerr << "MINE:" << x << y << std::endl;
					size_t const coords[4][2] = {	{x - 1, y}, {x + 1, y},
													{x, y - 1}, {x, y + 1} };
					for (size_t i = 0; i < 4; ++i) {
						Cell& it = map.get_cell(coords[i][0], coords[i][1]);
						if (it.get_owner() == NO_OWNER && it.get_type() != WALL) {
							// std::cerr << "GROW:" << coords[i][0] << coords[i][1] << std::endl;
							grow(map, coords[i][0], coords[i][1], BASIC);
							return ;
						}
					}
				}
			}
			catch (std::out_of_range) {std::cerr <<  "out_of_range" << std::endl;}
		}
	}
	std::cout << "WAIT" << std::endl;
}

void	grow(Map& map, size_t x, size_t y, e_type type)
{
	Stock& my_stock = map.get_stock(MYSELF);
	Cell cell(type, MYSELF, NO_DIRECTION);

	if (map.get_cell(x, y).get_type() == A)
		my_stock.set_protein_a(my_stock.get_protein(PROTEIN_A) + 3);

	map.set_cell(cell, x, y);
	my_stock.set_protein_a(my_stock.get_protein(PROTEIN_A) - 1);

	std::cout << "GROW 1 " << x << " " << y << " BASIC N" << std::endl;
}
