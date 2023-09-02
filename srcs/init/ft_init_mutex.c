/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:00:02 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:00:04 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (write(2, "Error:\nIssue creating mutex.\n", 29));
		i++;
	}
	if (pthread_mutex_init(&(rules->printing), NULL))
		return (write(2, "Error:\nIssue creating mutex.\n", 29));
	if (pthread_mutex_init(&(rules->health_check), NULL))
		return (write(2, "Error:\nIssue creating mutex.\n", 29));
	return (0);
}
