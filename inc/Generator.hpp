/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:50:08 by aautin            #+#    #+#             */
/*   Updated: 2024/12/28 18:42:26 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

#include "Cell.hpp"

class Generator
{
	public:
		//Constructors-Destructors
		Generator(size_t x, size_t y, e_type type);
		Generator(Generator const& other);
		~Generator();

		//Overloads
		Generator	operator=(Generator const& other);

		//Getters
		size_t	get_x() const;
		size_t	get_y() const;
		e_type	get_type() const;

	private:
		size_t const	_x;
		size_t const	_y;
		e_type const	_type;
};
