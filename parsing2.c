/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:17:31 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/04/04 18:53:05 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	copy_texture2(t_data *_data, char *_str, char *_nswd, t_copy *_cop)
{
	_cop->i = 0;
	_cop->j = 0;
	_cop->flag = 0;
	_cop->len = ft_strlen(_str);
	while (_str[_cop->i] != _nswd[0] && _str[_cop->i + 1] != _nswd[1])
	{
		if (_str[_cop->i] == ' ' )
			_cop->i = _cop->i + 1;
		else
			panpan(_data, "Error\nBad syntax textures\n");
	}
	_cop->i += 2;
	if (_str[_cop->i] != ' ')
		panpan(_data, "Error\nBad syntax textures\n");
	while (_str[_cop->i] == ' ')
		_cop->i = _cop->i + 1;
}

char	*copy_texture(t_data *_data, char *_str, char *_nswd)
{
	t_copy	cop;

	copy_texture2(_data, _str, _nswd, &cop);
	cop.k = cop.i;
	while (_str[cop.k] != '\n')
	{
		if (_str[cop.k] == ' ')
			cop.flag = cop.flag + 1;
		if (cop.flag != 0 && _str[cop.k] != ' ')
			panpan(_data, "Error\nBad syntax textures\n");
		cop.k = cop.k + 1;
	}
	cop.dest = ft_calloc(cop.len - cop.i + 1, sizeof(char));
	while (_str[cop.i] != '\0' && _str[cop.i] != '\n' && _str[cop.i] != ' ')
	{
		cop.dest[cop.j] = _str[cop.i];
		cop.i = cop.i + 1;
		cop.j = cop.j + 1;
	}
	return (cop.dest);
}

void	copy_colors2(t_data *_data, char *_str, char _color, t_copy *_cop)
{
	_cop->i = 0;
	_cop->j = 0;
	_cop->flag = 0;
	_cop->len = ft_strlen(_str);
	while (_str[_cop->i] != _color)
	{
		if (_str[_cop->i] == ' ')
			_cop->i = _cop->i + 1;
		else
			panpan(_data, "Error\nBad syntax colors\n");
	}
	_cop->i = _cop->i + 1;
	while (!(_str[_cop->i] >= 48 && _str[_cop->i] <= 57))
	{
		if (_str[_cop->i] == ' ')
			_cop->i = _cop->i + 1;
		else
			panpan(_data, "Error\nBad syntax colors\n");
	}
}

char	*copy_colors(t_data *_data, char *_str, char _color)
{
	t_copy	cop;

	copy_colors2(_data, _str, _color, &cop);
	cop.k = cop.i;
	while (_str[cop.k] != '\n')
	{
		if (_str[cop.k] == ' ')
			cop.flag = cop.flag + 1;
		if (cop.flag != 0 && _str[cop.k] != ' ')
			panpan(_data, "Error\nBad syntax colors\n");
		cop.k = cop.k + 1;
	}
	cop.dest = ft_calloc(cop.len - cop.i + 1, sizeof(char));
	while (_str[cop.i] != '\0' && _str[cop.i] != '\n')
	{
		cop.dest[cop.j] = _str[cop.i];
		cop.i = cop.i + 1;
		cop.j = cop.j + 1;
	}
	return (cop.dest);
}

void	check_doubl2(t_data *_data, int *k, int i, int j)
{
	if ((_data->pars->file[i][j] == 'N'
		&& _data->pars->file[i][j + 1] == 'O')
		|| (_data->pars->file[i][j] == 'S'
		&& _data->pars->file[i][j + 1] == 'O')
		|| (_data->pars->file[i][j] == 'W'
		&& _data->pars->file[i][j + 1] == 'E')
		|| (_data->pars->file[i][j] == 'E'
		&& _data->pars->file[i][j + 1] == 'A')
		|| (_data->pars->file[i][j] == 'F'
		&& _data->pars->file[i][j + 1] == ' ' )
		|| (_data->pars->file[i][j] == 'C'
		&& _data->pars->file[i][j + 1] == ' ' ))
		*k = *k + 1;
}
