/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:54:10 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 16:53:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define STOCKS_NB		2
# define PROTEINS_NB	4

# include <cstddef>

typedef enum s_stock
{
	PLAYER = 0,
	BOSS = 1,
	A = 0,
	B = 1,
	C = 2,
	D = 3
}	t_stock;

class Stock
{
	public:
		//Constructors-Destructors
		Stock();
		~Stock();

		//Setters
		void	set_protein(t_stock protein_index, size_t value);

		//Getters
		size_t	get_protein(t_stock protein_index) const;

	private:
		size_t	_proteins[PROTEINS_NB];
};
