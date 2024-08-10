/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:48 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 14:22:18 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

///@return TRUE if player can move, FALSE if not
t_bool	can_move_player(t_data *_data, t_bool plus_x,
	t_bool plus_y, t_vector2 _axis)
{
	t_vector2		test_player;
	t_vector2int	test_player_int;

	vector2_set(&test_player, _data->player->position.x,
		_data->player->position.y);
	if (plus_x)
		test_player.x += _axis.x * MOVE_SPEED;
	else
		test_player.x -= _axis.x * MOVE_SPEED;
	if (plus_y)
		test_player.y += _axis.y * MOVE_SPEED;
	else
		test_player.y -= _axis.y * MOVE_SPEED;
	test_player_int = vector2_to_vector2int(test_player);
	if (!is_inside_map_dimensions(_data, test_player))
		return (FALSE);
	if (_data->map->sqr_layout[test_player_int.y][test_player_int.x] == '1')
		return (FALSE);
	return (TRUE);
}

void	rotate_left(t_data *_data)
{
	double	tmp_rotation_x;
	double	tmp_plane_x;

	tmp_rotation_x = _data->player->rotation.x;
	tmp_plane_x = _data->player->plane.x;
	_data->player->rotation.x = _data->player->rotation.x
		* cos(-ROTATE_SPEED)
		- _data->player->rotation.y * sin(-ROTATE_SPEED);
	_data->player->rotation.y = tmp_rotation_x * sin(-ROTATE_SPEED)
		+ _data->player->rotation.y * cos(-ROTATE_SPEED);
	_data->player->plane.x = _data->player->plane.x * cos(-ROTATE_SPEED)
		- _data->player->plane.y * sin(-ROTATE_SPEED);
	_data->player->plane.y = tmp_plane_x * sin(-ROTATE_SPEED)
		+ _data->player->plane.y * cos(-ROTATE_SPEED);
	if (_data->player->rotation.x == 0)
		_data->player->rotation.x = 0.0001;
	if (_data->player->rotation.y == 0)
		_data->player->rotation.y = 0.0001;
}

void	rotate_right(t_data *_data)
{
	double	tmp_rotation_x;
	double	tmp_plane_x;

	tmp_rotation_x = _data->player->rotation.x;
	tmp_plane_x = _data->player->plane.x;
	_data->player->rotation.x = _data->player->rotation.x
		* cos(ROTATE_SPEED)
		- _data->player->rotation.y * sin(ROTATE_SPEED);
	_data->player->rotation.y = tmp_rotation_x * sin(ROTATE_SPEED)
		+ _data->player->rotation.y * cos(ROTATE_SPEED);
	_data->player->plane.x = _data->player->plane.x * cos(ROTATE_SPEED)
		- _data->player->plane.y * sin(ROTATE_SPEED);
	_data->player->plane.y = tmp_plane_x * sin(ROTATE_SPEED)
		+ _data->player->plane.y * cos(ROTATE_SPEED);
	if (_data->player->rotation.x == 0)
		_data->player->rotation.x = 0.0001;
	if (_data->player->rotation.y == 0)
		_data->player->rotation.y = 0.0001;
}
