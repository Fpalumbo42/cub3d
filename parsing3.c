/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:06:09 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/04/24 16:43:00 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_virg(t_data *_data, char *str)
{
	int	i;
	int	virg;

	i = 0;
	virg = 0;
	while (str[i])
	{
		if (str[i] == ',')
			virg++;
		if (str[i] == ',' && str[i + 1] == ',')
			panpan(_data, "Error\nBad syntax colors\n");
		i++;
	}
	if (virg != 2)
		panpan(_data, "Error\nBad syntax colors\n");
}

void	check_is_digit(t_data *_data, char **tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != 3)
	{
		j = 0;
		while (tmp[i][j] != '\0' && tmp[i][j] != ' ' && tmp[i][j] != '\n')
		{
			if (!ft_isdigit(tmp[i][j]))
			{
				free_string_array(tmp, 3);
				panpan(_data, "Error\nBad syntax colors\n");
			}
			j++;
		}
		i++;
	}
}

char	**check_color_valid(t_data *_data, char *str)
{
	char	**tmp;

	check_virg(_data, str);
	tmp = ft_split(str, ',');
	if (tmp[3] || !tmp[0] || !tmp[1] || !tmp[2]
		|| !(tmp[2][0] >= '0' && tmp[2][0] <= '9'))
	{
		free_string_array(tmp, 3);
		panpan(_data, "Error\nBad syntax colors\n");
	}
	check_is_digit(_data, tmp);
	if ((ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[1]) > 255
			|| ft_atoi(tmp[2]) > 255)
		|| (ft_atoi(tmp[0]) < 0 || ft_atoi(tmp[1]) < 0 || ft_atoi(tmp[2]) < 0))
	{
		free_string_array(tmp, 3);
		panpan(_data, "Error\nBad syntax colors\n");
	}
	return (tmp);
}

void	count_arg(t_data *_data)
{
	int	i;
	int	j;
	int	ecrit;

	j = 0;
	ecrit = 0;
	while (j != _data->pars->file_taille && ecrit < 7)
	{
		i = 0;
		while (_data->pars->file[j][i])
		{
			if (_data->pars->file[j][i] != ' '
				&& _data->pars->file[j][i] != '\n')
			{
				ecrit++;
				break ;
			}
			i++;
		}
		j++;
	}
	if (ecrit < 7)
		panpan(_data, "Error\nMissing data or bad syntax\n");
	_data->pars->arg_taille = j;
}

void	check_valid2(t_data *_data, int i, int j)
{
	if (_data->pars->file[i][j] &&
		((_data->pars->file[i][j] != 'N'
		&& _data->pars->file[i][j + 1] != 'O') &&
		(_data->pars->file[i][j] != 'S'
		&& _data->pars->file[i][j + 1] != 'O') &&
		(_data->pars->file[i][j] != 'W'
		&& _data->pars->file[i][j + 1] != 'E') &&
		(_data->pars->file[i][j] != 'E'
		&& _data->pars->file[i][j + 1] != 'A') &&
		(_data->pars->file[i][j] != 'F'
		&& (_data->pars->file[i][j] != ' ') &&
		(_data->pars->file[i][j] != 'C'
		&& _data->pars->file[i][j] != ' ') &&
			_data->pars->file[i][j] != '\n')))
		panpan(_data, "Error\nBad syntax\n");
}
