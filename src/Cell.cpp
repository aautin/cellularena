/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:35:41 by aautin            #+#    #+#             */
/*   Updated: 2024/12/22 17:04:39 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cell.hpp"

//Constructors-Destructors
Cell::Cell() : _type(NO_TYPE), _owner(NO_OWNER), _direction(NO_DIRECTION) { }

Cell::Cell(std::string& type, e_owner owner, std::string& direction)
{
	_type = type_stoi(type);
	_owner = owner;
	_direction = direction_stoi(direction);
}

Cell::Cell(e_type type, e_owner owner, e_direction direction)
{
	_type = type;
	_owner = owner;
	_direction = direction;
}

Cell::~Cell() { }
//-


//Getters
e_type	Cell::get_type() const { return _type; }

int	Cell::get_owner() const { return _owner; }

e_direction	Cell::get_direction() const { return _direction; }
//-


//Setters
void	Cell::set_type(e_type type) { _type = type; }

void	Cell::set_owner(int owner) { _owner = owner; }

void	Cell::set_direction(e_direction direction) { _direction = direction; }
//-


//Utils
e_type	Cell::type_stoi(std::string& type)
{
	const std::string types[TYPES_NB] = {
		"WALL", "ROOT", "BASIC", "TENTACLE",
		"HARVESTER", "SPORER", "A", "B", "C", "D"
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
		"WALL", "ROOT", "BASIC", "TENTACLE",
		"HARVESTER", "SPORER", "A", "B", "C", "D"
	};

	for (size_t i = 0; i < TYPES_NB; ++i) {
		if (type == static_cast<e_type>(i))
			return types[i];
	}
	return "NO_TYPE";
}

e_direction	Cell::direction_stoi(std::string& direction)
{
	const std::string directions[DIRECTIONS_NB] = { "N", "S", "W", "E"};

	for (size_t i = 0; i < DIRECTIONS_NB; ++i) {
		if (directions[i] == direction)
			return static_cast<e_direction>(i);
	}
	return NO_DIRECTION;
}

std::string	Cell::direction_itos(e_direction direction)
{
	const std::string directions[DIRECTIONS_NB] = { "N", "S", "W", "E"};

	for (size_t i = 0; i < DIRECTIONS_NB; ++i) {
		if (direction == static_cast<e_direction>(i))
			return directions[i];
	}
	return "NO_DIRECTION";
}
//-
