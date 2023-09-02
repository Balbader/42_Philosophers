/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:13:50 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:13:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	ft_usleep(unsigned long ms)
{
	unsigned long	time;

	time = ft_get_time();
	while (ft_time_diff(ft_get_time(), time) < ms)
		usleep(50);
}
