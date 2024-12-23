/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:13:07 by aautin            #+#    #+#             */
/*   Updated: 2024/12/25 00:46:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

#include "Map.hpp"

typedef std::pair<size_t, size_t> coords_t;

void	grow_towards_target(Map& map, std::stack<coords_t> & path);
void	grow_where_possible(Map& map);
void	grow(Map& map, Cell const& cell, size_t x, size_t y);
