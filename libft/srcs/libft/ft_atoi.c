/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:01:35 by fpalumbo          #+#    #+#             */
/*   Updated: 2023/03/30 19:01:35 by fpalumbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	check_over_max(int sign, long result, const char *str)
{
	if ((sign * result) == 922337203685477580 && \
			(*str > '7' || ft_isdigit(*(str + 1))))
		return (1);
	if ((sign * result) > 922337203685477580 && ft_isdigit(*str))
		return (1);
	return (0);
}

int	check_under_min(int sign, long result, const char *str)
{
	if ((sign * result) == -922337203685477580 && \
			(*str > '8' || ft_isdigit(*(str + 1))))
		return (1);
	if ((sign * result) < -922337203685477580 && ft_isdigit(*str))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (check_over_max(sign, result, str))
			return (-1);
		if (check_under_min(sign, result, str))
			return (0);
	}
	return ((int)(sign * result));
}
