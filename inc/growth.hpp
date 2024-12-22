/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:13:07 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 03:25:54 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <queue>

#include "Map.hpp"

size_t const nearby[4][2] = { {-1, 0}, {+1, 0}, {0, -1}, {0, +1} };

void	grow_towards_target(Map& map, std::queue<std::pair<size_t, size_t> > & path);
void	grow(Map& map, size_t x, size_t y, e_type type);
void	grow_where_possible(Map& map);
