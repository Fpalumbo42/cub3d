/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:39:07 by jfazi             #+#    #+#             */
/*   Updated: 2024/04/22 17:35:49 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_rectangle(t_data *_data, t_vector2int _position,
	t_vector2int _dimensions, int _color)
{
	int	i;
	int	j;

	i = _position.x;
	while (i < _position.x + _dimensions.x)
	{
		j = _position.y;
		while (j < _position.y + _dimensions.y)
		{
			draw_pixel(_data->rendering, i, j, _color);
			j++;
		}
		i++;
	}
}

void	draw_vertical_line2(t_data *_data, int x,
	t_raycast *_raycast, t_column *_column)
{
	(void)x;
	_column->step = 0;
	_column->line_height = (int)(WINDOW_HEIGHT / _raycast->distance);
	_column->draw_start = -_column->line_height / 2 + WINDOW_HEIGHT / 2;
	if (_column->draw_start < 0)
		_column->draw_start = 0;
	_column->draw_end = _column->line_height / 2 + WINDOW_HEIGHT / 2;
	if (_column->draw_end >= WINDOW_HEIGHT)
		_column->draw_end = WINDOW_HEIGHT;
	if (_raycast->wall_side_hit == 0)
		_column->wall_x = _data->player->position.y
			+ _raycast->distance * _raycast->direction.y;
	else
		_column->wall_x = _data->player->position.x
			+ _raycast->distance * _raycast->direction.x;
	_column->wall_x -= floor(_column->wall_x);
	_column->tex_x = (int)(_column->wall_x * TEXTURE_WIDTH);
	if (_raycast->wall_side_hit == 0 && _raycast->direction.x > 0)
		_column->tex_x = TEXTURE_WIDTH - _column->tex_x - 1;
	if (_raycast->wall_side_hit == 1 && _raycast->direction.y < 0)
		_column->tex_x = TEXTURE_WIDTH - _column->tex_x - 1;
	_column->step = (double)(TEXTURE_WIDTH)
		/ (double)(_column->line_height);
	_column->tex_pos = (_column->draw_start - WINDOW_HEIGHT
			/ 2 + _column->line_height / 2) * _column->step;
}

void	draw_vertical_line(t_data *_data, int x,
	t_raycast *_raycast)
{
	t_column	column;

	x = (x * -1) + WINDOW_WIDTH - 1;
	draw_vertical_line2(_data, x, _raycast, &column);
	while (column.draw_start < column.draw_end)
	{
		column.y_texture = (int)column.tex_pos & (TEXTURE_WIDTH + 8);
		if (_raycast->wall_side_hit == 1 && _raycast->direction.y > 0)
			column.color = get_pixel(_data->south_img,
					column.tex_x, column.y_texture);
		else if (_raycast->wall_side_hit == 1 && _raycast->direction.y < 0)
			column.color = get_pixel(_data->nord_img,
					column.tex_x, column.y_texture);
		else if (_raycast->wall_side_hit == 0 && _raycast->direction.x > 0)
			column.color = get_pixel(_data->east_img,
					column.tex_x, column.y_texture);
		else if (_raycast->wall_side_hit == 0 && _raycast->direction.x < 0)
			column.color = get_pixel(_data->west_img,
					column.tex_x, column.y_texture);
		if (_raycast->wall_side_hit == 1)
			column.color = (column.color >> 1) & 8355711;
		draw_pixel(_data->rendering, x, column.draw_start, column.color);
		column.tex_pos += column.step;
		column.draw_start++;
	}
}

void	render_background(t_data *_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			if (j < WINDOW_HEIGHT / 2)
				draw_pixel(_data->rendering, i, j, _data->ceilling_color);
			else
				draw_pixel(_data->rendering, i, j, _data->floor_color);
			j++;
		}
		i++;
	}
}

void	rendering(t_data *_data)
{
	render_background(_data);
	raycasting(_data);
	draw_minimap(_data);
	mlx_put_image_to_window(_data->mlx, _data->mlx_win,
		_data->rendering->img, 0, 0);
}
