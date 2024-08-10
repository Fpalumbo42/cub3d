/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:32:26 by jfazi             #+#    #+#             */
/*   Updated: 2024/04/22 16:59:55 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int _argc, char **_argv)
{
	t_data	*data;

	if (_argc != 2)
		panpan(NULL, ERROR_ARGC_MSG);
	if (ft_strncmp(_argv[1] + ft_strlen(_argv[1]) - 4, ".cub", 4) != 0)
		panpan(NULL, ERROR_EXT_MSG);
	data = malloc(sizeof(t_data));
	if (!data)
		panpan(NULL, ERROR_INIT_MSG);
	init_data(data, _argv);
	mlx_hook(data->mlx_win, 17, 1L << 21, panpan2, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, register_inputs, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, release_inputs, data);
	mlx_loop_hook(data->mlx, move, data);
	mlx_loop(data->mlx);
}
