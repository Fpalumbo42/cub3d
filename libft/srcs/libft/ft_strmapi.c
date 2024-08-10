/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:29:37 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/01/28 05:34:49 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	newstr = malloc((len + 1) * sizeof (char));
	if (newstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[j] = f(i, s[i]);
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
