/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:12:34 by aautin            #+#    #+#             */
/*   Updated: 2024/12/28 18:53:06 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define UNREACHED	-1
#define TARGET		-2

#include <stack>

#include "Map.hpp"
#include "coords.hpp"

template <typename T>
void	clear_stack(std::stack<T>& stack)
{
	while (!stack.empty())
		stack.pop();
}

bool	is_path_valid(Map const& map, std::stack<coords>& path);
void	retrace_steps(int** grid_layer, std::stack<coords>& path,
			size_t target_x, size_t target_y, int laps_index);
int		init_protein_path(Map& map, std::stack<coords>& path);
