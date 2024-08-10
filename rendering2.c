/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:47:11 by jfazi             #+#    #+#             */
/*   Updated: 2024/04/04 19:08:09 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_pixel(t_image *_img, int x, int y, int _color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = _img->addr + (y * _img->llngth + x * (_img->bpp / 8));
	*(unsigned int *)dst = _color;
}

int	get_pixel(t_image *_image, int x, int y)
{
	return (*(int *)(_image->addr
		+ (y * _image->llngth + x * (_image->bpp / 8))));
}

void	clear_image(t_data *_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			draw_pixel(_data->rendering, i, j, 0);
			j++;
		}
		i++;
	}
}

void	draw_rectangle2(t_data *_data, t_vector2int _position,
	t_vector2int _dimensions, int _color)
{
	int	i;
	int	j;

	i = _position.x;
	while (i < _position.x + _dimensions.x)
	{
		j = _position.y;
		while (j < _position.y + _dimensions.y)
		{
			draw_pixel(_data->rendering, i, j, _color);
			j++;
		}
		i++;
	}
	i = _position.x;
	while (i > _position.x - _dimensions.x)
	{
		j = _position.y;
		while (j > _position.y - _dimensions.y)
		{
			draw_pixel(_data->rendering, i, j, _color);
			j--;
		}
		i--;
	}
}
