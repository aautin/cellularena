/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 14:19:34 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define STOCKS_NB	2
#define PROTEINS_NB	4

#include <cstddef>

#include "Cell.hpp"

typedef enum s_protein
{
	PROTEIN_A,
	PROTEIN_B,
	PROTEIN_C,
	PROTEIN_D
}	e_protein;

class Stock
{
	public:
		//Constructors-Destructors
		Stock();
		~Stock();

		//Setters
		void	set_proteins(size_t a, size_t b, size_t c, size_t d);
		void	set_protein_a(size_t a);
		void	set_protein_b(size_t b);
		void	set_protein_c(size_t c);
		void	set_protein_d(size_t d);

		//Getters
		size_t	get_protein(e_protein protein_index) const;

		//Utils
		static bool	is_protein(Cell const& cell);

	private:
		size_t	_proteins[PROTEINS_NB];
};
