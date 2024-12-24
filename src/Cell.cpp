/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/25 00:47:43 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cell.hpp"
#include "near.h"

//Constructors-Destructors
Cell::Cell()
: _type(NO_TYPE), _owner(NO_OWNER), _direction(NO_DIRECTION), _organ_id(NO_ID) { }

Cell::Cell(std::string& type, e_owner owner, std::string& direction, size_t organ_id)
{
	_type = type_stoi(type);
	_owner = owner;
	_direction = direction_stoi(direction);
	_organ_id = organ_id;
}

Cell::Cell(e_type type, e_owner owner, e_direction direction, size_t organ_id)
{
	_type = type;
	_owner = owner;
	_direction = direction;
	_organ_id = organ_id;
}

Cell::~Cell() { }
//-


//Getters
e_type	Cell::get_type() const { return _type; }

int	Cell::get_owner() const { return _owner; }

e_direction	Cell::get_direction() const { return _direction; }

void	Cell::set_organ_id(size_t organ_id) { _organ_id = organ_id; }
//-


//Setters
void	Cell::set_type(e_type type) { _type = type; }

void	Cell::set_owner(int owner) { _owner = owner; }

void	Cell::set_direction(e_direction direction) { _direction = direction; }

size_t	Cell::get_organ_id() const { return _organ_id; }
//-


//Utils
e_type	Cell::type_stoi(std::string& type)
{
	const std::string types[TYPES_NB] = {
		"A", "B", "C", "D",
		"WALL", "ROOT", "BASIC", "TENTACLE",
		"HARVESTER", "SPORER" 
	};

	for (size_t i = 0; i < TYPES_NB; ++i) {
		if (types[i] == type)
			return static_cast<e_type>(i);
	}
	return NO_TYPE;
}

std::string	Cell::type_itos(e_type type)
{
	const std::string types[TYPES_NB] = {
		"A", "B", "C", "D",
		"WALL", "ROOT", "BASIC", "TENTACLE",
		"HARVESTER", "SPORER"
	};

	for (size_t i = 0; i < TYPES_NB; ++i) {
		if (type == static_cast<e_type>(i))
			return types[i];
	}
	return "NO_TYPE";
}

e_direction	Cell::direction_stoi(std::string& direction)
{
	const std::string directions[DIRECTIONS_NB] = { "W", "E", "N", "S"};

	for (size_t i = 0; i < DIRECTIONS_NB; ++i) {
		if (directions[i] == direction)
			return static_cast<e_direction>(i);
	}
	return NO_DIRECTION;
}

std::string	Cell::direction_itos(e_direction direction)
{
	const std::string directions[DIRECTIONS_NB] = { "W", "E", "N", "S"};

	for (size_t i = 0; i < DIRECTIONS_NB; ++i) {
		if (direction == static_cast<e_direction>(i))
			return directions[i];
	}
	return "NO_DIRECTION";
}

e_direction	Cell::coords_to_direction(int x, int y)
{
	for (size_t i = 0; i < 4; ++i) {
		if (near_x[i] == x && near_y[i] == y)
			return static_cast<e_direction>(i);
	}
	return NO_DIRECTION;
}
//-
