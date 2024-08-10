/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:18:18 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 14:21:27 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/// @return FALSE if init failed, TRUE if not 

void	init_data2(t_data *_data)
{
	_data->map->ceilling_color = NULL;
	_data->map->ground_color = NULL;
	_data->map->nord_texture = NULL;
	_data->map->south_texture = NULL;
	_data->map->east_texture = NULL;
	_data->map->west_texture = NULL;
	_data->player = NULL;
	_data->nord_img = NULL;
	_data->south_img = NULL;
	_data->east_img = NULL;
	_data->west_img = NULL;
	_data->rendering = NULL;
}

t_bool	init_data(t_data *_data, char **_argv)
{
	_data->mlx = mlx_init();
	_data->mlx_win = mlx_new_window(_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Ouga bouga!");
	_data->map = malloc(sizeof(t_map));
	_data->inputs = NULL;
	_data->map->sqr_layout = NULL;
	_data->map->layout = NULL;
	_data->map->ground_color_tab = NULL;
	_data->map->ceilling_color_tab = NULL;
	init_data2(_data);
	init_parsing(_data, _argv);
	init_rendering(_data);
	init_player(_data);
	_data->inputs = malloc(sizeof(t_inputs));
	clear_inputs(_data->inputs);
	init_textures(_data);
	init_colors(_data);
	return (TRUE);
}

void	init_player(t_data *_data)
{
	_data->player = malloc(sizeof(t_player));
	vector2_set(&(_data->player->position), _data->map->player_spawn.x + 1.5,
		_data->map->player_spawn.y + 1.5);
	_data->player->rotation
		= convert_direction_to_vector(_data->map->player_spawn_rotation);
	if (_data->map->player_spawn_rotation == NORD)
		vector2_set(&(_data->player->plane), -0.66, 0.0);
	if (_data->map->player_spawn_rotation == SOUTH)
		vector2_set(&(_data->player->plane), 0.66, 0.0);
	if (_data->map->player_spawn_rotation == WEST)
		vector2_set(&(_data->player->plane), 0.0, 0.66);
	if (_data->map->player_spawn_rotation == EAST)
		vector2_set(&(_data->player->plane), 0.0, -0.66);
}

void	init_rendering(t_data *_data)
{
	_data->rendering = malloc(sizeof(t_image));
	_data->rendering->img = mlx_new_image(_data->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	_data->rendering->addr = mlx_get_data_addr(_data->rendering->img,
			&(_data->rendering->bpp),
			&(_data->rendering->llngth),
			&(_data->rendering->endn));
}

void	init_parsing(t_data *_data, char **_argv)
{
	_data->pars = malloc(sizeof(t_parsing));
	_data->pars->file = NULL;
	_data->pars->file_taille = 0;
	_data->pars->arg_taille = 0;
	file_manager(_argv, _data);
}
