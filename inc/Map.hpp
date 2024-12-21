/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/21 17:04:23 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Cell.hpp"
#include "Stock.hpp"

class Map
{
	public:
		//Constructors-Destructors
		Map(size_t width, size_t height);
		~Map();

		//Setters
		void	set_cell(Cell& cell, size_t x, size_t y);

		//Getters
		size_t	get_width() const;
		size_t	get_height() const;
		Cell&	get_cell(size_t x, size_t y) const;
		Stock&	get_stock(e_owner index);

	private:
		size_t const	_grid_width;
		size_t const	_grid_height;
		Cell**			_grid;

		Stock			_stocks[STOCKS_NB];
};
