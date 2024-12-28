/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:16:46 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/28 18:29:29 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.hpp"

void	print_stocks(Stock const& myself, Stock const& opponent)
{
	std::cerr << "MYSELF:"
		<< myself.get_protein(A) << myself.get_protein(B)
		<< myself.get_protein(C) << myself.get_protein(D) << std::endl;

	std::cerr << "OPPONENT:"
		<< opponent.get_protein(A) << opponent.get_protein(B)
		<< opponent.get_protein(C) << opponent.get_protein(D) << std::endl;
}

void	print_path(std::stack<coords> path)
{
	while (!path.empty()) {
		coords& top = path.top();
		std::cerr << top.first << "x" << top.second << "y" << ", " << std::endl;
		path.pop();
	}
}
