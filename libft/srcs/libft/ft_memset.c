/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 08:44:14 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/01/28 05:35:52 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*dst_cpy;
	int				i;

	i = 0;
	dst_cpy = (unsigned char *)s;
	while (len-- != 0)
	{
		dst_cpy[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
