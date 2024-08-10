/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:14:58 by fpalumbo          #+#    #+#             */
/*   Updated: 2024/01/28 05:35:27 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrnbr_fd(char *str, int nbr)
{
	ft_putstr_fd(str, 1);
	ft_putnbr_fd(nbr, 1);
	ft_putchar_fd('\n', 1);
}
