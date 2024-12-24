/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 01:41:14 by aautin           ###   ########.fr       */
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
		<< myself.get_protein(PROTEIN_A) << myself.get_protein(PROTEIN_B)
		<< myself.get_protein(PROTEIN_C) << myself.get_protein(PROTEIN_D) << std::endl;

	std::cerr << "OPPONENT:"
		<< opponent.get_protein(PROTEIN_A) << opponent.get_protein(PROTEIN_B)
		<< opponent.get_protein(PROTEIN_C) << opponent.get_protein(PROTEIN_D) << std::endl;
}

int main()
{
	int map_width, map_height;
	std::cin >> map_width >> map_height; std::cin.ignore();

	Map map(map_width, map_height);

	std::stack<std::pair<size_t, size_t> >	target_path;

	while (1) {

		map.update_grid();
		map.update_stocks();
		map.update_generators();
		// print_stocks(map.get_stock(MYSELF), map.get_stock(OPPONENT));

		int required_actions_nb;
		std::cin >> required_actions_nb; std::cin.ignore();
		for (int i = 0; i < required_actions_nb; ++i) {
			if (map.get_stock(MYSELF).get_protein(PROTEIN_A) == 0)
				std::cout << "WAIT" << std::endl;
			else if (!target_path.empty() || init_target_path(map, target_path))
				grow_towards_target(map, target_path);
			else
				grow_where_possible(map);
		}
    }
}
