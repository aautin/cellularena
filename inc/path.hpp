/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:12:34 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 16:00:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define UNREACHED	-1
#define TARGET		-2

#include <stack>
#include <utility>

#include "Map.hpp"

using namespace std;

void	fill_path(int** grid_layer, stack<pair<size_t, size_t> >& path,
					size_t target_x, size_t target_y, int laps_index);
int		init_target_path(Map& map, stack<pair<size_t, size_t> >& path);
