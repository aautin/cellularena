/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:13:07 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 17:17:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

#include "Map.hpp"

int const near_x[4] = {-1, 1, 0, 0};
int const near_y[4] = { 0, 0,-1, 1};

void	grow_towards_target(Map& map, std::stack<std::pair<size_t, size_t> > & path);
void	grow_where_possible(Map& map);
void	grow(Map& map, Cell const& cell, size_t x, size_t y);
