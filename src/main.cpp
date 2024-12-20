/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 18:55:56 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <pair>
#include <vector>

#include "Cell.hpp"
#include "Map.hpp"
#include "Stock.hpp"

/**
 * Grow and multiply your organisms to end up larger than your opponent.
 **/

static void	update_map_grid(Map &myMap)
{
	size_t cells_nb;
	std::cin >> cells_nb; std::cin.ignore();

	for (size_t i = 0; i < cells_nb; i++) {
		int x, y, owner, organ_id, organ_parent_id, organ_root_id;
		std::string type, organ_dir;

		std::cin >> x >> y >> type >> owner >> organ_id
			>> organ_dir >> organ_parent_id >> organ_root_id; std::cin.ignore();

		Cell it(type, owner, organ_dir);
		myMap.set_cell(it, x, y);
	}
}

static void	update_map_stocks(Map &myMap)
{
	for (size_t i = 0; i < STOCKS_NB; ++i) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d; std::cin.ignore();

		Stock& stock = myMap.get_stock(static_cast<e_owner>(i));
		stock.set_proteins(a, b, c, d);
	}
}

void	print_stocks(Stock const& player, Stock const& boss)
{
	std::cerr << "Player:"
		<< player.get_protein(PROTEIN_A) << boss.get_protein(PROTEIN_B)
		<< player.get_protein(PROTEIN_C) << boss.get_protein(PROTEIN_D) << std::endl;

	std::cerr << "Boss:"
		<< boss.get_protein(PROTEIN_A) << boss.get_protein(PROTEIN_B)
		<< boss.get_protein(PROTEIN_C) << boss.get_protein(PROTEIN_D) << std::endl;
}

int	init_target(Map& myMap, std::vector<std::pair<size_t, size_t> > & shortest_path)
{
	// BFS here and stock shortest path
}

void	go_to_target(Map& myMap, std::stack<std::pair<size_t, size_t> > & shortest_path)
{
	// apply next move to the target
	// update myMap locally
}

int main()
{
	int map_width, map_height;
	std::cin >> map_width >> map_height; std::cin.ignore();

	Map myMap(map_width, map_height);

	std::vector<std::pair<size_t, size_t> >	target_path;

	while (1) {

		update_map_grid(myMap);
		update_map_stocks(myMap);
		print_stocks(myMap.get_stock(PLAYER), myMap.get_stock(BOSS));

		int required_actions_nb;
		std::cin >> required_actions_nb; std::cin.ignore();
		std::cout << required_actions_nb << std::endl;
		for (int i = 0; i < required_actions_nb; i++) {
			if (target_path.empty() && !init_target(myMap, target_path))
				std::cout << "WAIT" << std::endl;
			else
				go_to_target(myMap, target_path);
		}
    }
}