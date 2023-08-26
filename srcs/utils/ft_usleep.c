/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:26:34 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 17:26:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(time_t usec)
{
	time_t		start_time;
	time_t		elapsed_time;
	time_t		milliseconds;

	start_time = get_time();
	elapsed_time = get_time() - start_time;
	milliseconds = usec / 1000;
	while (elapsed_time < milliseconds)
	{
		usleep((milliseconds - elapsed_time) / 2);
		elapsed_time = get_time() - start_time;
	}
}
