/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:48:52 by aautin            #+#    #+#             */
/*   Updated: 2024/12/27 20:05:01 by aautin           ###   ########.fr       */
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
	_proteins[A] = a;
	_proteins[B] = b;
	_proteins[C] = c;
	_proteins[D] = d;
}

void	Stock::set_protein(e_type type, size_t value)
{
	_proteins[type] = value;
}
//-


//Getters
size_t	Stock::get_protein(e_type index) const { return _proteins[index]; }
//-
