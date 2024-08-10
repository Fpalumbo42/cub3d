/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:57:20 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/02/26 16:06:38 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *src)
{
	int		lenght;
	int		i;
	char	*dest;

	i = 0;
	lenght = ft_strlen(src);
	dest = malloc((lenght + 1) * sizeof(const char));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (i < lenght)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
