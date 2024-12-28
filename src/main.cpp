/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/28 20:01:07 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <utility>

#include "Cell.hpp"
#include "Map.hpp"
#include "Stock.hpp"
#include "growth.hpp"
#include "path.hpp"

/**
 * Grow and multiply your organisms to end up larger than your opponent.
 **/

bool is_harvester_target(Map const& map, Cell const& target, size_t x, size_t y)
{
	return Cell::is_protein(target) && !map.is_generator(x, y);
}
bool is_tentacle_target(Map const& map, Cell const& target, size_t x, size_t y)
{
	(void) map; (void) x; (void) y;
	return target.get_owner() == OPPONENT && target.get_type() != TENTACLE;
}

int main()
{
	int map_width, map_height;
	std::cin >> map_width >> map_height; std::cin.ignore();

	Map map(map_width, map_height);
	Stock& my_stock = map.get_stock(MYSELF);

	while (1) {

		map.update_grid();
		map.update_stocks();
		map.update_generators();

		int required_actions_nb;
		std::cin >> required_actions_nb; std::cin.ignore();
		for (int i = 0; i < required_actions_nb; ++i) {
			std::stack<coords>	target = map.get_target();

			/* Init strategy
				if path not valid:
					if protein accessible:
						set path on it
					if path not set and can grow tentacle
						set path on it
			*/
			if (!is_path_valid(map, target)) {
				std::stack<coords>	new_target;
				e_type				type;

				type = init_path(map, new_target, &is_harvester_target, HARVESTER);
				if (type == NO_TYPE && can_grow_tentacle(my_stock))
					type = init_path(map, target, &is_tentacle_target, TENTACLE);
				map.set_target(target, type);
				clear_stack<coords>(target);
			}

			/* Growth strategy
				HARVESTER pathsize >= 1
				TENTACLE pathsize >= 2
				if pathsize == 2:
					try to put target_type towards target, then clear path
					(tentacle will be possible everytime, not harvester)
			*/
			if (!can_grow(my_stock))
				std::cout << "WAIT" << std::endl;
			else if (!map.get_target().empty())
				grow_towards_target(map);
			else
				grow_where_possible(map);
		}
    }
}
