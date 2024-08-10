/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:42:39 by jfazi             #+#    #+#             */
/*   Updated: 2024/04/22 17:26:08 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	move(t_data *_data)
{
	if (_data->inputs->forward_movement)
		move_forward(_data);
	if (_data->inputs->downward_movement)
		move_backward(_data);
	if (_data->inputs->left_movement)
		move_left(_data);
	if (_data->inputs->right_movement)
		move_right(_data);
	if (_data->inputs->left_rotation)
		rotate_left(_data);
	if (_data->inputs->right_rotation)
		rotate_right(_data);
	rendering(_data);
	return (0);
}

void	move_forward(t_data *_data)
{
	if (can_move_player(_data, TRUE, TRUE, _data->player->rotation))
	{
		_data->player->position.x += _data->player->rotation.x * MOVE_SPEED;
		_data->player->position.y += _data->player->rotation.y * MOVE_SPEED;
	}
}

void	move_backward(t_data *_data)
{
	if (can_move_player(_data, FALSE, FALSE, _data->player->rotation))
	{
		_data->player->position.x -= _data->player->rotation.x * MOVE_SPEED;
		_data->player->position.y -= _data->player->rotation.y * MOVE_SPEED;
	}
}

void	move_right(t_data *_data)
{
	if (can_move_player(_data, FALSE, FALSE, _data->player->plane))
	{
		_data->player->position.x -= _data->player->plane.x * MOVE_SPEED;
		_data->player->position.y -= _data->player->plane.y * MOVE_SPEED;
	}
}

void	move_left(t_data *_data)
{
	if (can_move_player(_data, TRUE, TRUE, _data->player->plane))
	{
		_data->player->position.x += _data->player->plane.x * MOVE_SPEED;
		_data->player->position.y += _data->player->plane.y * MOVE_SPEED;
	}
}
