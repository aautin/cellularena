/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:48:52 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 16:20:53 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stock.hpp"

//Constructors-Destructors
Stock::Stock(): _proteins{0, 0, 0, 0} { }

Stock::~Stock() { }
//-


//Setters
void	Stock::set_protein(t_stock index, size_t value) { _proteins[index] = value; }
//-


//Getters
size_t	Stock::get_protein(t_stock index) const { return _proteins[index]; }
//-
