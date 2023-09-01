/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:46:37 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 15:55:28 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	mutex_init_alt(t_args *data)
{
	data->i = -1;
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		while (++data->i < data->nb_philo)
			pthread_mutex_destroy(&data->forks_mutex[data->i]);
		return (ft_putstr_fd("\n mutex init failed\n", 2), ERROR);
	}
	if (pthread_mutex_init(data->death_mutex, NULL) != 0)
	{
		while (++data->i < data->nb_philo)
			pthread_mutex_destroy(&data->forks_mutex[data->i]);
		pthread_mutex_destroy(&data->print_mutex);
		return (ft_putstr_fd("\n mutex init failed\n", 2), ERROR);
	}
	if (pthread_mutex_init(&data->time_mutex, NULL) != 0)
	{
		while (++data->i < data->nb_philo)
			pthread_mutex_destroy(&data->forks_mutex[data->i]);
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(data->death_mutex);
		return (ft_putstr_fd("\n mutex init failed\n", 2), ERROR);
	}
	return (E_OK);
}

int	mutex_init(t_philo **philo, t_args *data)
{
	(void)philo;
	data->i = -1;
	while (++data->i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks_mutex[data->i], NULL) != 0)
		{
			while (--data->i <= 0)
				pthread_mutex_destroy(&data->forks_mutex[data->i]);
			return (ft_putstr_fd("\n mutex init failed\n", 2), ERROR);
		}
	}
	if (mutex_init_alt(data) == ERROR)
		return (ERROR);
	return (E_OK);
}
