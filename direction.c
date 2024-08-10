/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:35:33 by jfazi             #+#    #+#             */
/*   Updated: 2024/04/22 16:07:06 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_direction	rotatt_direction(t_bool _rotate_left, t_direction _direction)
{
	if (_rotate_left)
	{
		if (_direction == NORD)
			return (WEST);
		if (_direction == WEST)
			return (SOUTH);
		if (_direction == SOUTH)
			return (EAST);
		if (_direction == EAST)
			return (NORD);
	}
	else
	{
		if (_direction == NORD)
			return (EAST);
		if (_direction == EAST)
			return (SOUTH);
		if (_direction == SOUTH)
			return (WEST);
		if (_direction == WEST)
			return (NORD);
	}
	return (NONE);
}

t_direction	convert_char_to_direction(char c)
{
	if (c == 'N')
		return (NORD);
	if (c == 'S')
		return (SOUTH);
	if (c == 'E')
		return (EAST);
	if (c == 'W')
		return (WEST);
	else
		return (NONE);
}

char	*convert_direction_to_string(t_direction _direction)
{
	if (_direction == NORD)
		return ("NORD");
	if (_direction == SOUTH)
		return ("SOUTH");
	if (_direction == WEST)
		return ("WEST");
	if (_direction == EAST)
		return ("EAST");
	else
		return ("NONE");
}

float	convert_direction_to_float(t_direction _direction)
{
	if (_direction == NORD)
		return (0);
	if (_direction == SOUTH)
		return (180);
	if (_direction == WEST)
		return (270);
	if (_direction == EAST)
		return (90);
	else
		return (0);
}

t_vector2	convert_direction_to_vector(t_direction _direction)
{
	t_vector2	vector;

	if (_direction == NORD)
	{
		vector.x = 0.0001;
		vector.y = -1.0;
	}
	if (_direction == SOUTH)
	{
		vector.x = 0.0001;
		vector.y = 1.0;
	}
	if (_direction == EAST)
	{
		vector.x = 1.0;
		vector.y = 0.0001;
	}
	if (_direction == WEST)
	{
		vector.x = -1.0;
		vector.y = 0.0001;
	}
	return (vector);
}
