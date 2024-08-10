/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:12:21 by jfazi             #+#    #+#             */
/*   Updated: 2024/03/06 18:12:18 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	vector2_distance(t_vector2 a, t_vector2 b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

t_vector2int	vector2_to_vector2int(t_vector2 _vector2)
{
	t_vector2int	vector2int;

	vector2int.x = (int) _vector2.x;
	vector2int.y = (int) _vector2.y;
	return (vector2int);
}

void	vector2_set(t_vector2 *_vector2, double x, double y)
{
	_vector2->x = x;
	_vector2->y = y;
}

void	vector2int_set(t_vector2int *_vector2, int x, int y)
{
	_vector2->x = x;
	_vector2->y = y;
}
