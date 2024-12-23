/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harvester.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:50:53 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 20:05:18 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harvester.hpp"

//Constructors-Destructors
Harvester::Harvester(size_t x, size_t y) : _x(x), _y(y), _meals_number(0) { }

Harvester::~Harvester() {};
//-


//Overloads
Harvester	Harvester::operator=(Harvester const& other)
{
	this->_meals_number = other._meals_number;
	return *this;
}
//-


//Getters
size_t	Harvester::get_x() const { return _x; }

size_t	Harvester::get_y() const { return _y; }
//-


//Meals
void	Harvester::eat_meal() { _meals_number++; }

bool	Harvester::can_eat() const { return _meals_number < MEALS_NB_MAX; }
//-
