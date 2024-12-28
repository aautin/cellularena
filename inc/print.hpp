/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:19:03 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/28 18:29:22 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

#include "Stock.hpp"
#include "coords.hpp"

void	print_stocks(Stock const& myself, Stock const& opponent);
void	print_path(std::stack<coords> path);
