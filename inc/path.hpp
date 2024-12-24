/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:12:34 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 18:48:38 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define UNREACHED	-1
#define TARGET		-2

#include <stack>
#include <utility>

#include "Map.hpp"

typedef std::pair<size_t, size_t> coords_t;

bool	is_path_valid(Map& map, std::stack<coords_t> path);
void	print_path(std::stack<coords_t> path);
void	fill_path(int** grid_layer, std::stack<coords_t>& path,
					size_t target_x, size_t target_y, int laps_index);
int		init_path(Map& map, std::stack<coords_t>& path);
