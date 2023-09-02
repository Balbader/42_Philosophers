/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:37:42 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:37:43 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_start_dinner(t_rules *rules)
{
	int				i;

	i = 0;
	rules->start = ft_get_time();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(rules->philos[i].thread), NULL,
				ft_threader, &(rules->philos[i])))
			return (write(2, "Error:\nIssue creating threads.\n", 31));
		pthread_mutex_lock(&(rules->health_check));
		rules->philos[i].last_meal = ft_get_time();
		pthread_mutex_unlock(&(rules->health_check));
		i++;
	}
	ft_end(rules, 0, 0);
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(rules->philos[i].thread, NULL);
		i++;
	}
	ft_destroy_mutexes(rules);
	return (0);
}
