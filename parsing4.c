/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:05:30 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/04/24 16:29:16 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parse_map2(t_data *_data, t_copy *_cop)
{
	_cop->i = 0;
	_cop->flag = 0;
	while (_cop->i < _data->map->dimensions.y)
	{
		_cop->j = 0;
		while (_data->map->layout[_cop->i][_cop->j] != '\n'
			&& _data->map->layout[_cop->i][_cop->j] != '\0')
		{
			if (_data->map->layout[_cop->i][_cop->j] != '1'
				&& _data->map->layout[_cop->i][_cop->j] != '0' &&
				_data->map->layout[_cop->i][_cop->j] != 'N'
				&& _data->map->layout[_cop->i][_cop->j] != 'S' &&
				_data->map->layout[_cop->i][_cop->j] != 'W'
				&& _data->map->layout[_cop->i][_cop->j] != 'E' &&
				_data->map->layout[_cop->i][_cop->j] != ' ')
				panpan(_data, "Error\nBad syntax map\n");
			_cop->j++;
		}
		_cop->i++;
	}
	_cop->i = 0;
}

void	aaaaaa(t_data *_data, t_copy _cop)
{
	if (_cop.flag != 1)
		panpan(_data, "Error\nOne player expected\n");
}

void	parse_map(t_data *_data)
{
	t_copy	cop;

	parse_map2(_data, &cop);
	while (cop.i < _data->map->dimensions.y)
	{
		cop.j = 0;
		while (_data->map->layout[cop.i][cop.j] != '\n'
		&& _data->map->layout[cop.i][cop.j] != '\0')
		{
			if (_data->map->layout[cop.i][cop.j] == 'N'
			|| _data->map->layout[cop.i][cop.j] == 'S' ||
				_data->map->layout[cop.i][cop.j] == 'W'
				|| _data->map->layout[cop.i][cop.j] == 'E')
			{
				_data->map->player_spawn.x = cop.j;
				_data->map->player_spawn.y = cop.i;
				_data->map->player_spawn_rotation = convert_char_to_direction(
						_data->map->layout[cop.i][cop.j]);
				cop.flag++;
			}
			cop.j++;
		}
		cop.i++;
	}
	aaaaaa(_data, cop);
}

void	new_map2(t_data *_data, t_new_map *_np)
{
	_np->max_len = calculate_max_len(_data) + 3;
	_np->str = malloc((_np->max_len) * sizeof(char));
	_np->tmp_y = _data->map->dimensions.y + 2;
	_np->tmp_x = _np->max_len;
	_data->map->dimensions.x = _np->max_len - 2;
	_np->i = 0;
	_np->tmp = ft_calloc(_np->tmp_y, sizeof(char *));
	while (_np->i != _np->max_len - 1)
	{
		_np->str[_np->i] = ' ';
		_np->i = _np->i + 1;
	}
	_np->str[_np->i] = '\0';
	_np->i = 0;
}

void	new_map(t_data *_data)
{
	t_new_map	np;

	new_map2(_data, &np);
	while (np.i < np.tmp_y - 2)
	{
		if (np.i == 0)
		{
			np.tmp[np.i] = ft_strdup(np.str);
			np.tmp[np.i + 1] = copy_line(_data->map->layout[np.i], np.tmp_x);
		}
		else
		{
			np.tmp[np.i + 1] = copy_line(_data->map->layout[np.i], np.tmp_x);
		}
		np.i++;
	}
	np.tmp[np.i + 1] = ft_strdup(np.str);
	_data->map->sqr_layout = np.tmp;
	np.i = 0;
	free(np.str);
}
