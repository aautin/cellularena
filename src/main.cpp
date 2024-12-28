/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/28 18:36:41 by alexandre        ###   ########.fr       */
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

bool	operator<=(std::stack<coords> const& s1, std::stack<coords> const& s2)
{
	std::cerr << "OPERATOR<=" << std::endl;

	if (s2.empty())
		return true;

	return s1.size() <= s2.size();
}

int main()
{
	int map_width, map_height;
	std::cin >> map_width >> map_height; std::cin.ignore();

	std::stack<coords> protein;
	std::stack<coords> tentacle;

	Map map(map_width, map_height);
	Stock& my_stock = map.get_stock(MYSELF);

	while (1) {

		map.update_grid();
		map.update_stocks();
		map.update_generators();
		// print_stocks(map.get_stock(MYSELF), map.get_stock(OPPONENT));

		int required_actions_nb;
		std::cin >> required_actions_nb; std::cin.ignore();
		for (int i = 0; i < required_actions_nb; ++i) {
			std::stack<coords> target = map.get_target();

			if (!is_path_valid(map, target)) {
				init_protein_path(map, protein);
				// init_attack_path(map, tentacle);
				if (!protein.empty() && protein <= tentacle)
					map.set_target(protein, HARVESTER);
				else if (!tentacle.empty())
					map.set_target(tentacle, TENTACLE);
			}
			clear_stack<coords>(protein);
			clear_stack<coords>(tentacle);

			if (!can_grow(my_stock))
				std::cout << "WAIT" << std::endl;
			else if (!map.get_target().empty())
				grow_towards_target(map);
			// else if (!opponent_path.empty() && opponent_path <= protein_path)
			// 	grow_towards_opponent(map, opponent_path);
			else
				grow_where_possible(map);
		}
    }
}
