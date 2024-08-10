/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:39:15 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 11:23:11 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_bool	is_in_a_wall(t_data *_data, t_vector2 _position)
{
	t_vector2int	position_int;

	if (!is_inside_map_dimensions(_data, _position))
		return (TRUE);
	position_int = vector2_to_vector2int(_position);
	if (_data->map->layout[position_int.y][position_int.x] == MAP_WALL)
		return (TRUE);
	return (FALSE);
}

t_bool	is_inside_map_dimensions(t_data *_data, t_vector2 _position)
{
	if (_position.x >= 0 && _position.x < _data->map->dimensions.x + 2
		&& _position.y >= 0 && _position.y < _data->map->dimensions.y + 2)
		return (TRUE);
	return (FALSE);
}

t_bool	is_inside_map_dimensions_int(t_data *_data, t_vector2int _position)
{
	if (_position.x >= 0 && _position.x < _data->map->dimensions.x + 2
		&& _position.y >= 0 && _position.y < _data->map->dimensions.y + 2)
		return (TRUE);
	return (FALSE);
}
