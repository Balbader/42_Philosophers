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

int	ft_start_dinner(t_config *conf)
{
	int				i;

	i = 0;
	conf->start = ft_get_time();
	while (i < conf->nb_philo)
	{
		if (pthread_create(&(conf->philos[i].thread), NULL,
				ft_threader, &(conf->philos[i])))
			ft_putstr_fd(THREAD_ERR, 2);
		pthread_mutex_lock(&(conf->health_check));
		conf->philos[i].last_meal = ft_get_time();
		pthread_mutex_unlock(&(conf->health_check));
		i++;
	}
	ft_til_the_end(conf, 0, 0);
	i = 0;
	while (i < conf->nb_philo)
	{
		pthread_join(conf->philos[i].thread, NULL);
		i++;
	}
	ft_destroy_mutexes(conf);
	return (0);
}
