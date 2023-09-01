/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:56:09 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 16:00:27 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_all(t_args *data, t_philo **philo)
{
	if (data->death)
		free (data->death);
	if (data->meals)
		free (data->meals);
	if (data->threads)
		free (data->threads);
	if (data->forks_mutex)
		free (data->forks_mutex);
	if (data->death_mutex)
		free (data->death_mutex);
	if (*philo)
		free (*philo);
	data->i = -1;
	while (++data->i < data->nb_philo)
		pthread_mutex_destroy(&data->forks_mutex[data->i]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(data->death_mutex);
	pthread_mutex_destroy(&data->time_mutex);
}
