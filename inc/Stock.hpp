/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/25 00:44:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define STOCKS_NB	2
#define PROTEINS_NB	4

#include <cstddef>

#include "Cell.hpp"

class Stock
{
	public:
		//Constructors-Destructors
		Stock();
		~Stock();

		//Setters
		void	set_proteins(size_t a, size_t b, size_t c, size_t d);
		void	set_protein(e_type type, size_t value);

		//Getters
		size_t	get_protein(e_type protein_index) const;

		//Utils
		static bool	is_protein(Cell const& cell);

	private:
		size_t	_proteins[PROTEINS_NB];
};
