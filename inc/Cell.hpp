/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:18:16 by aautin            #+#    #+#             */
/*   Updated: 2024/12/21 17:26:11 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define TYPES_NB		11
#define DIRECTIONS_NB	5
#define OWNERS_NB		3

#include <string>

typedef enum s_type
{
	WALL,		ROOT,
	BASIC,		TENTACLE,
	HARVESTER,	SPORER,
	A,	B,	C,	D,
	NO_TYPE
}	e_type;

typedef enum s_owner
{
	MYSELF = 1,
	OPPONENT = 0,
	NO_OWNER = -1
}	e_owner;

typedef enum s_direction
{
	NORTH,	SOUTH,
	WEST,	EAST,
	NO_DIRECTION
}	e_direction;

class Cell
{
	public:
		//Constructors-Destructors
		Cell();
		Cell(std::string& type, e_owner owner, std::string& direction);
		Cell(e_type type, e_owner owner, e_direction direction);
		~Cell();

		//Setters
		void	set_type(e_type type);
		void	set_owner(int owner);
		void	set_direction(e_direction direction);

		//Getters
		e_type		get_type() const;
		int			get_owner() const;
		e_direction	get_direction() const;

	private:
		e_type		_type;
		int			_owner;
		e_direction	_direction;

		//Utils
		static e_type		type_stoi(std::string& type);
		static std::string	type_itos(e_type type);
		static e_direction	direction_stoi(std::string& direction);
		static std::string	direction_itos(e_direction direction);

};

