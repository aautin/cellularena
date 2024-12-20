/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 18:13:43 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define STOCKS_NB	2
#define PROTEINS_NB	4

#include <cstddef>

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

		//Getters
		size_t	get_protein(e_protein protein_index) const;

	private:
		size_t	_proteins[PROTEINS_NB];
};
