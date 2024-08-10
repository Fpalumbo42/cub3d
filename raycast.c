/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:10:35 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 14:22:25 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_delta_dist(t_raycast *_raycast)
{
	if (_raycast->direction.x == 0)
		_raycast->delta_dist.x = INT_MAX;
	else
		_raycast->delta_dist.x = fabs(1 / _raycast->direction.x);
	if (_raycast->direction.x == 0)
		_raycast->delta_dist.y = INT_MAX;
	else
		_raycast->delta_dist.y = fabs(1 / _raycast->direction.y);
}

void	get_step(t_raycast *_raycast, t_data *_data)
{
	if (_raycast->direction.x < 0)
	{
		_raycast->step.x = -1;
		_raycast->side_dist.x = (_data->player->position.x - _raycast->map.x)
			* _raycast->delta_dist.x;
	}
	else
	{
		_raycast->step.x = 1;
		_raycast->side_dist.x = (_raycast->map.x + 1.0
				- _data->player->position.x) * _raycast->delta_dist.x;
	}
	if (_raycast->direction.y < 0)
	{
		_raycast->step.y = -1;
		_raycast->side_dist.y = (_data->player->position.y - _raycast->map.y)
			* _raycast->delta_dist.y;
	}
	else
	{
		_raycast->step.y = 1;
		_raycast->side_dist.y = (_raycast->map.y + 1.0
				- _data->player->position.y) * _raycast->delta_dist.y;
	}
}

void	digital_differential_analyser(t_raycast *_raycast, t_data *_data)
{
	_raycast->hit = 0;
	while (_raycast->hit == 0)
	{
		if (_raycast->side_dist.x < _raycast->side_dist.y)
		{
			_raycast->side_dist.x += _raycast->delta_dist.x;
			_raycast->map.x += _raycast->step.x;
			_raycast->wall_side_hit = 0;
		}
		else
		{
			_raycast->side_dist.y += _raycast->delta_dist.y;
			_raycast->map.y += _raycast->step.y;
			_raycast->wall_side_hit = 1;
		}
		if (!is_inside_map_dimensions_int(_data, _raycast->map))
			return ;
		if (_data->map->sqr_layout[_raycast->map.y][_raycast->map.x] == '1')
			_raycast->hit = 1;
	}
}

void	init_raycasting(t_data *_data, int x, t_raycast *_raycast)
{
	_raycast->map.x = _data->player->position.x;
	_raycast->map.y = _data->player->position.y;
	_data->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	_raycast->direction.x = _data->player->rotation.x
		+ _data->player->plane.x * _data->camera_x;
	_raycast->direction.y = _data->player->rotation.y
		+ _data->player->plane.y * _data->camera_x;
}

void	raycasting(t_data *_data)
{
	int			x;
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_raycasting(_data, x, raycast);
		get_delta_dist(raycast);
		get_step(raycast, _data);
		digital_differential_analyser(raycast, _data);
		if (raycast->wall_side_hit == 0)
			raycast->distance = ((raycast->side_dist.x
						- raycast->delta_dist.x));
		else
			raycast->distance = ((raycast->side_dist.y
						- raycast->delta_dist.y));
		if (raycast->hit)
			draw_vertical_line(_data, x, raycast);
		x++;
	}
	free(raycast);
}
