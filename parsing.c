/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:50:36 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/05/07 14:17:34 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	recup_texture3(t_data *_data, int i, char **_color, char c)
{
	if (*_color != NULL)
		panpan(_data, "Error\ntwo colors\n");
	*_color
		= copy_colors(_data, _data->pars->file[i], c);
}

void	recup_texture2(t_data *_data, int i, int j)
{
	if (_data->pars->file[i][j] == 'N'
		&& _data->pars->file[i][j + 1] == 'O')
		_data->map->nord_texture
			= copy_texture(_data, _data->pars->file[i], "NO");
	else if (_data->pars->file[i][j] == 'S'
		&& _data->pars->file[i][j + 1] == 'O')
		_data->map->south_texture
			= copy_texture(_data, _data->pars->file[i], "SO");
	else if (_data->pars->file[i][j] == 'W'
		&& _data->pars->file[i][j + 1] == 'E')
		_data->map->west_texture
			= copy_texture(_data, _data->pars->file[i], "WE");
	else if (_data->pars->file[i][j] == 'E'
		&& _data->pars->file[i][j + 1] == 'A')
		_data->map->east_texture
			= copy_texture(_data, _data->pars->file[i], "EA");
	else if (_data->pars->file[i][j] == 'F'
		&& _data->pars->file[i][j + 1] == ' ')
		recup_texture3(_data, i, &_data->map->ground_color, 'F');
	else if (_data->pars->file[i][j] == 'C'
		&& _data->pars->file[i][j + 1] == ' ')
		recup_texture3(_data, i, &_data->map->ceilling_color, 'C');
}

void	recup_texture(t_data *_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != _data->pars->arg_taille)
	{
		j = 0;
		while (_data->pars->file[i][j])
		{
			recup_texture2(_data, i, j);
			j++;
		}
		i++;
	}
	if (_data->map->nord_texture == NULL
		|| _data->map->south_texture == NULL
		|| _data->map->east_texture == NULL
		|| _data->map->west_texture == NULL
		|| _data->map->ceilling_color == NULL
		|| _data->map->ground_color == NULL)
		panpan(_data, "Error\nMissing data or bad syntax\n");
}

int	calculate_file(char **_argv, t_data *_data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(_argv[1], O_RDONLY);
	if (fd == -1)
		panpan(_data, "Error\nInvalid file\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	file_manager(char **_argv, t_data *_data)
{
	recup_file(_argv, _data);
	count_arg(_data);
	check_valid(_data);
	check_doubl(_data);
	recup_texture(_data);
	_data->map->ground_color_tab
		= check_color_valid(_data, _data->map->ground_color);
	_data->map->ceilling_color_tab
		= check_color_valid(_data, _data->map->ceilling_color);
	recup_map(_data);
	new_map(_data);
	parse_map(_data);
	map_is_close(_data);
}
