/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:35:44 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 11:20:33 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_minimap(t_data *_data)
{
	t_vector2int	v;
	t_vector2int	v_draw;
	t_vector2int	dimensions;

	v.x = 0;
	vector2int_set(&dimensions, 5, 5);
	while (v.x < _data->map->dimensions.x + 2)
	{
		v.y = 0;
		while (v.y < _data->map->dimensions.y + 2)
		{
			if (_data->map->sqr_layout[v.y][v.x] == MAP_WALL)
			{
				vector2int_set(&v_draw, v.x * 5, v.y * 5);
				draw_rectangle(_data, v_draw, dimensions, COLOR_ORANGE);
			}
			v.y++;
		}
		v.x++;
	}
	vector2int_set(&v_draw, _data->player->position.x * 5,
		_data->player->position.y * 5);
	vector2int_set(&dimensions, 2, 2);
	draw_rectangle2(_data, v_draw, dimensions, COLOR_VIOLET);
}
