/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:18:16 by aautin            #+#    #+#             */
/*   Updated: 2024/12/23 17:24:59 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define TYPES_NB		10
#define DIRECTIONS_NB	4
#define OWNERS_NB		2

#define NO_ID			0

#include <string>

enum e_type {
	WALL,		ROOT,
	BASIC,		TENTACLE,
	HARVESTER,	SPORER,
	A,	B,	C,	D,
	NO_TYPE
};

enum e_owner
{
	MYSELF = 1,
	OPPONENT = 0,
	NO_OWNER = -1
};

enum e_direction
{
	NORTH,	SOUTH,
	WEST,	EAST,
	NO_DIRECTION
};

class Cell
{
	public:
		//Constructors-Destructors
		Cell();
		Cell(std::string& type, e_owner owner, std::string& direction, size_t organ_id);
		Cell(e_type type, e_owner owner, e_direction direction, size_t organ_id);
		~Cell();

		//Setters
		void	set_type(e_type type);
		void	set_owner(int owner);
		void	set_direction(e_direction direction);
		void	set_organ_id(size_t direction);

		//Getters
		e_type		get_type() const;
		int			get_owner() const;
		e_direction	get_direction() const;
		size_t		get_organ_id() const;

	private:
		e_type		_type;
		int			_owner;
		e_direction	_direction;
		size_t		_organ_id;

		//Utils
		static e_type		type_stoi(std::string& type);
		static std::string	type_itos(e_type type);
		static e_direction	direction_stoi(std::string& direction);
		static std::string	direction_itos(e_direction direction);
};

