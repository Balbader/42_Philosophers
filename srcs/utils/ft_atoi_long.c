/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:52:50 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 16:52:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

long	ft_atoi_long(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str++ - '0';
		if (sign < 0 && (-nb) < INT_MIN)
			return (LONG_MIN);
		if (sign > 0 && nb > INT_MAX)
			return (LONG_MAX);
	}
	return (nb * sign);
}
