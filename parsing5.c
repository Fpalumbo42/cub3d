/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:49:05 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 13:50:36 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_doubl(t_data *_data)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = 0;
	while (i != _data->pars->file_taille)
	{
		j = 0;
		while (_data->pars->file[i][j])
		{
			check_doubl2(_data, &k, i, j);
			j++;
		}
		i++;
	}
	if (k > 6)
		panpan(_data, "Error\nDouble argumets is detected\n");
}

void	check_valid(t_data *_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < _data->pars->arg_taille - 1)
	{
		j = 0;
		while (_data->pars->file[i][j] == ' ')
			j++;
		check_valid2(_data, i, j);
		i++;
	}
}

void	check_player_valid(t_data *_data, int i, int j)
{
	if (_data->map->sqr_layout[i][j + 1] == ' '
		|| _data->map->sqr_layout[i][j - 1] == ' '
		|| _data->map->sqr_layout[i + 1][j] == ' '
		|| _data->map->sqr_layout[i - 1][j] == ' ')
		panpan(_data, "Error\nPlayer spawn is not valid\n");
}

void	map_is_close2(t_data *_data, int i, int j)
{
	if (_data->map->sqr_layout[i][j] == '0'
	&& _data->map->sqr_layout[i][j + 1] == ' ')
		panpan(_data, "Error\nMap is not close\n");
	if (_data->map->sqr_layout[i][j] == '0'
	&& _data->map->sqr_layout[i][j - 1] == ' ')
		panpan(_data, "Error\nMap is not close\n");
	if (_data->map->sqr_layout[i][j] == '0'
	&& _data->map->sqr_layout[i + 1][j] == ' ')
		panpan(_data, "Error\nMap is not close\n");
	if (_data->map->sqr_layout[i][j] == '0'
	&& _data->map->sqr_layout[i - 1][j] == ' ')
		panpan(_data, "Error\nMap is not close\n");
}

void	map_is_close(t_data *_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < _data->map->dimensions.y + 2)
	{
		j = 0;
		while (_data->map->sqr_layout[i][j] != '\n'
		&& _data->map->sqr_layout[i][j] != '\0')
		{
			if (_data->map->sqr_layout[i][j] == 'N'
				|| _data->map->sqr_layout[i][j] == 'S'
				|| _data->map->sqr_layout[i][j] == 'W'
				|| _data->map->sqr_layout[i][j] == 'E')
				check_player_valid(_data, i, j);
			map_is_close2(_data, i, j);
			j++;
		}
		i++;
	}
}
