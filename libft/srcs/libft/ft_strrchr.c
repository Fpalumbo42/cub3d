/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:35:36 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/01/28 05:34:36 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	const char		*last;

	chr = (unsigned char)c;
	last = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == chr)
			last = s;
		s++;
	}
	if ((unsigned char)*s == chr)
		return ((char *)s);
	return ((char *)last);
}
