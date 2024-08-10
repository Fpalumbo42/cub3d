/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:51:05 by jfazi             #+#    #+#             */
/*   Updated: 2024/05/07 14:39:46 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	calculate_max_len(t_data *_data)
{
	int	i;
	int	max_len;
	int	len;
	int	j;

	max_len = 0;
	i = 0;
	while (i < _data->map->dimensions.y)
	{
		j = 0;
		len = 0;
		while (_data->map->layout[i][j] != '\n'
			&& _data->map->layout[i][j] != '\0')
		{
			len++;
			j++;
		}
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	recup_map(t_data *_data)
{
	int	start;
	int	j;

	j = 0;
	start = _data->pars->arg_taille - 1;
	_data->map->dimensions.y = _data->pars->file_taille - start;
	_data->map->layout = ft_calloc(_data->map->dimensions.y, sizeof(char *));
	while (start != _data->pars->file_taille)
	{
		_data->map->layout[j] = ft_strdup(_data->pars->file[start]);
		start++;
		j++;
	}
}

char	*copy_line(char *str, int len)
{
	char	*tmp_line;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tmp_line = malloc((len + 3) * sizeof(char));
	tmp_line[0] = ' ';
	while (i <= len)
	{
		tmp_line[i] = str[j];
		if (str[j] == '\0' || str[j] == '\n')
			tmp_line[i] = ' ';
		i++;
		if (str[j] != '\0' && str[j] != '\n')
			j++;
	}
	tmp_line[i] = '\0';
	return (tmp_line);
}

void	recup_file(char **_argv, t_data *_data)
{
	int	i;
	int	fd;

	fd = open(_argv[1], O_RDONLY);
	if (fd == -1)
		panpan(_data, "Error\nInvalid file\n");
	_data->pars->file_taille = calculate_file(_argv, _data);
	_data->pars->file = malloc(sizeof(char *) * _data->pars->file_taille);
	if (_data->pars->file == NULL)
		panpan(_data, "Error\nMemory allocation failed\n");
	i = 0;
	while (i < _data->pars->file_taille)
	{
		_data->pars->file[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}
