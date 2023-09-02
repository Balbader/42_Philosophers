/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:09:34 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:09:36 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

unsigned long	ft_time_diff(unsigned long a, unsigned long b)
{
	return (a - b);
}

void	isleep(unsigned long ms)
{
	unsigned long	t;

	t = get_time();
	while (time_diff(get_time(), t) < ms)
		usleep(50);
}
