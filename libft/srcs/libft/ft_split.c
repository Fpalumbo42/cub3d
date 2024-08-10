/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfazi <jfazi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:45:49 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/03/13 21:25:18 by jfazi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_countwords(char const *s, char c)
{
	size_t	lsize;
	size_t	i;

	i = 0;
	lsize = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || \
	(s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			lsize++;
		i++;
	}
	return (lsize);
}

static char	*ft_dupdup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)

{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	split = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	index = -1;
	while (i <= (size_t)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_dupdup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
