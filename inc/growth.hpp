/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:13:07 by aautin            #+#    #+#             */
/*   Updated: 2024/12/27 16:06:19 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

#include "Map.hpp"

typedef std::pair<size_t, size_t> coords_t;


//Conditions
bool	can_grow(Stock const& stock);
bool	can_grow_basic(Stock const& stock);
bool	can_grow_harvester(Stock const& stock);
bool	can_grow_tentacle(Stock const& stock);

//Utils
size_t	get_closest_id(Map& map, size_t x, size_t y, e_owner owner);

//Grow
void	grow_towards_protein(Map& map, std::stack<coords_t> & path);
void	grow_where_possible(Map& map);
void	grow(Map& map, Cell const& cell, size_t x, size_t y);
