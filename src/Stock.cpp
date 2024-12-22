/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:48:52 by aautin            #+#    #+#             */
/*   Updated: 2024/12/22 16:31:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stock.hpp"

//Constructors-Destructors
Stock::Stock(): _proteins{0, 0, 0, 0} { }

Stock::~Stock() { }
//-


//Setters
void	Stock::set_proteins(size_t a, size_t b, size_t c, size_t d)
{
	_proteins[PROTEIN_A] = a;
	_proteins[PROTEIN_B] = b;
	_proteins[PROTEIN_C] = c;
	_proteins[PROTEIN_D] = d;
}
void	Stock::set_protein_a(size_t a)
{
	_proteins[PROTEIN_A] = a;
}

void	Stock::set_protein_b(size_t b)
{
	_proteins[PROTEIN_B] = b;
}

void	Stock::set_protein_c(size_t c)
{
	_proteins[PROTEIN_C] = c;
}

void	Stock::set_protein_d(size_t d)
{
	_proteins[PROTEIN_D] = d;
}
//-


//Getters
size_t	Stock::get_protein(e_protein index) const { return _proteins[index]; }
//-
