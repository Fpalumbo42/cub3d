/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:23:56 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/01/28 05:34:25 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dest;

	i = 0;
	j = 0;
	k = 0;
	while (s[k] != '\0')
		k++;
	while (i < len && start < k && s[start + i])
		i++;
	j = 0;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (j < i && start < k)
	{
		dest[j] = s[start + j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
