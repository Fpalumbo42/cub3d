/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:45:56 by jfazi             #+#    #+#             */
/*   Updated: 2024/04/04 19:08:30 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_textures2(t_data *_data)
{
	_data->nord_img->addr
		= mlx_get_data_addr(_data->nord_img->img, &_data->nord_img->bpp,
			&_data->nord_img->llngth, &_data->nord_img->endn);
	_data->south_img->addr
		= mlx_get_data_addr(_data->south_img->img, &_data->south_img->bpp,
			&_data->south_img->llngth, &_data->south_img->endn);
	_data->east_img->addr
		= mlx_get_data_addr(_data->east_img->img, &_data->east_img->bpp,
			&_data->east_img->llngth, &_data->east_img->endn);
	_data->west_img->addr
		= mlx_get_data_addr(_data->west_img->img, &_data->west_img->bpp,
			&_data->west_img->llngth, &_data->west_img->endn);
}

void	init_img(t_data *_data)
{
	_data->nord_img = malloc(sizeof(t_image));
	_data->south_img = malloc(sizeof(t_image));
	_data->east_img = malloc(sizeof(t_image));
	_data->west_img = malloc(sizeof(t_image));
}

void	init_textures(t_data *_data)
{
	int	w;
	int	h;

	w = TEXTURE_WIDTH;
	h = TEXTURE_HEIGHT;
	init_img(_data);
	_data->nord_img->img = mlx_xpm_file_to_image(_data->mlx,
			_data->map->nord_texture, &w, &h);
	_data->south_img->img = mlx_xpm_file_to_image(_data->mlx,
			_data->map->south_texture, &w, &h);
	_data->east_img->img = mlx_xpm_file_to_image(_data->mlx,
			_data->map->east_texture, &w, &h);
	_data->west_img->img = mlx_xpm_file_to_image(_data->mlx,
			_data->map->west_texture, &w, &h);
	if (!_data->nord_img->img || !_data->south_img->img
		|| !_data->east_img->img || !_data->west_img->img)
		panpan(_data, "Error\nInvalid textures\n");
	init_textures2(_data);
}

void	init_colors(t_data *_data)
{
	_data->ceilling_color = ft_atoi(_data->map->ceilling_color_tab[0]);
	_data->ceilling_color = (_data->ceilling_color << 8)
		+ ft_atoi(_data->map->ceilling_color_tab[1]);
	_data->ceilling_color = (_data->ceilling_color << 8)
		+ ft_atoi(_data->map->ceilling_color_tab[2]);
	_data->floor_color = ft_atoi(_data->map->ground_color_tab[0]);
	_data->floor_color = (_data->floor_color << 8)
		+ ft_atoi(_data->map->ground_color_tab[1]);
	_data->floor_color = (_data->floor_color << 8)
		+ ft_atoi(_data->map->ground_color_tab[2]);
}
