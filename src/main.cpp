/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/21 17:28:48 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <queue>

#include "Cell.hpp"
#include "Map.hpp"
#include "Stock.hpp"
#include "growth.hpp"

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

		Cell it(type, static_cast<e_owner>(owner), organ_dir);
		map.set_cell(it, x, y);
	}
}

static void	update_map_stocks(Map &map)
{
	for (size_t i = 0; i < STOCKS_NB; ++i) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d; std::cin.ignore();

		Stock& stock = map.get_stock(static_cast<e_owner>(i));
		stock.set_proteins(a, b, c, d);
	}
}

void	print_stocks(Stock const& MYSELF, Stock const& OPPONENT)
{
	std::cerr << "MYSELF:"
		<< MYSELF.get_protein(PROTEIN_A) << OPPONENT.get_protein(PROTEIN_B)
		<< MYSELF.get_protein(PROTEIN_C) << OPPONENT.get_protein(PROTEIN_D) << std::endl;

	std::cerr << "OPPONENT:"
		<< OPPONENT.get_protein(PROTEIN_A) << OPPONENT.get_protein(PROTEIN_B)
		<< OPPONENT.get_protein(PROTEIN_C) << OPPONENT.get_protein(PROTEIN_D) << std::endl;
}

int	init_target_path(Map& map, std::queue<std::pair<size_t, size_t> > & path)
{
	(void) map;
	(void) path;
	return false;
}

int main()
{
	int map_width, map_height;
	std::cin >> map_width >> map_height; std::cin.ignore();

	Map map(map_width, map_height);

	std::queue<std::pair<size_t, size_t> >	target_path;

	while (1) {

		update_map_grid(map);
		update_map_stocks(map);
		print_stocks(map.get_stock(MYSELF), map.get_stock(OPPONENT));

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