/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:22:55 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/05/07 14:39:53 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	pp2(t_data *_data, char *str)
{
	printf(RED"%s"RESET, str);
	if (!_data)
		exit(0);
	if (_data->pars)
	{
		if (_data->pars->file)
			free_string_array(_data->pars->file, _data->pars->file_taille);
		free(_data->pars);
	}
	if (_data->inputs)
		free(_data->inputs);
}

void	pp3(t_data *_data)
{
	if (_data->map)
	{
		if (_data->map->layout)
			free_string_array(_data->map->layout, _data->map->dimensions.y);
		if (_data->map->sqr_layout)
			free_string_array(_data->map->sqr_layout,
				_data->map->dimensions.y + 2);
		if (_data->map->ground_color_tab)
			free_string_array(_data->map->ground_color_tab, 3);
		if (_data->map->ceilling_color_tab)
			free_string_array(_data->map->ceilling_color_tab, 3);
		if (_data->map->ceilling_color)
			free(_data->map->ceilling_color);
		if (_data->map->ground_color)
			free(_data->map->ground_color);
		if (_data->map->nord_texture)
			free(_data->map->nord_texture);
		if (_data->map->south_texture)
			free(_data->map->south_texture);
		if (_data->map->east_texture)
			free(_data->map->east_texture);
		if (_data->map->west_texture)
			free(_data->map->west_texture);
		free(_data->map);
	}
}

void	pp4(t_data *_data)
{
	if (_data->player)
		free(_data->player);
	if (_data->nord_img)
	{
		if (_data->nord_img->img)
			mlx_destroy_image(_data->mlx, _data->nord_img->img);
		free(_data->nord_img);
	}
	if (_data->south_img)
	{
		if (_data->south_img->img)
			mlx_destroy_image(_data->mlx, _data->south_img->img);
		free(_data->south_img);
	}
	if (_data->east_img)
	{
		if (_data->east_img->img)
			mlx_destroy_image(_data->mlx, _data->east_img->img);
		free(_data->east_img);
	}
}

void	panpan(t_data *_data, char *str)
{
	pp2(_data, str);
	pp3(_data);
	pp4(_data);
	if (_data->west_img)
	{
		if (_data->west_img->img)
			mlx_destroy_image(_data->mlx, _data->west_img->img);
		free(_data->west_img);
	}
	if (_data->rendering)
	{
		mlx_destroy_image(_data->mlx, _data->rendering->img);
		free(_data->rendering);
	}
	if (_data->mlx_win)
		mlx_destroy_window(_data->mlx, _data->mlx_win);
	if (_data->mlx)
	{
		mlx_destroy_display(_data->mlx);
		free(_data->mlx);
	}
	if (_data)
		free(_data);
	exit(0);
}

int	panpan2(void *_data)
{
	t_data	*data;

	data = (t_data *)_data;
	panpan(data, "You closed the window\n");
	exit(0);
}
