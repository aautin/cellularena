/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:22:11 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 16:13:27 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cell.hpp"
#include "Map.hpp"

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

		Stock& stock = myMap.get_stock(static_cast<t_stock>(i));
		stock.set_protein(A, a);
		stock.set_protein(B, b);
		stock.set_protein(C, c);
		stock.set_protein(D, d);
	}
}

int main()
{
	int map_width, map_height;
	std::cin >> map_width >> map_height; std::cin.ignore();

	Map myMap(map_width, map_height);

	while (1) {

		update_map_grid(myMap);
		update_map_stocks(myMap);

        int required_actions_count; // your number of organisms, output an action for each one in any order
		std::cin >> required_actions_count; std::cin.ignore();
		std::cout << required_actions_count << std::endl;
        for (int i = 0; i < required_actions_count; i++) {
            std::cout << "WAIT" << std::endl;
		}
    }
}