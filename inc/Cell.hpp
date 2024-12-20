/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:18:16 by aautin            #+#    #+#             */
/*   Updated: 2024/12/20 13:21:53 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASE_HPP
# define CASE_HPP

# define TYPES_NB		10
# define DIRECTIONS_NB	4
# define OWNERS_NB		3

# include <string>

typedef enum s_type
{
	WALL,		ROOT,
	BASIC,		TENTACLE,
	HARVESTER,	SPORER,
	A,	B,	C,	D
}	e_type;

typedef enum s_owner
{
	PLAYER,
	BOSS,
	NONE
}	e_owner;

typedef enum s_direction
{
	NORTH,	SOUTH,
	WEST,	EAST
}	e_direction;

class Cell
{
	public:
		//Constructors-Destructors
		Cell();
		Cell(std::string& type, int owner, std::string& direction);
		~Cell();
		//-

		//Getters
		e_type		get_type() const;
		int			get_owner() const;
		e_direction	get_direction() const;
		//-

		//Setters
		void	set_type(e_type type);
		void	set_owner(int owner);
		void	set_direction(e_direction direction);
		//-

	private:
		e_type		_type;
		int			_owner;
		e_direction	_direction;

		//Utils
		static e_type		type_stoi(std::string& type);
		static e_direction	direction_stoi(std::string& direction);
};

#endif