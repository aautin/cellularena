/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:50:53 by aautin            #+#    #+#             */
/*   Updated: 2024/12/24 02:13:53 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generator.hpp"

//Constructors-Destructors
Generator::Generator(size_t x, size_t y, e_type type)
: _x(x), _y(y), _type(type) { }

Generator::~Generator() {};
//-


//Overloads
Generator	Generator::operator=(Generator const& other) { (void) other; return *this; }
//-


//Getters
size_t	Generator::get_x() const { return _x; }

size_t	Generator::get_y() const { return _y; }

e_type	Generator::get_type() const { return _type; }
//-
