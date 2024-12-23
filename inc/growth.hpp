/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:13:07 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 17:33:28 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <queue>

#include "Map.hpp"

int const nearby[4][2] = { {-1, 0}, {+1, 0}, {0, -1}, {0, +1} };

void	grow_towards_target(Map& map, std::stack<std::pair<size_t, size_t> > & path);
void	grow(Map& map, size_t x, size_t y, e_type type, size_t organ_id);
void	grow_where_possible(Map& map);
