/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:38:04 by jfazi             #+#    #+#             */
/*   Updated: 2024/04/22 18:23:19 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	register_inputs(int _keycode, t_data *_data)
{
	if (_keycode == KEYCODE_ESC)
		panpan(_data, "You closed the window\n");
	else if (_keycode == KEYCODE_W)
		_data->inputs->forward_movement = TRUE;
	else if (_keycode == KEYCODE_S)
		_data->inputs->downward_movement = TRUE;
	else if (_keycode == KEYCODE_D)
		_data->inputs->right_movement = TRUE;
	else if (_keycode == KEYCODE_A)
		_data->inputs->left_movement = TRUE;
	else if (_keycode == KEYCODE_LEFT_ARROW)
		_data->inputs->left_rotation = TRUE;
	else if (_keycode == KEYCODE_RIGHT_ARROW)
		_data->inputs->right_rotation = TRUE;
	return (0);
}

int	release_inputs(int _keycode, t_data *_data)
{
	if (_keycode == KEYCODE_W)
		_data->inputs->forward_movement = FALSE;
	else if (_keycode == KEYCODE_S)
		_data->inputs->downward_movement = FALSE;
	else if (_keycode == KEYCODE_D)
		_data->inputs->right_movement = FALSE;
	else if (_keycode == KEYCODE_A)
		_data->inputs->left_movement = FALSE;
	else if (_keycode == KEYCODE_LEFT_ARROW)
		_data->inputs->left_rotation = FALSE;
	else if (_keycode == KEYCODE_RIGHT_ARROW)
		_data->inputs->right_rotation = FALSE;
	return (0);
}

/// @brief Set all inputs to FALSE
void	clear_inputs(t_inputs *_inputs)
{
	_inputs->forward_movement = FALSE;
	_inputs->downward_movement = FALSE;
	_inputs->right_movement = FALSE;
	_inputs->left_movement = FALSE;
	_inputs->right_rotation = FALSE;
	_inputs->left_rotation = FALSE;
	_inputs->close_window = FALSE;
}
