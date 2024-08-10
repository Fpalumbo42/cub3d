/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:54 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/01/28 05:36:13 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*jsp;

	jsp = malloc(sizeof * jsp);
	if (jsp == NULL)
		return (NULL);
	jsp->content = content;
	jsp->next = NULL;
	return (jsp);
}
