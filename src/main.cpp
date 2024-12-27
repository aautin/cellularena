/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/27 15:48:23 by aautin           ###   ########.fr       */
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

void	print_stocks(Stock const& myself, Stock const& opponent)
{
	std::cerr << "MYSELF:"
		<< myself.get_protein(A) << myself.get_protein(B)
		<< myself.get_protein(C) << myself.get_protein(D) << std::endl;

	std::cerr << "OPPONENT:"
		<< opponent.get_protein(A) << opponent.get_protein(B)
		<< opponent.get_protein(C) << opponent.get_protein(D) << std::endl;
}

int main()
{
	int map_width, map_height;
	std::cin >> map_width >> map_height; std::cin.ignore();

	Map map(map_width, map_height);
	std::stack<coords_t> protein_target;
	std::stack<coords_t> attack_path;

	while (1) {

		map.update_grid();
		map.update_stocks();
		map.update_generators();
		// print_stocks(map.get_stock(MYSELF), map.get_stock(OPPONENT));

		int required_actions_nb;
		std::cin >> required_actions_nb; std::cin.ignore();
		for (int i = 0; i < required_actions_nb; ++i) {
			Stock& my_stock = map.get_stock(MYSELF);
			if (!can_grow(my_stock))
				std::cout << "WAIT" << std::endl;
			else if (is_path_valid(map, protein_target) || init_protein_path(map, protein_target))
				grow_towards_target(map, protein_target);
			else
				grow_where_possible(map);			
		}
    }
}
