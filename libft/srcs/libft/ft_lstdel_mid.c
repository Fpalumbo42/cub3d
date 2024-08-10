/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_mid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:04:50 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/01/30 00:05:03 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_mid(t_list **lst, t_list *node)
{
	t_list	*prev;
	t_list	*next;

	prev = node->prev;
	next = node->next;
	if (prev)
		prev->next = next;
	else
		*lst = next;
	if (next)
		next->prev = prev;
	ft_lstdelone(node, free);
}
