/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   growth.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:13:07 by aautin            #+#    #+#             */
/*   Updated: 2024/12/22 16:31:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <queue>

#include "Map.hpp"

void	grow_towards_target(Map& map, std::queue<std::pair<size_t, size_t> > & path);
void	grow(Map& map, size_t x, size_t y, e_type type);
void	grow_where_possible(Map& map);
