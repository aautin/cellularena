/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 17:39:02 by aautin           ###   ########.fr       */
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

static void	update_map_grid(Map &map)
{
	size_t cells_nb;
	std::cin >> cells_nb; std::cin.ignore();

	for (size_t i = 0; i < cells_nb; i++) {
		int x, y, owner, organ_id, organ_parent_id, organ_root_id;
		std::string type, organ_dir;

		std::cin >> x >> y >> type >> owner >> organ_id
			>> organ_dir >> organ_parent_id >> organ_root_id; std::cin.ignore();

		try {
			map.set_cell(Cell(type, static_cast<e_owner>(owner), organ_dir, organ_id), x, y);
		} catch (std::out_of_range) { /* std::cerr << "out_of_range" << std::endl; */}
	}
}

static void	update_map_stocks(Map &map)
{
	size_t a, b, c, d;

	std::cin >> a >> b >> c >> d; std::cin.ignore();
	map.get_stock(MYSELF).set_proteins(a, b, c, d);

	std::cin >> a >> b >> c >> d; std::cin.ignore();
	map.get_stock(OPPONENT).set_proteins(a, b, c, d);
}

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

		update_map_grid(map);
		update_map_stocks(map);
		// print_stocks(map.get_stock(MYSELF), map.get_stock(OPPONENT));

		int required_actions_nb;
		std::cin >> required_actions_nb; std::cin.ignore();
		for (int i = 0; i < required_actions_nb; ++i) {
			if (map.get_stock(MYSELF).get_protein(PROTEIN_A) == 0) {
				std::cout << "WAIT" << std::endl;
			}
			else if (!target_path.empty() || init_target_path(map, target_path))
				grow_towards_target(map, target_path);
			else
				grow_where_possible(map);
		}
    }
}
